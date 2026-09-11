# FreeLinX/ports - base/runit : runit process supervision suite (2.1.2).
#
# Final /init supervision: runsvdir + runsv manage per-service run files.
# runsvdir/runit-init/runsv go to /sbin; sv/svlogd/chpst/utmpset to /usr/bin.
# Built statically with the FreeLinX musl toolchain.
NAME    := runit
VERSION := 2.1.2
CATEGORY:= base
LICENSE := BSD-3-Clause (public domain individual components)
DEPENDENCIES:=
BUILD_DEPENDENCIES:= musl (via FreeLinX toolchain sysroot)
TARGET  := $(FREELINX_TRIPLE)
PREFIX  := /

include ../../mk/project-port.mk

RUNIT_PREFIX = $(FREELINX_BUILD_DIR)/deps/$(NAME)
SRC_TREE = $(FREELINX_BUILD_DIR)/work/$(NAME)/admin/runit-$(VERSION)
SRC  = $(SRC_TREE)/src
CC_ABS = $(FREELINX_TOOLCHAIN_BIN)/freelinix-cc

# runsvdir is the artifact the port _must_ deliver for the general port
# framework; the full suite is staged into the deps prefix as a rootfs mirror
# (sbin/ + usr/bin/), consumed by the rootfs assembly.
PROJECT_BIN = $(RUNIT_PREFIX)/sbin/runsvdir
BUILD_BIN   = $(PROJECT_BIN)

PROJECT_CFG_CMDS = \
	printf '%s\n' "$(CC_ABS) -std=gnu89 -O2 -Wall" > "$(SRC)/conf-cc" && \
	printf '%s\n' "$(CC_ABS) -static" > "$(SRC)/conf-ld" && \
	printf '%s\n' 'linux-i386' > "$(SRC)/systype" && \
	cp "$(CURDIR)/choose.in" "$(SRC)/choose" && chmod +x "$(SRC)/choose"

BUILD_CMDS = \
	$(MAKE) -C "$(SRC)" -s sysdeps && \
	$(MAKE) -C "$(SRC)" -s chpst runit runit-init runsv runsvchdir runsvdir sv svlogd utmpset && \
	mkdir -p "$(RUNIT_PREFIX)/sbin" "$(RUNIT_PREFIX)/usr/bin" && \
	for _b in runsvdir runsv runit-init runsvchdir runit; do \
		cp "$(SRC)/$$_b" "$(RUNIT_PREFIX)/sbin/"; done && \
	for _b in sv svlogd chpst utmpset; do \
		cp "$(SRC)/$$_b" "$(RUNIT_PREFIX)/usr/bin/"; done