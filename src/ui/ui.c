#include "ui.h"

#include <stdio.h>

int menuPrincipal(void) {
    int opcao = -1;
    int leitura = 0;

    printf("\n=========================================\n");
    printf("               BAR DOS ALUNOS               \n");
    printf("=========================================\n");
    printf("[1] Inserir novo aluno\n");
    printf("[2] Eliminar aluno\n");
    printf("[3] Listar alunos\n");
    printf("[4] Efetuar despesa\n");
    printf("[5] Carregar saldo\n");
    printf("[0] Sair\n");
    printf("-----------------------------------------\n");
    printf("> Escolha uma opcao: ");

    leitura = scanf("%d", &opcao);
    if (leitura != 1) {
        opcao = -1;
    }

    while (getchar() != '\n') {
        continue;
    }

    return opcao;
}
