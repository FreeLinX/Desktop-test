# strip-reflect.awk - remove the gtk3 "reflect" demo executables from
# src/meson.build (they need to LINK a static gtk/vte and fail on the
# cross toolchain; only the library matters for FreeLinX).
/^# reflect$/ { indel = 1; next }
indel && /^endif$/ { indel = 0; next }
indel { next }
{ print }