#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"

Config load_config(const char* config_path) {
    Config config = {1, 1, 1}; // Standardmäßig alles an
    FILE* file = fopen(config_path, "r");
    
    if (file == NULL) {
        return config;
    }
    
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Ignoriere Kommentare und Leerzeilen
        if (line[0] == '#' || line[0] == '\n') continue;
        
        char *key = strtok(line, "=");
        char *value = strtok(NULL, "\n");
        
        if (key && value) {
            if (strcmp(key, "cpu-temp") == 0) {
                config.show_cpu_temp = (strcmp(value, "true") == 0);
            }
            if (strcmp(key, "cpu-usage") == 0) {
                config.show_cpu_usage = (strcmp(value, "true") == 0);
            }
            if (strcmp(key, "gpu-temp") == 0) {
                config.show_gpu_temp = (strcmp(value, "true") == 0);
            }
        }
    }
    
    fclose(file);
    return config;
}