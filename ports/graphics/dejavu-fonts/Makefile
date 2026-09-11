# FreeLinX/ports - graphics/dejavu-fonts : DejaVu fonts, TTF (2.37).
#
# Data-only port: the TTF families staged at /usr/share/fonts/TTF for
# fontconfig.  No compilation; extract + copy.
NAME    := dejavu-fonts
VERSION := 2.37
CATEGORY:= graphics
LICENSE := Bitstream Vera plus extensions (freely redistributable)
DEPENDENCIES:=
BUILD_DEPENDENCIES:=
TARGET  := $(FREELINX_TRIPLE)
PREFIX  := /

include ../../mk/project-port.mk

FONT_PREFIX = $(FREELINX_BUILD_DIR)/deps/$(NAME)
SRC_TREE = $(FREELINX_BUILD_DIR)/work/$(NAME)/dejavu-fonts-ttf-$(VERSION)

PROJECT_BIN = $(FONT_PREFIX)/usr/share/fonts/TTF/DejaVuSans.ttf
BUILD_BIN   = $(PROJECT_BIN)

BUILD_CMDS = \
	mkdir -p "$(FONT_PREFIX)/usr/share/fonts/TTF" && \
	cp "$(SRC_TREE)"/ttf/*.ttf "$(FONT_PREFIX)/usr/share/fonts/TTF/" && \
	cp "$(SRC_TREE)"/LICENSE "$(FONT_PREFIX)/usr/share/fonts/TTF/DEJAVU-LICENSE"