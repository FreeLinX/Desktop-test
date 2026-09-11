# FreeLinX/ports - xfce/thunar-4.20.9 : Xfce file manager (Wayland, static).
NAME:=thunar-4.20.9
CATEGORY:=xfce
TARGET:=$(FREELINX_TRIPLE)
LICENSE:=GPL-2.0-or-later

FLX_PREFIX=$(FREELINX_BUILD_DIR)/deps/$(NAME)
SRC_TREE=$(FREELINX_BUILD_DIR)/work/$(NAME)/$(DISTINFO_NAME)
PROJECT_BIN=$(FLX_PREFIX)/bin/thunar
BUILD_BIN=$(PROJECT_BIN)

include ../../mk/project-port.mk

export PATH := $(FREELINX_BUILD_DIR)/deps/glib-2.82.5/bin:$(PATH)
export PKG_CONFIG:=/usr/bin/pkg-config --static

PROJECT_CFG_CMDS = \
	sh "$(CURDIR)/patch.sh" "$(SRC_TREE)" && \
	./configure \
		--host=x86_64-linux-musl \
		--prefix="$(FLX_PREFIX)" \
		--disable-shared --enable-static \
		--disable-nls --disable-gtk-doc --disable-dependency-tracking \
		--disable-gio-unix --disable-gudev \
		--disable-exif --disable-pcre2 \
		--disable-notifications \
		--disable-apr-plugin --disable-sbr-plugin \
		--disable-tpa-plugin --disable-uca-plugin \
		--disable-wallpaper-plugin

BUILD_CMDS = make && make install