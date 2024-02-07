#include "helpers.hh"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void error_log(const char *msg, ...) {
    fputs("[ERROR] ", stderr);
    va_list argptr;
    va_start(argptr, msg);
    vfprintf(stderr, msg, argptr);
    va_end(argptr);
    fputc('\n', stderr);

    exit(1);
}

void trace_log(const char *msg, ...) {
#ifndef RELEASE
    fputs("[TRACE] ", stdout);
    va_list argptr;
    va_start(argptr, msg);
    vfprintf(stdout, msg, argptr);
    va_end(argptr);
    fputc('\n', stdout);
#endif
}
