#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <errno.h>
#include <string.h>

#define LOG_ERROR(fmt, ...) \
    fprintf(stderr, "[ERROR] %s:%d: " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define CHECK_SYS_CALL(call) \
    if ((call) == -1) { \
        LOG_ERROR("System call failed: %s", strerror(errno)); \
        exit(EXIT_FAILURE); \
    }

void trim_whitespace(char* str);
bool parse_bool(const char* value);
void daemonize();

#endif