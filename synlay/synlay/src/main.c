#include <stdio.h>
#include <signal.h>
#include "config.h"
#include "output.h"
#include "modules/module.h"

static volatile sig_atomic_t running = 1;

void handle_signal(int sig) {
    running = 0;
}

int main(int argc, char* argv[]) {
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    Config cfg = {0};
    if(parse_config("synlay.config", &cfg) != 0) {
        fprintf(stderr, "Fehler beim Laden der Konfiguration\n");
        return 1;
    }

    // Module initialisieren
    Module* modules[] = {&cpu_module, &gpu_module, NULL};
    
    for(Module** m = modules; *m; m++) {
        if((*m)->init && (*m)->init() != 0) {
            fprintf(stderr, "Fehler bei der Initialisierung von %s\n", (*m)->name);
            return 1;
        }
    }

    // Hauptloop
    while(running) {
        for(Module** m = modules; *m; m++) {
            if((*m)->update) (*m)->update();
        }
        
        generate_output(&cfg);
        usleep(cfg.core.interval * 1000);
    }

    // Cleanup
    for(Module** m = modules; *m; m++) {
        if((*m)->cleanup) (*m)->cleanup();
    }

    return 0;
}