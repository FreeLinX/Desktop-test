# FreeLinX/ports - graphics/gettext-0.23 : gettext-runtime libintl (musl).
#
# glib needs libintl; musl has no GNU gettext.  We cross-build only the
# libintl runtime (static), not the gettext tools.  configure is autotools;
# --host forces cross so no target binaries get executed at configure time.
NAME    := gettext-0.23
VERSION := 0.23
CATEGORY:= graphics
LICENSE := GPL-3.0-or-later (libintl: LGPL-2.1-or-later)
DEPENDENCIES:=
BUILD_DEPENDENCIES:=
TARGET  := $(FREELINX_TRIPLE)
PREFIX  := /

FLX_PREFIX = $(FREELINX_BUILD_DIR)/deps/$(NAME)
SRC_TREE = $(FREELINX_BUILD_DIR)/work/$(NAME)/$(NAME)
PROJECT_BIN = $(FLX_PREFIX)/lib/libintl.a
BUILD_BIN   = $(PROJECT_BIN)

include ../../mk/project-port.mk

PROJECT_CFG_CMDS = \
	cd "$(SRC_TREE)" && \
	./configure \
		--host="$(FREELINX_TRIPLE)" --build="$(shell uname -m)-pc-linux-gnu" \
		--prefix="$(FLX_PREFIX)" \
		--disable-shared --enable-static \
		--disable-nls --disable-csharp --disable-java --disable-rpath \
		--disable-curses --without-libncurses-prefix \
		--without-emacs --with-included-gettext

BUILD_CMDS = \
	$(MAKE) -C "$(SRC_TREE)/gettext-runtime/intl" && \
	$(MAKE) -C "$(SRC_TREE)/gettext-runtime/intl" install && \
	mkdir -p "$(FLX_PREFIX)/lib/pkgconfig" && \
	{ printf 'prefix=%s\\nexec_prefix=$${prefix}\\nlibdir=$${exec_prefix}/lib\\nincludedir=$${prefix}/include\\n\\nName: GNU libintl\\nDescription: i18n library\\nVersion: $(VERSION)\\nLibs: -L$${libdir} -lintl\\nCflags: -I$${includedir}\\n' "$(FLX_PREFIX)" > "$(FLX_PREFIX)/lib/pkgconfig/libintl.pc"; }

