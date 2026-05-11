#ifndef DESPESA_H
#define DESPESA_H

#define TAM_DESCRICAO 200

#include "../utils/data.h"

typedef struct Despesa {
    float valor;
    char descricao[TAM_DESCRICAO];
    Data data;
    struct Despesa *proximo;
} Despesa;

#endif
