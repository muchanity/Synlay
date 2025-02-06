#include <stdio.h>
#include <stdlib.h>
#include "../../include/synlay.h"

int main() {
    MetricConfig* config = load_config("configs/synlay.config");
    
    if (!config) {
        fprintf(stderr, "Fehler beim Laden der Konfiguration\n");
        return 1;
    }

    print_available_metrics(config);

    if (is_metric_enabled(config, "cpu-temp")) {
        printf("CPU Temperatur: %.1f°C\n", get_cpu_temperature());
    }

    if (is_metric_enabled(config, "cpu-usage")) {
        printf("CPU Auslastung: %.1f%%\n", get_cpu_usage());
    }

    free(config);
    return 0;
}
