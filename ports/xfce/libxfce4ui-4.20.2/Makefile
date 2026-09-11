# FreeLinX/ports - xfce/libxfce4ui-4.20.2 : Xfce widget/UI helpers (GTK3, static).
NAME:=libxfce4ui-4.20.2
CATEGORY:=xfce
TARGET:=$(FREELINX_TRIPLE)
LICENSE:=LGPL-2.0-or-later

FLX_PREFIX=$(FREELINX_BUILD_DIR)/deps/$(NAME)
SRC_TREE=$(FREELINX_BUILD_DIR)/work/$(NAME)/$(DISTINFO_NAME)
PROJECT_BIN=$(FLX_PREFIX)/lib/libxfce4ui-2.a
BUILD_BIN=$(PROJECT_BIN)

include ../../mk/project-port.mk

export PATH := $(FREELINX_BUILD_DIR)/deps/glib-2.82.5/bin:$(PATH)
# Force static pkg-config resolution so link lines carry full dep closure.
export PKG_CONFIG:=/usr/bin/pkg-config --static

FLX_PROJECT_CPPFLAGS?=

PROJECT_CFG_CMDS = \
	./configure \
		--host=x86_64-linux-musl \
		--prefix="$(FLX_PREFIX)" \
		--disable-shared --enable-static \
		--disable-nls --disable-gtk-doc --disable-dependency-tracking \
		--disable-x11 --enable-wayland --disable-libsm \
		--disable-startup-notification --disable-glibtop \
		--disable-epoxy --disable-gudev \
		--enable-introspection=no --enable-vala=no \
		--disable-gladeui2 --disable-tests

BUILD_CMDS = make && make install