#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/synlay.h"

MetricConfig* load_config(const char* path) {
    FILE* file = fopen(path, "r");
    if (!file) {
        perror("Konfigurationsdatei nicht gefunden");
        return NULL;
    }

    MetricConfig* config = malloc(sizeof(MetricConfig));
    config->count = 0;

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char name[MAX_METRIC_NAME];
        int enabled;

        if (sscanf(line, "%49[^=]=%d", name, &enabled) == 2) {
            strncpy(config->metrics[config->count].name, name, MAX_METRIC_NAME);
            config->metrics[config->count].enabled = enabled;
            config->count++;
        }
    }

    fclose(file);
    return config;
}

int is_metric_enabled(MetricConfig* config, const char* name) {
    for (int i = 0; i < config->count; i++) {
        if (strcmp(config->metrics[i].name, name) == 0) {
            return config->metrics[i].enabled;
        }
    }
    return 0;
}

void print_available_metrics(MetricConfig* config) {
    printf("Verfügbare Metriken:\n");
    for (int i = 0; i < config->count; i++) {
        printf("%s: %s\n", 
               config->metrics[i].name, 
               config->metrics[i].enabled ? "Aktiviert" : "Deaktiviert");
    }
}