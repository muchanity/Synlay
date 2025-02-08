#include <stdio.h>
#include <stdlib.h>
#include "../modules/config.h"
#include "display.h"

int main() {
    // Konfigurationsdatei im aktuellen Verzeichnis
    Config config = load_config("synlay.conf");
    
    display_system_info(config);
    
    return 0;
}