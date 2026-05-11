#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Aluno *criarAluno(char *nome, Data dataNascimento, char *curso, int ano, int numero, float saldoInicial) {
    Aluno *novo = NULL;

    if (nome == NULL || curso == NULL || ano <= 0 || numero <= 0 || saldoInicial < 0) {
        return NULL;
    }

    novo = (Aluno *)malloc(sizeof(Aluno));
    if (novo == NULL) {
        return NULL;
    }

    strncpy(novo->nome, nome, TAM_NOME - 1);
    novo->nome[TAM_NOME - 1] = '\0';
    
    strncpy(novo->curso, curso, TAM_CURSO - 1);
    novo->curso[TAM_CURSO - 1] = '\0';

    novo->dataNascimento = dataNascimento;
    novo->ano = ano;
    novo->numero = numero;
    novo->saldo = saldoInicial;
    
    novo->listaDespesas = NULL;
    novo->proximo = NULL;

    return novo;
}

int inserirAlunoOrdenado(Aluno **lista, Aluno *novo) {
    Aluno *atual = NULL;
    Aluno *anterior = NULL;

    if (lista == NULL || novo == NULL) {
        return 0;
    }

    atual = *lista;

    while (atual != NULL) {
        if (atual->numero == novo->numero) {
            return 0;
        }

        if (strcmp(atual->nome, novo->nome) > 0) {
            break;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    if (anterior == NULL) {
        novo->proximo = *lista;
        *lista = novo;
        return 1;
    }

    novo->proximo = atual;
    anterior->proximo = novo;
    return 1;
}

Aluno *procurarAlunoPorNumero(Aluno *lista, int numero) {
    Aluno *atual = lista;

    while (atual != NULL) {
        if (atual->numero == numero) {
            return atual;
        }
        atual = atual->proximo;
    }

    return NULL;
}

void listarAlunosOrdenados(Aluno *lista) {
    Aluno *atual = lista;

    if (atual == NULL) {
        printf("Nao existem alunos registados.\n");
        return;
    }

    while (atual != NULL) {
        printf("Numero: %d | Nome: %s | Curso: %s | Ano: %d | Saldo: %.2f\n",
               atual->numero,
               atual->nome,
               atual->curso,
               atual->ano,
               atual->saldo);
        atual = atual->proximo;
    }
}

int removerAlunoPorNumero(Aluno **lista, int numero) {
    Aluno *atual = NULL;
    Aluno *anterior = NULL;

    if (lista == NULL) {
        return 0;
    }

    atual = *lista;

    while (atual != NULL && atual->numero != numero) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        return 0;
    }

    if (anterior == NULL) {
        *lista = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    libertarListaDespesas(&atual->listaDespesas);
    free(atual);
    return 1;
}
