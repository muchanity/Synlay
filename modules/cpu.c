#include "modules/cpu.h"
#include "../utils.h"
#include <stdio.h>

static CpuStats current_stats;

void cpu_module_init() {
    // Initialisierungscode
}

void cpu_module_update() {
    FILE* thermal = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
    if (thermal) {
        fscanf(thermal, "%f", &current_stats.temperature);
        current_stats.temperature /= 1000;
        fclose(thermal);
    }
}

CpuStats cpu_module_get_stats() {
    return current_stats;
}

void cpu_module_cleanup() {
    // Cleanup code
}