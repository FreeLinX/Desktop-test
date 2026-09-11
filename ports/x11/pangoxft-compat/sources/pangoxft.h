#ifndef __PANGOXFT_COMPAT_H__
#define __PANGOXFT_COMPAT_H__

#include <pango/pango.h>
#include <X11/Xlib.h>
#include <X11/Xft/Xft.h>

G_BEGIN_DECLS

typedef XftDraw PangoXftRenderer;

PangoContext *pango_xft_get_context(Display *display, int screen);
void pango_xft_render_layout(PangoXftRenderer *renderer, XftColor *color,
                             PangoLayout *layout, int x, int y);
void pango_xft_render_layout_line(PangoXftRenderer *renderer, XftColor *color,
                                  PangoLayoutLine *line, int x, int y);

G_END_DECLS

#endif