#include "../include/mscad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Configuration global_config;

int load_config(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Fehler beim Öffnen der Konfigurationsdatei");
        return -1;
    }

    global_config.count = 0;
    char line[100];

    while (fgets(line, sizeof(line), file) && global_config.count < MAX_CONFIG_ITEMS) {
        // Überspringe Kommentare und leere Zeilen
        if (line[0] == '#' || line[0] == '\n') continue;

        char* key = strtok(line, "=");
        char* value = strtok(NULL, "\n");

        if (key && value) {
            // Trimme Whitespace
            while(*key == ' ') key++;
            while(value[strlen(value)-1] == ' ') value[strlen(value)-1] = '\0';

            strcpy(global_config.items[global_config.count].key, key);
            global_config.items[global_config.count].enabled = 
                (strcmp(value, "true") == 0);
            
            global_config.count++;
        }
    }

    fclose(file);
    return 0;
}

int main(int argc, char* argv[]) {
    // Unterdrücke Compiler-Warnings für unused parameters
    (void)argc;
    (void)argv;

    if (load_config(CONFIG_FILE) != 0) {
        fprintf(stderr, "Fehler beim Laden der Konfiguration\n");
        return 1;
    }

    // Modulaufrufe basierend auf Konfiguration
    for (int i = 0; i < global_config.count; i++) {
        if (global_config.items[i].enabled) {
            if (strcmp(global_config.items[i].key, "SYSTEM_CHECK") == 0)
                get_system_info();
            else if (strcmp(global_config.items[i].key, "NETWORK") == 0)
                get_network_info();
            else if (strcmp(global_config.items[i].key, "TEMPERATURE") == 0)
                get_temperature_info();
            else if (strcmp(global_config.items[i].key, "STORAGE") == 0)
                get_storage_info();
        }
    }

    return 0;
}
