#include "utils.h"
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>

void trim_whitespace(char* str) {
    char* end;
    while (isspace((unsigned char)*str)) str++;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
}

bool parse_bool(const char* value) {
    return strcasecmp(value, "true") == 0 || strcmp(value, "1") == 0;
}

void daemonize() {
    pid_t pid = fork();
    CHECK_SYS_CALL(pid);
    
    if (pid > 0) exit(EXIT_SUCCESS); // Parent process exits
    
    setsid();
    umask(0);
    chdir("/");
    
    // Close standard file descriptors
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}