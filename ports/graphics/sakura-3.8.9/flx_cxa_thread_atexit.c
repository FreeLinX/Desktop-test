/*
 * FreeLinX/ports - graphics/sakura-3.8.9
 * musl in the FreeLinX toolchain does not export __cxa_thread_atexit_impl
 * (glibc extension used by libc++abi for thread-local destructors). Provide
 * an implementation routed through musl's __cxa_atexit instead.
 */
#include <stddef.h>
#include <stdlib.h>

extern int __cxa_atexit(void (*func)(void *), void *arg, void *dso);

int __cxa_thread_atexit_impl(void (*func)(void *), void *obj, void *dso)
{
    (void)dso;
    return __cxa_atexit(func, obj, NULL);
}