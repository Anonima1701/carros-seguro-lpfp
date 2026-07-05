#include <stdio.h>
#include "linha.h"

void linha () {
    printf("======================================\n");
}

void pausar() {
printf("\nPressione ENTER para continuar...");
int ch;
while ((ch = getchar()) != '\n' && ch != EOF);
}