#include <stdio.h>
#include <stdlib.h>
#include "../../include/synlay.h"

float get_cpu_temperature(void) {
    FILE* pipe = popen("sensors | grep 'Core 0' | awk '{print $3}' | cut -c2-6", "r");
    float temp = 0.0;
    
    if (pipe) {
        fscanf(pipe, "%f", &temp);
        pclose(pipe);
    }
    
    return temp;
}

float get_cpu_usage(void) {
    FILE* pipe = popen("top -bn1 | grep 'Cpu(s)' | sed 's/.*, *\\([0-9.]*\\)%* id.*/\\1/' | awk '{print 100 - $1}'", "r");
    float usage = 0.0;
    
    if (pipe) {
        fscanf(pipe, "%f", &usage);
        pclose(pipe);
    }
    
    return usage;
}
