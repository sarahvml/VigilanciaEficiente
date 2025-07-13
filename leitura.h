#ifndef LEITURA_H
#define LEITURA_H

typedef struct {
    int a;
    int b;
}Conexao;

int ler_arquivo(const char *nome_arquivo, Conexao **conexao, int *num_conexao, int *num_pontos);

#endif
