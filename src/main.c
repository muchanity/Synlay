#include "synlay.h"
#include "config.h"
#include "utils.h"
#include "modules/cpu.h"
#include "modules/gpu.h"
#include <signal.h>
#include <unistd.h>

static volatile sig_atomic_t running = 1;

void signal_handler(int sig) {
    (void)sig;
    running = 0;
}

int main() {
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
    
    init_application();
    
    while(running) {
        update_display();
        sleep(UPDATE_INTERVAL);
    }
    
    cleanup_application();
    return 0;
}