# FreeLinX/ports - graphics/atk-2.38.0 : atk-2.38.0 2.38.0. Static cross build.
NAME    := atk-2.38.0
VERSION := 2.38.0
CATEGORY:= graphics
LICENSE := ATK-2.38.0 Public
DEPENDENCIES:=
BUILD_DEPENDENCIES:=
TARGET  := $(FREELINX_TRIPLE)
PREFIX  := /

FLX_PREFIX = $(FREELINX_BUILD_DIR)/deps/$(NAME)
MESON    := /tmp/opencode/meson-1.6.1/meson.py
SRC_TREE = $(FREELINX_BUILD_DIR)/work/$(NAME)/$(NAME)
BUILD_DIR = $(FREELINX_BUILD_DIR)/obj/$(NAME)/meson
PROJECT_BIN = $(FLX_PREFIX)/lib/libatk-1.0.a
BUILD_BIN   = $(PROJECT_BIN)

include ../../mk/project-port.mk

export PATH := /tmp/opencode/host-tools:$(PATH)

PROJECT_CFG_CMDS = \
	sed -i "/subdir('tests')/d; /^x$$/d" meson.build && \
	rm -rf "$(BUILD_DIR)" && mkdir -p "$(BUILD_DIR)" && \
	python3 "$(MESON)" setup \
		--cross-file "$(CURDIR)/meson-cross.ini" \
		--buildtype=release \
		--default-library=static \
		-Ddocs=false -Dintrospection=false \
		--prefix="$(FLX_PREFIX)" \
		"$(BUILD_DIR)" "$(SRC_TREE)"

BUILD_CMDS = \
	python3 "$(MESON)" compile -C "$(BUILD_DIR)" && \
	python3 "$(MESON)" install -C "$(BUILD_DIR)"
