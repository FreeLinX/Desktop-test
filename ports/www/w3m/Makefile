# FreeLinX/ports - www/w3m : w3m text-based web browser (0.5.3).
#
# Text-mode web browser with SSL support.
# w3m license. Autotools build.
# Requires: libgc, netbsd-curses, openssl, zlib.
# Notes: needs native mktable for table generation during cross-compile.
#        needs multiple musl/compat patches.

NAME    := w3m
VERSION := 0.5.3
CATEGORY:= www
LICENSE := w3m
DEPENDENCIES:= libgc netbsd-curses openssl
BUILD_DEPENDENCIES:= musl (via FreeLinX toolchain sysroot), native libgc (for mktable)
TARGET  := $(FREELINX_TRIPLE)
PREFIX  := /

INSTALL_BIN:= w3m
INSTALL_RELPATH:= usr/bin

include ../../mk/project-port.mk

SRC_TREE = $(FREELINX_BUILD_DIR)/work/$(NAME)/w3m-$(VERSION)
PROJECT_BIN = $(SRC_TREE)/w3m

OPENSSL_PREFIX = $(FREELINX_BUILD_DIR)/deps/openssl
NCURSES_PREFIX = $(FREELINX_BUILD_DIR)/deps/ncurses
LIBGC_PREFIX = $(FREELINX_PORTS_ROOT)/staging/usr
ZLIB_PREFIX = $(FREELINX_BUILD_DIR)/deps/zlib
NATIVE_GC = $(FREELINX_BUILD_DIR)/work/bdwgc-native/gc-for-w3m
NATIVE_GC_INC = $(FREELINX_BUILD_DIR)/work/bdwgc-native/include

W3M_CFLAGS = \
	--target=$(FREELINX_TRIPLE) --sysroot=$(FREELINX_TOOLCHAIN_DIR)/$(FREELINX_TRIPLE) \
	-O2 -I. -I.. -I./libwc \
	-I$(OPENSSL_PREFIX)/include \
	-I$(NCURSES_PREFIX)/include/ncursesw \
	-I$(NCURSES_PREFIX)/include \
	-I$(LIBGC_PREFIX)/include \
	-I$(ZLIB_PREFIX)/include \
	-Wno-format-security -Wno-deprecated-non-prototype \
	-Wno-int-conversion -Wno-pointer-sign \
	-Wno-implicit-function-declaration -Wno-implicit-int \
	-Wno-incompatible-pointer-types

W3M_LDFLAGS = \
	--target=x86_64-linux-musl --sysroot=$(FREELINX_TOOLCHAIN_DIR)/$(FREELINX_TRIPLE) \
	-L$(OPENSSL_PREFIX)/lib64 -L$(NCURSES_PREFIX)/lib -L$(LIBGC_PREFIX)/lib -L$(ZLIB_PREFIX)/lib \
	-fuse-ld=lld --rtlib=compiler-rt -static -Wl,--allow-multiple-definition

PROJECT_CFG_CMDS = \
	cd "$(SRC_TREE)" && \
	sed -i -E 's/\bfile_handle\b/w3m_file_handle/g' istream.h istream.c && \
	sed -i 's/orig_GC_warn_proc = GC_set_warn_proc(wrap_GC_warn_proc);/GC_set_warn_proc(wrap_GC_warn_proc);/' main.c && \
	sed -i 's/^prepare_sys_errlist()$$/void prepare_sys_errlist(void)/' etc.c && \
	sed -i 's@if (RAND_egd(file) > 0)@\#if OPENSSL_VERSION_NUMBER < 0x10100000L\n\tif (RAND_egd(file) > 0)\n\#else\n\tif (0)\n\#endif@' url.c && \
	mkdir -p "$(NATIVE_GC)"/.libs && \
	cp -f "$(FREELINX_BUILD_DIR)/work/bdwgc-native/.libs/libgc.a" "$(NATIVE_GC)/.libs/libgc.a" && \
	cd "$(SRC_TREE)" && \
	/usr/bin/cc -O2 -DHAVE_CONFIG_H -I. -I./libwc -I$(NATIVE_GC_INC) \
		-c -o Str_native.o Str.c && \
	/usr/bin/cc -O2 -DHAVE_CONFIG_H -I. -I./libwc -I$(NATIVE_GC_INC) \
		-c -o hash_native.o hash.c && \
	/usr/bin/cc -O2 -DHAVE_CONFIG_H -I. -I./libwc -I$(NATIVE_GC_INC) \
		-c -o myctype_native.o myctype.c && \
	/usr/bin/cc -O2 -DHAVE_CONFIG_H -I. -I./libwc -I$(NATIVE_GC_INC) \
		-o mktable_native mktable.c Str_native.o hash_native.o myctype_native.o \
		-L$(NATIVE_GC)/.libs -lgc -lm && \
	./configure \
		--host=x86_64-pc-linux-gnu \
		--prefix=/usr \
		--disable-image \
		--disable-xface \
		--with-ssl="$(OPENSSL_PREFIX)" \
		--with-gc="$(LIBGC_PREFIX)" \
		ac_cv_func_setpgrp_void=yes \
		CPPFLAGS="-I$(NCURSES_PREFIX)/include/ncursesw -I$(NCURSES_PREFIX)/include" \
		LIBS="-lncursesw" \
		CC="$(FREELINX_CC)" \
		CXX="$(FREELINX_CXX)" \
		CXXFLAGS="-stdlib=libc++ $(W3M_CFLAGS)" \
		CFLAGS="$(W3M_CFLAGS)" \
		LDFLAGS="$(W3M_LDFLAGS)" && \
	sed -i '1i \#define RC_DIR "~/.w3m"\n\#define CONF_DIR "/etc/w3m"\n\#define ETC_DIR "/etc"' config.h
BUILD_CMDS = \
	cd "$(SRC_TREE)" && \
	make -j"$(FREELINX_JOBS)" w3m
