#include "leitura.h"
#include "algoritmo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mostra_menu_principal(){
    printf("\n=== Vigilancia eficiente ===\n");
    printf("1. Processar arquivo\n");
    printf("2. Sair\n");
    printf("Escolha: ");
}

void mostrar_menu_arquivos() {
    printf("\nArquivos disponiveis:\n");
    printf("1. n_5_m_6.txt\n");
    printf("2. n_6_m_8.txt\n");
    printf("3. n_8_m_12.txt\n");
    printf("4. Outro arquivo\n");
    printf("Escolha (1-4): ");
}

void processar_arquivo(const char *nome_arquivo) {
    Conexao *conexoes = NULL;
    int num_conexoes, num_pontos;

    if (ler_arquivo(nome_arquivo, &conexoes, &num_conexoes, &num_pontos) != 0){
        printf("Erro ao processar o arquivo %s\n", nome_arquivo);
        return;
    }

    printf("\nArquivo carregado: %s\n", nome_arquivo);
    printf("Pontos: %d | Conexoes: %d\n", num_pontos, num_conexoes);

    Solucao solucao = encontrar_minimo_cameras_guloso(conexoes, num_conexoes, num_pontos);

    printf("\nResultado:\n");
    printf("Numero minimo de cameras: %d\n", solucao.tamanho);
    printf("Pontos para instalacao: ");
    for(int i = 0; i < solucao.tamanho; i++){
        printf("%d ", solucao.pontos[i]);
    }
    printf("\n");

    free(conexoes);
    free(solucao.pontos);
}

int main(){
    int opcao;
    char nome_arquivo[100];

    do {
        mostra_menu_principal();
        scanf("%d", &opcao);

        if(opcao == 1){
            int escolha;
            mostrar_menu_arquivos();
            scanf("%d", &escolha);

            switch(escolha){
                case 1: strcpy(nome_arquivo, "n_5_m_6.txt"); break;
                case 2: strcpy(nome_arquivo, "n_6_m_8.txt"); break;
                case 3: strcpy(nome_arquivo, "n_8_m_12.txt"); break;
                case 4:
                    printf("Digite o nome do arquivo: ");
                    scanf("%99s", nome_arquivo);
                    break;
                default:
                    printf("Opcao invalida\n");
                    continue;
            }
            processar_arquivo(nome_arquivo);
        }
    } while (opcao != 2);

    printf("Programa encerrado.\n");
    return 0;
}
