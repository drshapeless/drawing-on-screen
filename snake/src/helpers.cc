#include "helpers.hh"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void error_log(const char *msg, ...) {
    va_list argptr;
    va_start(argptr, msg);
    vfprintf(stderr, msg, argptr);
    va_end(argptr);
    fputc('\n', stderr);

    exit(1);
}
