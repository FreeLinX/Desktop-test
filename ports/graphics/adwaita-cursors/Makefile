# FreeLinX/ports - graphics/adwaita-cursors : Adwaita cursor theme (48.0).
#
# Data-only port: prebuilt Xcursor images from the Adwaita icon theme release
# (only the cursor theme + index.theme are staged, not the full icon set).
NAME    := adwaita-cursors
VERSION := 48.0
CATEGORY:= graphics
LICENSE := LGPL-3.0-or-later with exceptions (theme)
DEPENDENCIES:=
BUILD_DEPENDENCIES:=
TARGET  := $(FREELINX_TRIPLE)
PREFIX  := /

include ../../mk/project-port.mk

CUR_PREFIX = $(FREELINX_BUILD_DIR)/deps/$(NAME)
SRC_TREE = $(FREELINX_BUILD_DIR)/work/$(NAME)/adwaita-icon-theme-$(VERSION)

PROJECT_BIN = $(CUR_PREFIX)/usr/share/icons/Adwaita/cursors/left_ptr
BUILD_BIN   = $(PROJECT_BIN)

BUILD_CMDS = \
	mkdir -p "$(CUR_PREFIX)/usr/share/icons/Adwaita" && \
	cp -a "$(SRC_TREE)/Adwaita/cursors" "$(CUR_PREFIX)/usr/share/icons/Adwaita/" && \
	cp "$(SRC_TREE)/index.theme" "$(CUR_PREFIX)/usr/share/icons/Adwaita/" && \
	cd "$(CUR_PREFIX)/usr/share/icons/Adwaita/cursors" && \
	ln -sf copy    dnd-copy && \
	ln -sf no-drop dnd-none && \
	ln -sf move    dnd-move && \
	ln -sf alias   dnd-link && \
	ln -sf alias   dnd-ask