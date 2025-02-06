#include "config.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SynlayConfig parse_config(const char* path) {
    SynlayConfig config = {0};
    FILE* file = fopen(path, "r");
    
    if (!file) {
        LOG_ERROR("Config file not found, using defaults");
        return config;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char* key = strtok(line, "=");
        char* value = strtok(NULL, "\n");
        
        if (!key || !value) continue;
        
        trim_whitespace(key);
        trim_whitespace(value);

        if (strcmp(key, "cpu-temp") == 0) {
            config.cpu_temp = parse_bool(value);
        }
        // Add other config options
    }
    
    fclose(file);
    return config;
}

bool validate_config(const SynlayConfig* config) {
    // Add validation logic
    return true;
}