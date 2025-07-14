# Projeto: Vigilancia Eficiente

## Descrição

Este projeto tem o objetivo de simular a instalação de uma rede de vigilância em uma cidade inteligente. O sistema recebe a quantidade de pontos (cruzamentos ou locais importantes) e de conexões (ruas ou vielas) que os ligam, retornando o menor número de pontos para colocar câmeras, de modo que todas as linhas (conexões) toquem em pelo menos um ponto com câmera.

---

## Como Executar

### Requisitos

- Um compilador C (como GCC ou Clang):
  - **Linux:** `sudo apt install build-essential`
  - **Windows:** Instale o MinGW.
  - **macOS:** Instale o Xcode Command Line Tools com `xcode-select --install`.

### Passos

1. Clone este repositório:

   ```bash
   git clone https://github.com/sarahvml/VigilanciaEficiente.git

   ```

    ```bash
   cd VigilanciaEficiente
   ```
  
2. Compile o código:

   ```bash
   gcc main.c algoritmo.c algoritmo.h leitura.c leitura.h -o vigilancia_executable
   ```

3. Execute o programa:

   ```bash
   ./vigilancia_executable
   ```
   
## Estrutura do Código

O código está organizado em vários arquivos:

- **1**. `main.c` - Contém a lógica principal do programa e a interface do usuário
- **2**. `leitura.h` e `leitura.c` - Responsáveis pela leitura dos arquivos de entrada.
- **3**. `algoritmo.h` e `algoritmo.c` - Implementam o algoritmo guloso para resolver o problema.
- **4**. Arquivos de teste (`n_5_m_6.txt`, `n_6_m_8.txt`, `n_8_m_12.txt`) - Contêm exemplos de redes de pontos e conexões.


Exemplo de arquivo de entrada:

```
5 6
0 1
0 2
1 2
1 3
2 4
3 4
...
EOF
```

## Como funciona o programa 

O programa funciona da seguinte maneira:

- **1**. O usuário seleciona um arquivo contendo a descrição da rede (pontos e conexões)
- **2**. O programa lê o arquivo e armazena as conexões
- **3**.O algoritmo guloso é aplicado para encontrar o número mínimo de câmeras
- **4** .Os resultados são exibidos ao usuário
---
## Leitura do Arquivo  (`leitura.h` e `leitura.c`)
```bash
typedef struct {
 int a;
 int b;
} Conexao;
```
```bash
int ler_arquivo(const char *nome_arquivo, Conexao **conexoes, int *num_conexoes, int
*num_pontos)
```

Esta função:

- **1**. Abre o arquivo especificado
- **2** .Lê os dois primeiros números: número de pontos e de conexões
- **3** .Aloca memória e armazena as conexões lidas
- **4**. Retorna 0 em caso de sucesso ou -1 em erro

## Algoritmo Guloso (`algoritmo.h` e `algoritmo.c`)
```bash
typedef struct {
 int *pontos; // Array de pontos selecionados para instalação de câmeras
 int tamanho; // Número de pontos selecionados (tamanho do array)
} Solucao;
```
```bash
Solucao encontrar_minimo_cameras_guloso(Conexao *conexoes, int num_conexoes, int
num_pontos)
```

### Funcionamento:
1. Inicializa estruturas de controle
2. Em um loop:
 a. Para cada ponto, calcula quantas conexões não vigiadas ele cobre
 b. Seleciona o ponto com maior cobertura
 c. Atualiza conexões vigiadas
3. Retorna a solução

## Interface do Usuário (`main.c`)

Fluxo:
1. Exibe menu com opções
2. Carrega e processa o arquivo escolhido
3. Exibe resultado final
A função `processar_arquivo()` gerencia a leitura e chamada do algoritmo guloso.


## Exemplo de Saída no Terminal

### Entrada

Arquivo `n_6_m_8.txt`:

```
5 6
0 1
0 2
1 2
1 3
2 4
3 4

EOF
```

### Saída

```
Arquivo carregado: n_6_m_8.txt
Pontos: 6 | Conexoes: 8

Resultado:
Numero minimo de cameras: 3
Pontos para instalacao: 1 4 5
```

---

## Tecnologias Utilizadas

- Linguagem C.
- Biblioteca padrão (`math.h`, `stdio.h`, etc.).

---


## Contribuição

Sinta-se à vontade para contribuir com melhorias neste projeto. Sugestões, correções e ideias são bem-vindas!

---

## Licença

Este projeto é de uso livre para fins educacionais.

---

Feito por Diego Miqueias, Sarah Marques e Carlos Eduardo
