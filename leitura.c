#include "leitura.h"
#include <stdio.h>
#include <stdlib.h>

int ler_arquivo(const char *nome_arquivo, Conexao **conexoes, int *num_conexoes, int *num_pontos) 
{ 
    FILE *arquivo = fopen(nome_arquivo, "r");
    if(arquivo == NULL){
        perror("Erro ao abrir o arquivo\n");
        return -1;
    }

    if (fscanf(arquivo, "%d %d", num_pontos, num_conexoes) != 2) { 
        fclose(arquivo);
        return -1;
    }

    *conexoes = malloc(*num_conexoes * sizeof(Conexao));
    if(*conexoes == NULL){
        fclose(arquivo);
        return -1;
    }

    for(int i = 0; i < *num_conexoes; i++){
        if(fscanf(arquivo, "%d %d", &(*conexoes)[i].a, &(*conexoes)[i].b) != 2){
            free(*conexoes);
            fclose(arquivo);
            return -1;
        }
    }
    fclose(arquivo);
    return 0;
}