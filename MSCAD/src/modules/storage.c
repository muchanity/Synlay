#include "../../include/mscad.h"
#include <stdio.h>
#include <sys/statvfs.h>

void get_storage_info() {
    struct statvfs sv;
    if (statvfs("/", &sv) == 0) {
        long total_space = sv.f_blocks * sv.f_frsize / (1024 * 1024 * 1024);
        long free_space = sv.f_bfree * sv.f_frsize / (1024 * 1024 * 1024);
        long used_space = total_space - free_space;

        printf("Total Disk Space: %ld GB\n", total_space);
        printf("Used Disk Space: %ld GB (%.2f%%)\n", 
               used_space, 
               (float)used_space / total_space * 100);
    }
}