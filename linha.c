#include <stdio.h>
#include "linha.h"

#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void linha () {
    printf(ANSI_COLOR_CYAN "======================================\n" ANSI_COLOR_RESET);
}