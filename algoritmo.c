#include "algoritmo.h"
#include <stdlib.h>
#include <stdbool.h>

bool ponto_ja_selecionado(int ponto, int *pontos_selecionados, int tamanho, int index) {
    if (index >= tamanho) return false;
    if (pontos_selecionados[index] == ponto) return true;
    return ponto_ja_selecionado(ponto, pontos_selecionados, tamanho, index + 1);
}

static int contar_cobertura(int ponto, Conexao *conexoes, int num_conexoes, bool *vigiadas) {
    int count = 0;
    for (int i = 0; i < num_conexoes; i++) {
        if (!vigiadas[i] && (conexoes[i].a == ponto || conexoes[i].b == ponto)) {
            count++;
        }
    }
    return count;
}

Solucao encontrar_minimo_cameras_guloso(Conexao *conexoes, int num_conexoes, int num_pontos) {
    Solucao solucao = {NULL, 0};
    bool *vigiadas = calloc(num_conexoes, sizeof(bool));
    if (!vigiadas) {
        return solucao;
    }

    solucao.pontos = malloc(num_pontos * sizeof(int));
    if (!solucao.pontos) {
        free(vigiadas);
        return solucao;
    }

    while (true) {
        int melhor_ponto = -1;
        int max_cobertura = 0;

        for (int p = 0; p < num_pontos; p++) {
           
            if (!ponto_ja_selecionado(p, solucao.pontos, solucao.tamanho, 0)) {
                int cobertura = contar_cobertura(p, conexoes, num_conexoes, vigiadas);
                if (cobertura > max_cobertura) {
                    max_cobertura = cobertura;
                    melhor_ponto = p;
                }
            }
        }

        if (melhor_ponto == -1) break;

        solucao.pontos[solucao.tamanho++] = melhor_ponto;
        for (int i = 0; i < num_conexoes; i++) {
            if (!vigiadas[i] && (conexoes[i].a == melhor_ponto || conexoes[i].b == melhor_ponto)) {
                vigiadas[i] = true;
            }
        }
    }

    free(vigiadas);
    return solucao;
}
