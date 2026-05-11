#include "despesa.h"

#include <stdlib.h>

void libertarListaDespesas(Despesa **listaDespesas) {
    Despesa *atual = NULL;

    if (listaDespesas == NULL) {
        return;
    }

    atual = *listaDespesas;

    while (atual != NULL) {
        Despesa *proxima = atual->proximo;
        free(atual);
        atual = proxima;
    }

    *listaDespesas = NULL;
}
