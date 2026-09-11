#!/bin/sh
exec {fd}<>/dev/tcp/127.0.0.1/4445
printf 'screendump %s\r' "/home/kanan/FreeLinX-workspace/vmtest/screen.ppm" >&$fd
sleep 0.5
printf 'quit\r' >&$fd
