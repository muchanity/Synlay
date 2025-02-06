#pragma once

typedef struct {
    struct {
        unsigned interval;
        char output_format[10];
        int daemon;
    } core;
    
    struct {
        int enabled;
        int temperature;
        int usage;
        int clock;
        unsigned critical_temp;
    } cpu;
    
    struct {
        int enabled;
        int temperature;
        int memory;
    } gpu;
    
    struct {
        char log_file[256];
        size_t max_size;
    } logging;
    
} Config;

int parse_config(const char* path, Config* cfg);
void print_config(const Config* cfg);