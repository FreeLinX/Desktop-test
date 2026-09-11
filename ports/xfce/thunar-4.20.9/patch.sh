#!/bin/sh
# FreeLinX/ports - xfce/thunar-4.20.9 : source patches for a Wayland-only
# (no X11 dev files) static musl build.
#
# 1. Thunar REQUIRES X11 via XDT_CHECK_LIBX11_REQUIRE() in configure.ac, but
#    LibreLinX GTK is Wayland-only.  Demote it to the non-requiring
#    XDT_CHECK_LIBX11() so configure proceeds with no_x=yes; the X11 source
#    paths are guarded by GDK_WINDOWING_X11 / HAVE_LIBSM (both off) so they are
#    compiled out.
# 2. thunar-session-client.c includes <gdk/gdkx.h> unconditionally even though
#    the only use (gdk_x11_set_sm_client_id) is inside #ifdef HAVE_LIBSM.
#    Guard the include so it compiles without the (absent) Wayland-only gdkx.h.
set -e
TREE="$1"

xd_sed() {
    f="$1"; shift
    sed -i "$@" "$f"
}

xd_sed "$TREE/configure.ac" \
    's/XDT_CHECK_LIBX11_REQUIRE()/XDT_CHECK_LIBX11()/'

xd_sed "$TREE/thunar/thunar-session-client.c" \
    '/#include <gdk\/gdkx.h>/c\
#ifdef HAVE_LIBSM\
#include <gdk/gdkx.h>\
#endif'

# 3. Thunar's generated gdbus skeletons use g_variant_builder_init_static() when
#    GLIB_VERSION_MAX_ALLOWED >= GLIB_VERSION_2_84.  libglib is FreeLinX-built
#    at 2.82.5 which defines neither the macro (evaluates 0) nor the function.
#    Replace with the always-available initializer in every generated file.
find "$TREE" \( -name 'thunar-dbus-*.c' -o -name 'thunar-thumbnailer-proxy.c' -o -name 'thunar-thumbnail-cache-proxy.c' \) -exec sed -i \
    's/g_variant_builder_init_static/g_variant_builder_init/' {} +

echo "thunar patches applied to $TREE"
