#include <stdio.h>
#include <stdlib.h>

float get_cpu_temperature() {
    FILE *file;
    int temp;
    
    file = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
    if (file == NULL) return -1;
    
    fscanf(file, "%d", &temp);
    fclose(file);
    
    return temp / 1000.0;
}