#include "../../include/mscad.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <unistd.h>

void get_system_info() {
    struct sysinfo si;
    if (sysinfo(&si) == 0) {
        long total_ram = si.totalram * si.mem_unit / (1024 * 1024);
        long free_ram = si.freeram * si.mem_unit / (1024 * 1024);
        long used_ram = total_ram - free_ram;

        printf("System Load: %.2f\n", si.loads[0] / 65536.0);
        printf("Total RAM: %ld MB\n", total_ram);
        printf("Used RAM: %ld MB (%.2f%%)\n", 
               used_ram, 
               (float)used_ram / total_ram * 100);
        printf("Uptime: %ld seconds\n", si.uptime);
    }
}