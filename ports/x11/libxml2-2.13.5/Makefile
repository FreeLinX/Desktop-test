# FreeLinX/ports - x11/libxml2-2.13.5 : XML parsing library (openbox config/menu).
NAME:=libxml2-2.13.5
CATEGORY:=x11
TARGET:=$(FREELINX_TRIPLE)
LICENSE:=MIT

FLX_PREFIX=$(FREELINX_BUILD_DIR)/deps/x11
SRC_TREE=$(FREELINX_BUILD_DIR)/work/$(NAME)/$(DISTINFO_NAME)
PROJECT_BIN=$(FLX_PREFIX)/lib/libxml2.a
BUILD_BIN=$(PROJECT_BIN)

FLX_PROJECT_LIBS?=

include ../../mk/project-port.mk

export PKG_CONFIG:=/usr/bin/pkg-config --static

PROJECT_CFG_CMDS = \
	./configure \
		--host=x86_64-linux-musl \
		--prefix="$(FLX_PREFIX)" \
		--disable-shared --enable-static \
		--disable-dependency-tracking \
		--without-python --without-lzma --without-iconv \
		--without-legacy --without-readline --without-debug

BUILD_CMDS = make && make install
