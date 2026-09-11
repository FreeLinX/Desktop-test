# FreeLinX/ports - xfce/exo-4.20.0 : Xfce extensions library (used by Thunar).
NAME:=exo-4.20.0
CATEGORY:=xfce
TARGET:=$(FREELINX_TRIPLE)
LICENSE:=LGPL-2.0-or-later

FLX_PREFIX=$(FREELINX_BUILD_DIR)/deps/$(NAME)
SRC_TREE=$(FREELINX_BUILD_DIR)/work/$(NAME)/$(DISTINFO_NAME)
PROJECT_BIN=$(FLX_PREFIX)/lib/libexo-2.a
BUILD_BIN=$(PROJECT_BIN)

include ../../mk/project-port.mk

export PATH := $(FREELINX_BUILD_DIR)/deps/glib-2.82.5/bin:$(PATH)
export PKG_CONFIG:=/usr/bin/pkg-config --static

PROJECT_CFG_CMDS = \
	./configure \
		--host=x86_64-linux-musl \
		--prefix="$(FLX_PREFIX)" \
		--disable-shared --enable-static \
		--disable-nls --disable-gtk-doc --disable-dependency-tracking \
		--disable-gio-unix
# exo-helper and the D-Bus-activated helpers are built but unused by a
# minimal file manager; the static lib + headers are what Thunar links.

BUILD_CMDS = make && make install