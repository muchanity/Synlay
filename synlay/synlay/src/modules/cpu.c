#include "module.h"
#include "../include/config.h"

static int cpu_init(void) {
    // Initialisierungscode
    return 0;
}

static int cpu_update(void) {
    // Messcode
    return 0;
}

Module cpu_module = {
    .name = "cpu",
    .init = cpu_init,
    .update = cpu_update,
    .cleanup = NULL
};