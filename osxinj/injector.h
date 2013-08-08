#ifndef _INJECTOR_H_
#define _INJECTOR_H_

#include "mach_inject.h"
// #include <Carbon/Carbon.h>

extern "C" void __pthread_set_self(void*);

class Injector
{
private:
    static void *pthread_entry(void *patch_bundle);
    static void inject_entry(ptrdiff_t offset, void *param, size_t psize, void *dummy);
public:
    Injector();
    ~Injector();

    void inject(pid_t pid, const char* lib);
    pid_t getProcessByName(const char *name);
};

#endif