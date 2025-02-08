#ifndef CONFIG_H
#define CONFIG_H

typedef struct {
    int show_cpu_temp;
    int show_cpu_usage;
    int show_gpu_temp;
} Config;

Config load_config(const char* config_path);

#endif