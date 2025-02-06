#include "modules/gpu.h"
#include "../utils.h"
#include <stdio.h>

static GpuStats current_stats;

void gpu_module_init() {
    // Initialisierungscode
}

void gpu_module_update() {
    FILE* pipe = popen("vcgencmd measure_temp", "r");
    if (pipe) {
        char buffer[128];
        fgets(buffer, sizeof(buffer), pipe);
        sscanf(buffer, "temp=%f'C", &current_stats.temperature);
        pclose(pipe);
    }
}

GpuStats gpu_module_get_stats() {
    return current_stats;
}

void gpu_module_cleanup() {
    // Cleanup code
}