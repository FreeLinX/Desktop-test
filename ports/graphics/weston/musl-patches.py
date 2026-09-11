#!/usr/bin/env python3
import sys, os

TREE = sys.argv[1]

PATCHES = [
    ("FREELINX-MUSL-001",
     "libweston/backend-drm/libbacklight.c",
     "#include <errno.h>\n",
     "#include <errno.h>\n#include <libgen.h>\n",
     "musl declares basename() in <libgen.h>, not <string.h>"),
    ("FREELINX-MUSL-002",
     "tools/zunitc/src/zunitc_impl.c",
     "#include <string.h>\n",
     "#include <string.h>\n#include <libgen.h>\n",
     "musl declares basename() in <libgen.h>, not <string.h>"),
]

def apply(root, patch):
    tag, rel, before, after, why = patch
    path = os.path.join(root, rel)
    if not os.path.exists(path):
        return False
    with open(path, encoding="utf-8") as f:
        s = f.read()
    if before not in s:
        return False
    if after in s and after != before:
        # already applied
        return True
    s = s.replace(before, after, 1)
    with open(path, "w", encoding="utf-8") as f:
        f.write(s)
    return True

def main():
    status = 0
    for patch in PATCHES:
        tag, rel, _, _, why = patch
        if not apply(TREE, patch):
            print(f"[{tag}] SKIP (no match or already applied): {rel} - {why}", file=sys.stderr)
            continue
        print(f"[{tag}] applied: {rel} - {why}")
    sys.exit(status)

if __name__ == "__main__":
    main()