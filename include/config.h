#ifndef CONFIG_H
#define CONFIG_H

#include "synlay.h"

SynlayConfig parse_config(const char* path);
bool validate_config(const SynlayConfig* config);
void print_config(const SynlayConfig* config);

#endif