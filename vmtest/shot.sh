#!/bin/sh
# Screenshot the running VM (monitor) and convert to PNG. Does NOT quit.
exec {fd}<>/dev/tcp/127.0.0.1/4445
printf 'screendump %s\r' "/home/kanan/FreeLinX-workspace/vmtest/screen.ppm" >&$fd
sleep 1
exit 0