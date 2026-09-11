# FreeLinX/ports - x11/xf86-video-fbdev-git : fbdev video driver (Xorg module), git master.
# 0.5.0 release was dropped from API sync; git master builds against Server 21.1.
NAME:=xf86-video-fbdev-git
CATEGORY:=x11
TARGET:=$(FREELINX_TRIPLE)
LICENSE:=MIT-X11

FLX_PREFIX=$(FREELINX_BUILD_DIR)/deps/x11
SRC_TREE=$(FREELINX_BUILD_DIR)/work/$(NAME)/xf86-video-fbdev-master
PROJECT_BIN=$(FLX_PREFIX)/lib/xorg/modules/drivers/fbdev_drv.so
BUILD_BIN=$(PROJECT_BIN)

# Pure-C stack: drop the default C++/unwind link closure.
FLX_PROJECT_LIBS?=
# libtool strips --rtlib from LDFLAGS but passes CFLAGS through verbatim;
# without it the driver asks for GNU crtbeginS/libgcc.
FLX_PROJECT_CFLAGS?=-O2 -rtlib=compiler-rt

include ../../mk/project-port.mk

# The driver is a dlopen'd module (.so): it must NOT be -static linked.
export LDFLAGS:=$(FREELINX_TARGET_FLAGS) $(FREELINX_SYSROOT_FLAGS) --rtlib=compiler-rt -fuse-ld=lld

export PKG_CONFIG:=/usr/bin/pkg-config --static

PROJECT_CFG_CMDS = \
	ACLOCAL_PATH="$(FLX_PREFIX)/share/aclocal" \
		./autogen.sh \
			--host=x86_64-linux-musl \
			--prefix="$(FLX_PREFIX)" \
			--with-xorg-module-dir="$(FLX_PREFIX)/lib/xorg/modules" \
			--with-pic=yes


BUILD_CMDS = make && make install