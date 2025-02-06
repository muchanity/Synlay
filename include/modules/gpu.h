#ifndef GPU_MODULE_H
#define GPU_MODULE_H

typedef struct {
    float temperature;
    float usage;
} GpuStats;

void gpu_module_init();
void gpu_module_update();
GpuStats gpu_module_get_stats();
void gpu_module_cleanup();

#endif