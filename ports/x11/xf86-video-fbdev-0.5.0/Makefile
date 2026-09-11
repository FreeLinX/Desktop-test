# FreeLinX/ports - x11/xf86-video-fbdev-0.5.0 : fbdev video driver (Xorg module).
NAME:=xf86-video-fbdev-0.5.0
CATEGORY:=x11
TARGET:=$(FREELINX_TRIPLE)
LICENSE:=MIT-X11

FLX_PREFIX=$(FREELINX_BUILD_DIR)/deps/x11
SRC_TREE=$(FREELINX_BUILD_DIR)/work/$(NAME)/$(DISTINFO_NAME)
PROJECT_BIN=$(FLX_PREFIX)/lib/xorg/modules/drivers/fbdev_drv.so
BUILD_BIN=$(PROJECT_BIN)

# Pure-C stack: drop the default C++/unwind link closure.
FLX_PROJECT_LIBS?=

include ../../mk/project-port.mk

# The driver is a dlopen'd module (.so): it must NOT be -static linked.
export LDFLAGS:=$(FREELINX_TARGET_FLAGS) $(FREELINX_SYSROOT_FLAGS) --rtlib=compiler-rt -fuse-ld=lld

export PKG_CONFIG:=/usr/bin/pkg-config --static

PROJECT_CFG_CMDS = \
	./configure \
		--host=x86_64-linux-musl \
		--prefix="$(FLX_PREFIX)" \
		--with-xorg-module-dir="$(FLX_PREFIX)/lib/xorg/modules" \
		--disable-dependency-tracking \


BUILD_CMDS = make && make install