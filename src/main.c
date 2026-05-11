#include <stdio.h>

#include "ui/ui.h"

int main() {
    int opcao = menuPrincipal();
    printf("Opcao escolhida: %d\n", opcao);
    return 0;
}