#ifndef SYNLAY_H
#define SYNLAY_H

#include <stdbool.h>

#define CONFIG_PATH "/etc/synlay.conf"
#define MAX_MODULES 10
#define UPDATE_INTERVAL 1 // in seconds

typedef struct {
    bool cpu_temp;
    bool cpu_usage;
    bool gpu_temp;
    bool gpu_usage;
    unsigned int refresh_rate;
} SynlayConfig;

void init_application();
void cleanup_application();
void reload_config();
void run_main_loop();

#endif