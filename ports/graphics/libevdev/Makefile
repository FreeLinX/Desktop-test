# FreeLinX/ports - graphics/libevdev : libevdev 1.13.7 (build dependency).
#
# Kernel evdev access library used by libinput to read input devices from
# /dev/input/event*.  Cross-built static against the FreeLinX musl sysroot;
# installed only into build/deps/libevdev for libinput to consume.  Tools
# (libevdev-events etc.) are disabled for the dependency build.

NAME   := libevdev
VERSION:= 1.13.7
CATEGORY:= graphics
LICENSE:= MIT/X11
DEPENDENCIES:=
BUILD_DEPENDENCIES:= musl (via FreeLinX toolchain sysroot)
TARGET := $(FREELINX_TRIPLE)
PREFIX := /

LEV_PREFIX = $(FREELINX_BUILD_DIR)/deps/$(NAME)

INSTALL_BIN:=
INSTALL_RELPATH:= lib/libevdev.a

include ../../mk/project-port.mk

PORT_DIR := $(CURDIR)
HOST_TOOLS := /tmp/opencode/host-tools
MESON    := /tmp/opencode/meson-1.6.1/meson.py
SRC_TREE = $(FREELINX_BUILD_DIR)/work/$(NAME)/libevdev-libevdev-$(VERSION)-a158f468affb059669189454a52b0d78c563618b
BUILD_DIR = $(FREELINX_BUILD_DIR)/obj/$(NAME)/meson
PROJECT_BIN = $(LEV_PREFIX)/lib/libevdev.a

export PATH := $(HOST_TOOLS):$(PATH)

PROJECT_CFG_CMDS = \
	mkdir -p "$(BUILD_DIR)" && \
	python3 "$(MESON)" setup \
		--cross-file "$(PORT_DIR)/meson-cross.ini" \
		--buildtype=release \
		--default-library=static \
		--prefix="$(LEV_PREFIX)" \
		-Dtests=disabled -Ddocumentation=disabled -Dtools=disabled -Dcoverity=false \
		"$(BUILD_DIR)" "$(SRC_TREE)"

BUILD_CMDS = \
	python3 "$(MESON)" compile -C "$(BUILD_DIR)" && \
	python3 "$(MESON)" install -C "$(BUILD_DIR)"