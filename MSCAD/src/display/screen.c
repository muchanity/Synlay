#include "../../include/mscad.h"
#include <stdio.h>
#include <string.h>

void render_template(Configuration* config) {
    FILE* template = fopen(TEMPLATE_FILE, "r");
    if (!template) {
        perror("Fehler beim Öffnen des Templates");
        return;
    }

    char line[200];
    while (fgets(line, sizeof(line), template)) {
        char* start = strchr(line, '{');
        char* end = strchr(line, '}');

        if (start && end) {
            char key[50];
            strncpy(key, start + 1, end - start - 1);
            key[end - start - 1] = '\0';

            // Suche Konfigurationswert
            for (int i = 0; i < config->count; i++) {
                if (strcmp(config->items[i].key, key) == 0) {
                    // Ersetze Platzhalter
                    char replacement[10];
                    strcpy(replacement, config->items[i].enabled ? "ENABLED" : "DISABLED");
                    
                    // Einfache Ersetzung
                    char* pos = strstr(line, key);
                    if (pos) {
                        strcpy(pos, replacement);
                        strcat(line, pos + strlen(key));
                    }
                    break;
                }
            }
        }
        printf