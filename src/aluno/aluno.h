#ifndef ALUNO_H
#define ALUNO_H

#include "../despesa/despesa.h"
#include "../utils/data.h"

#define TAM_NOME 100
#define TAM_CURSO 100

typedef struct Aluno {
    char nome[TAM_NOME];
    Data dataNascimento;
    char curso[TAM_CURSO];
    int ano;
    int numero;
    float saldo;
    Despesa *listaDespesas;
    struct Aluno *proximo;
} Aluno;

#endif
