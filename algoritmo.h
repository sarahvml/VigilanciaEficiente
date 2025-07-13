#include "leitura.h"
#ifndef ALGORITMO_H
#define ALGORITMO_H
#include <stdbool.h>

typedef struct {
    int *pontos;
    int tamanho;
} Solucao;

bool ponto_ja_selecionado(int ponto, int *pontos_selecionados, int tamanho, int index);

// Algoritmo guloso original (não alterado)
Solucao encontrar_minimo_cameras_guloso(Conexao *conexoes, int num_conexoes, int num_pontos);

#endif