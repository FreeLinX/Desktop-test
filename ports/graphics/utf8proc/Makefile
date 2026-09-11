# FreeLinX/ports - graphics/utf8proc : utf8proc 2.11.3 (Unicode UTF-8 library).
#
# Minimal Unicode table-based library (segmentation, case mapping) used by
# foot for proper UTF-8 handling.  Built with the project's plain Makefile
# (no meson in this release); only the static archive is installed plus a
# generated pkg-config file.
NAME    := utf8proc
VERSION := 2.11.3
CATEGORY:= graphics
LICENSE := MIT
DEPENDENCIES:=
BUILD_DEPENDENCIES:=
TARGET  := $(FREELINX_TRIPLE)
PREFIX  := /

include ../../mk/project-port.mk

U8_PREFIX = $(FREELINX_BUILD_DIR)/deps/$(NAME)
SRC_TREE = $(FREELINX_BUILD_DIR)/work/$(NAME)/utf8proc-$(VERSION)
PROJECT_BIN = $(U8_PREFIX)/lib/libutf8proc.a
BUILD_BIN   = $(PROJECT_BIN)

BUILD_CMDS = \
	cd "$(SRC_TREE)" && make libutf8proc.a CC="$(CC)" AR="$(AR)" && \
	mkdir -p "$(U8_PREFIX)/lib/pkgconfig" "$(U8_PREFIX)/include" && \
	cp libutf8proc.a "$(U8_PREFIX)/lib/" && \
	cp utf8proc.h "$(U8_PREFIX)/include/" && \
	sed -e 's|PREFIX|$(U8_PREFIX)|' \
	    -e 's|LIBDIR|lib|' \
	    -e 's|INCLUDEDIR|include|' \
	    -e 's|VERSION|$(VERSION)|' \
	    libutf8proc.pc.in > "$(U8_PREFIX)/lib/pkgconfig/utf8proc.pc"