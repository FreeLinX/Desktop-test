#!/bin/sh
# FreeLinX - boot the desktop initramfs under QEMU/KVM (headless).
# Monitor on telnet 127.0.0.1:4445; serial console in vmtest/serial.log.
set -eu
cd /home/kanan/FreeLinX-workspace
QEMU=qemu/qemu-install/bin/qemu-system-x86_64
KERNEL=kernel/bzImage
INITRD=src/build/freelinx-desktop.img.gz
[ -f "$KERNEL" ] || { echo "missing $KERNEL"; exit 1; }
[ -f "$INITRD" ] || { echo "missing $INITRD"; exit 1; }

rm -f vmtest/serial.log vmtest/screen.ppm
: > vmtest/serial.log

"$QEMU" \
    -machine q35,accel=kvm \
    -cpu host -smp 4 -m 1280 \
    -kernel "$KERNEL" \
    -initrd "$INITRD" \
    -append "console=ttyS0,115200 rdinit=/init quiet loglevel=2" \
    -device virtio-gpu-pci \
    -monitor telnet:127.0.0.1:4445,server,nowait \
    -serial file:vmtest/serial.log \
    -display none -vga none -no-reboot \
    > vmtest/qemu.log 2>&1 &
echo $! > vmtest/qemu.pid
echo "QEMU pid $(cat vmtest/qemu.pid)"