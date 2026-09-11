# FreeLinX/ports - xfce/xfconf-4.20.0 : Xfce configuration daemon + library (gdbus).
NAME:=xfconf-4.20.0
CATEGORY:=xfce
TARGET:=$(FREELINX_TRIPLE)
LICENSE:=LGPL-2.0-or-later

FLX_PREFIX=$(FREELINX_BUILD_DIR)/deps/$(NAME)
SRC_TREE=$(FREELINX_BUILD_DIR)/work/$(NAME)/$(DISTINFO_NAME)
PROJECT_BIN=$(FLX_PREFIX)/lib/libxfconf-0.a
BUILD_BIN=$(PROJECT_BIN)

include ../../mk/project-port.mk

export PATH := $(FREELINX_BUILD_DIR)/deps/glib-2.82.5/bin:$(PATH)
# Force static pkg-config resolution so link lines carry full dep closure.
export PKG_CONFIG:=/usr/bin/pkg-config --static

PROJECT_CFG_CMDS = \
	./configure \
		--host=x86_64-linux-musl \
		--prefix="$(FLX_PREFIX)" \
		--disable-shared --enable-static \
		--disable-nls --disable-gtk-doc --disable-dependency-tracking \
		--enable-introspection=no --enable-vala=no \
		--disable-gsettings-backend --disable-checks
# xfconfd is the daemon started alongside the session bus in the guest;
# keep it (installed with the rest) but the delivered artifact is the lib.

BUILD_CMDS = make && make install