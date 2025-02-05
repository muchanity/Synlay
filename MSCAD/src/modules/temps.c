#include "../../include/mscad.h"
#include <stdio.h>
#include <stdlib.h>

#define TEMP_FILE "/sys/class/thermal/thermal_zone0/temp"

void get_temperature_info() {
    FILE* tempfile = fopen(TEMP_FILE, "r");
    if (tempfile) {
        int temperature;
        if (fscanf(tempfile, "%d", &temperature) == 1) {
            printf("CPU Temperature: %.1f°C\n", temperature / 1000.0);
        }
        fclose(tempfile);
    }
}