# Manual QEMU boot (with a visible window)

```
qemu/bin/qemu-system-x86_64 \
  -machine q35,accel=kvm \
  -cpu host -smp 4 -m 1280 \
  -kernel kernel/bzImage \
  -initrd src/build/freelinx-desktop.img.gz \
  -append "console=ttyS0,115200 rdinit=/init quiet loglevel=2" \
  -device virtio-gpu-pci \
  -serial mon:stdio \
  -monitor none \
  -display sdl
```

Notes:
- Same config as vmtest/boot.sh but with an SDL window (visible), serial on stdio, no telnet monitor.
- Qt/gtk display also works: replace `-display sdl` with `-display gtk`.
- To quit: close the window, or Ctrl-C if serial is bound to stdio.
