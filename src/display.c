// synlay/src/display.c
#include <ncurses.h>

void init_display() {
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    timeout(0);
}

void update_display(const SynlayConfig* config) {
    erase();
    printw("System Monitor\n");
    printw("----------------\n");
    
    if (config->cpu_temp) {
        CpuStats cpu = cpu_module_get_stats();
        printw("CPU Temperature: %.1f°C\n", cpu.temperature);
    }
    
    refresh();
}