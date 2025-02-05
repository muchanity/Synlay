#ifndef MSCAD_H
#define MSCAD_H

#include <stdbool.h>
#include <stdio.h>

#define MAX_CONFIG_ITEMS 20
#define CONFIG_FILE "configs/mscad.config"
#define TEMPLATE_FILE "configs/template.txt"

// Konfigurationsstruktur
typedef struct {
    char key[50];
    bool enabled;
} ConfigItem;

// Hauptkonfigurationsstruktur
typedef struct {
    ConfigItem items[MAX_CONFIG_ITEMS];
    int count;
} Configuration;

// Funktionsprototypen
int load_config(const char* filename);
void render_template(Configuration* config);
void init_mscad();

// Modulprototypen
void get_system_info();
void get_network_info();
void get_temperature_info();
void get_storage_info();

#endif // MSCAD_H