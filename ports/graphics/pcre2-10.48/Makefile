# FreeLinX/ports - graphics/pcre2-10.48 : PCRE2 8-bit library (static).
#
# glib uses pcre2-8 for its regex layer.  autotools configure; --host forces
# cross so no configure run-execution happens.
NAME    := pcre2-10.48
VERSION := 10.48
CATEGORY:= graphics
LICENSE := BSD-3-Clause
DEPENDENCIES:=
BUILD_DEPENDENCIES:=
TARGET  := $(FREELINX_TRIPLE)
PREFIX  := /

FLX_PREFIX = $(FREELINX_BUILD_DIR)/deps/$(NAME)
SRC_TREE = $(FREELINX_BUILD_DIR)/work/$(NAME)/$(NAME)
PROJECT_BIN = $(FLX_PREFIX)/lib/libpcre2-8.a
BUILD_BIN   = $(PROJECT_BIN)

include ../../mk/project-port.mk

PROJECT_CFG_CMDS = \
	cd "$(SRC_TREE)" && \
	./configure \
		--host="$(FREELINX_TRIPLE)" --build="$(shell uname -m)-pc-linux-gnu" \
		--prefix="$(FLX_PREFIX)" \
		--disable-shared --enable-static \
		--enable-pcre2-8 --disable-pcre2-16 --disable-pcre2-32 \
		--disable-jit --disable-tests --disable-pcre2grep-libz \
		--disable-pcre2grep-libbz2 --disable-pcre2test-libreadline

BUILD_CMDS = \
	$(MAKE) -C "$(SRC_TREE)" && \
	$(MAKE) -C "$(SRC_TREE)" install

