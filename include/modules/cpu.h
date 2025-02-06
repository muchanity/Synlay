#ifndef CPU_MODULE_H
#define CPU_MODULE_H

typedef struct {
    float temperature;
    float usage;
} CpuStats;

void cpu_module_init();
void cpu_module_update();
CpuStats cpu_module_get_stats();
void cpu_module_cleanup();

#endif