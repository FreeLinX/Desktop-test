# FreeLinX/ports - graphics/libudev-zero : libudev-zero 1.0.5 (build dependency).
#
# Small static udev-compatible library (no daemon): reads device info straight
# from /sys, so it works without systemd/udevd on the FreeLinX initramfs.
# libinput requires a libudev for device discovery; libudev-zero provides it.
# Built with the FreeLinX toolchain via its bundled Makefile (static-only).

NAME   := libudev-zero
VERSION:= 1.0.5
CATEGORY:= graphics
LICENSE:= ISC
DEPENDENCIES:=
BUILD_DEPENDENCIES:= musl (via FreeLinX toolchain sysroot)
TARGET := $(FREELINX_TRIPLE)
PREFIX := /

UDEV_PREFIX = $(FREELINX_BUILD_DIR)/deps/libudev-zero

INSTALL_BIN:=
INSTALL_RELPATH:= lib/libudev.a

include ../../mk/project-port.mk

PORT_DIR := $(CURDIR)
SRC_TREE = $(FREELINX_BUILD_DIR)/work/$(NAME)/libudev-zero-$(VERSION)
PROJECT_BIN = $(UDEV_PREFIX)/lib/libudev.a

# The bundled Makefile sets PREFIX/LIBDIR/INCLUDEDIR from its own vars; build a
# static-only archive (install-static) into DESTDIR then relocate into our dep
# prefix.  Override CFLAGS/LDFLAGS via make vars so only the archive is made.
PROJECT_CFG_CMDS = \
	mkdir -p "$(UDEV_PREFIX)"

BUILD_CMDS = \
	cd "$(SRC_TREE)" && \
	$(MAKE) CC="$(CC)" AR="$(FREELINX_TOOLCHAIN_BIN)/llvm-ar" \
		CFLAGS="-O2 -D_GNU_SOURCE" libudev.a && \
	$(MAKE) install-static \
		PREFIX=/usr DESTDIR="$(UDEV_PREFIX)" && \
	mkdir -p "$(UDEV_PREFIX)/lib/pkgconfig" "$(UDEV_PREFIX)/include" && \
	mv "$(UDEV_PREFIX)/usr/lib/libudev.a" "$(UDEV_PREFIX)/lib/libudev.a" && \
	cp "$(UDEV_PREFIX)/usr/include/libudev.h" "$(UDEV_PREFIX)/include/libudev.h" && \
	mv "$(UDEV_PREFIX)/usr/lib/pkgconfig/libudev.pc" "$(UDEV_PREFIX)/lib/pkgconfig/libudev.pc" && \
	sed -i "s|^prefix=/usr|prefix=$(UDEV_PREFIX)|; s|^exec_prefix=/usr|exec_prefix=$(UDEV_PREFIX)|" \
		"$(UDEV_PREFIX)/lib/pkgconfig/libudev.pc" && \
	rm -rf "$(UDEV_PREFIX)/usr"