#pragma once

typedef struct {
    const char* name;
    int (*init)(void);
    int (*update)(void);
    void (*cleanup)(void);
} Module;

// Modul-Deklarationen
extern Module cpu_module;
extern Module gpu_module;