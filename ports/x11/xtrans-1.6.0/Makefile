# FreeLinX/ports - x11/xtrans-1.6.0 : xtrans (X Window System).
NAME:=xtrans-1.6.0
CATEGORY:=x11
TARGET:=$(FREELINX_TRIPLE)
LICENSE:=MIT

FLX_PREFIX=$(FREELINX_BUILD_DIR)/deps/x11
SRC_TREE=$(FREELINX_BUILD_DIR)/work/$(NAME)/$(DISTINFO_NAME)
PROJECT_BIN=$(FLX_PREFIX)/include/X11/Xtrans/Xtrans.h
BUILD_BIN=$(PROJECT_BIN)

# Pure-C stack: drop the default C++/unwind link closure.
FLX_PROJECT_LIBS?=

include ../../mk/project-port.mk

export PKG_CONFIG:=/usr/bin/pkg-config --static

PROJECT_CFG_CMDS = \
	./configure \
		--host=x86_64-linux-musl \
		--prefix="$(FLX_PREFIX)" \
		--disable-shared --enable-static \
		--disable-dependency-tracking \
		

BUILD_CMDS = make && make install
