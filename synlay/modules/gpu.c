#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float get_gpu_temperature() {
    FILE *pipe;
    char buffer[128];
    float temp = -1;

    // Versuche VCHIP Temperatur (Raspberry Pi spezifisch)
    pipe = popen("/opt/vc/bin/vcgencmd measure_temp", "r");
    if (pipe == NULL) return -1;

    if (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        // Extrahiere Temperatur aus dem Format temp=45.0'C
        char *start = strchr(buffer, '=');
        if (start) {
            temp = atof(start + 1);
        }
    }
    
    pclose(pipe);
    return temp;
}