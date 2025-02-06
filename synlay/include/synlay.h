#ifndef SYNLAY_H
#define SYNLAY_H

#define MAX_METRIC_NAME 50
#define MAX_METRICS 20

typedef struct {
    char name[MAX_METRIC_NAME];
    int enabled;
} Metric;

typedef struct {
    Metric metrics[MAX_METRICS];
    int count;
} MetricConfig;

// Konfigurationsfunktionen
MetricConfig* load_config(const char* path);
int is_metric_enabled(MetricConfig* config, const char* name);
void print_available_metrics(MetricConfig* config);

// CPU-Metrik Funktionen
float get_cpu_temperature(void);
float get_cpu_usage(void);

#endif // SYNLAY_H
