#include <stdio.h>
#include "../modules/cpu.h"
#include "../modules/gpu.h"
#include "../modules/config.h"

void display_system_info(Config config) {
    // CPU Temperatur
    if (config.show_cpu_temp) {
        float cpu_temp = get_cpu_temperature();
        if (cpu_temp >= 0) {
            printf("CPU Temperatur: %.1f°C\n", cpu_temp);
        }
    }
    
    // CPU Auslastung
    if (config.show_cpu_usage) {
        int cpu_usage = get_cpu_usage();
        if (cpu_usage >= 0) {
            printf("CPU Auslastung: %d%%\n", cpu_usage);
        }
    }
    
    // GPU Temperatur
    if (config.show_gpu_temp) {
        float gpu_temp = get_gpu_temperature();
        if (gpu_temp >= 0) {
            printf("GPU Temperatur: %.1f°C\n", gpu_temp);
        }
    }
}