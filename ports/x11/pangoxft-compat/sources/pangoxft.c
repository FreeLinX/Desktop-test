/* pangoxft.c - FreeLinX pangoxft compatibility shim.
 *
 * Modern Pango (>= 1.56) removed the Xft-based rendering module ("pangoxft").
 * Openbox 3.6.1 still uses its small API surface.  This shim reimplements it
 * over PangoCairo with the cairo Xlib backend, which draws to the same XftDraw
 * drawable while respecting the XftColor (and its premultiplied shadow alpha).
 */

#include "pangoxft.h"
#include <pango/pangocairo.h>

#include <cairo/cairo.h>
#include <cairo/cairo-xlib.h>

#include <X11/Xlib.h>
#include <X11/Xft/Xft.h>

#include <math.h>

#define FLX_PANGO_SCALE_DIV ((int) PANGO_SCALE)

static void
flx_pango_xft_render(XftDraw *draw, XftColor *color,
                     PangoLayout *layout, PangoLayoutLine *line,
                     int x, int y)
{
    Display *dpy;
    Drawable drawable;
    Visual *visual;
    Window root;
    int rx, ry, bd, depth;
    unsigned int width, height;
    cairo_surface_t *surface;
    cairo_t *cr;
    double r, g, b, a;

    dpy = XftDrawDisplay(draw);
    drawable = XftDrawDrawable(draw);
    visual = XftDrawVisual(draw);

    /* The text target must be fully sized so cairo's Xlib finish flushes a
     * complete clip around the glyphs. */
    if (XGetGeometry(dpy, drawable, &root, &rx, &ry,
                     &width, &height, &bd, &depth)
        == 0) {
        width = 1;
        height = 1;
    }

    surface = cairo_xlib_surface_create(dpy, drawable, visual,
                                        (int) width, (int) height);
    if (cairo_surface_status(surface) != CAIRO_STATUS_SUCCESS) {
        cairo_surface_destroy(surface);
        return;
    }

    cr = cairo_create(surface);

    /* XftColor carries 16-bit premultiplied components; cairo expects
     * unpremultiplied source RGBA, which it premultiplies internally when
     * drawing with OPERATOR_OVER. */
    a = color->color.alpha / 65535.0;
    r = a > 0.0 ? (color->color.red / 65535.0) / a : 0.0;
    g = a > 0.0 ? (color->color.green / 65535.0) / a : 0.0;
    b = a > 0.0 ? (color->color.blue / 65535.0) / a : 0.0;
    if (r > 1.0) r = 1.0;
    if (g > 1.0) g = 1.0;
    if (b > 1.0) b = 1.0;

    cairo_set_source_rgba(cr, r, g, b, a);

    cairo_move_to(cr, (double) x / (double) FLX_PANGO_SCALE_DIV,
                  (double) y / (double) FLX_PANGO_SCALE_DIV);

    if (line != NULL)
        pango_cairo_show_layout_line(cr, line);
    else
        pango_cairo_show_layout(cr, layout);

    cairo_destroy(cr);

    cairo_surface_flush(surface);
    cairo_surface_destroy(surface);
}

PangoContext *
pango_xft_get_context(Display *display, int screen)
{
    PangoFontMap *fontmap;

    (void) display;
    (void) screen;

    fontmap = pango_cairo_font_map_get_default();
    return pango_font_map_create_context(fontmap);
}

void
pango_xft_render_layout(PangoXftRenderer *renderer, XftColor *color,
                        PangoLayout *layout, int x, int y)
{
    flx_pango_xft_render((XftDraw *) renderer, color, layout, NULL, x, y);
}

void
pango_xft_render_layout_line(PangoXftRenderer *renderer, XftColor *color,
                             PangoLayoutLine *line, int x, int y)
{
    flx_pango_xft_render((XftDraw *) renderer, color, NULL, line, x, y);
}