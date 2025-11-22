#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição do número máximo de discos e torres
#define MAX_DISCOS 10
#define NUM_TORRES 3

// Representação das torres como um array de arrays de char.
// Cada torre é uma "pilha" de caracteres (os discos).
char torres[NUM_TORRES][MAX_DISCOS];
int topo[NUM_TORRES] = {0, 0, 0}; // O topo de cada pilha (quantidade de discos)

// --- Protótipos das Funções ---
void inicializar_torre(int N);
void mover_disco(int origem, int destino);
void desenhar_disco(int tamanho, int max_tamanho);
void exibir_tabuleiro();
void hanoi(int n, int origem, int destino, int auxiliar);
void mostra_jogada(int disco, int origem, int destino);
int calcular_potencia(int base, int expoente);
void modo_manual(int N_discos);
int validar_jogada(int origem, int destino);

// --- Funções Auxiliares ---

/**
 * @brief Calcula base elevado a expoente.
 * @param base Base da potenciação.
 * @param expoente Expoente da potenciação.
 * @return Resultado de base^expoente.
 */
int calcular_potencia(int base, int expoente) {
    int resultado = 1;
    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }
    return resultado;
}

// --- 1. Inicialização do Tabuleiro (Questão 3) ---

/**
 * @brief Inicializa a Torre 1 com N discos, representados por letras.
 * Discos maiores têm letras mais distantes de 'A'.
 * @param N Número de discos.
 */
void inicializar_torre(int N) {
    if (N > MAX_DISCOS || N <= 0) {
        printf("Erro: Numero de discos invalido (1 a %d).\n", MAX_DISCOS);
        exit(1);
    }
    
    // Inicializa a Torre 1 (índice 0)
    for (int i = 0; i < N; i++) {
        // Ex: Para N=4, i=0 (D), i=1 (C), i=2 (B), i=3 (A)
        // O disco maior é 'A' + (N - 1) = 'A' + 3 = 'D'
        torres[0][i] = 'A' + (N - 1) - i;
    }
    topo[0] = N; // A primeira torre tem N discos
}

/**
 * @brief Desenha um disco com tamanho visual proporcional.
 * @param tamanho Tamanho do disco (1 = menor, N = maior).
 * @param max_tamanho Tamanho máximo possível para centralizar.
 */
void desenhar_disco(int tamanho, int max_tamanho) {
    int espacos = (max_tamanho - tamanho) * 2; // Espaços para centralizar
    
    // Imprime espaços à esquerda
    for (int i = 0; i < espacos; i++) {
        printf(" ");
    }
    
    // Imprime o disco com asteriscos
    for (int i = 0; i < tamanho * 2; i++) {
        printf("*");
    }
    
    // Imprime espaços à direita (para simetria)
    for (int i = 0; i < espacos; i++) {
        printf(" ");
    }
    
    printf(" (%c)", 'A' + tamanho - 1); // Mostra também a letra
}

/**
 * @brief Exibe o estado atual do tabuleiro (Torres 1, 2 e 3) de forma visual.
 */
void exibir_tabuleiro() {
    printf("\n");
    
    // Encontra o número máximo de discos para determinar a altura visual
    int max_discos = 0;
    int tamanho_maximo = 0;
    
    for (int t = 0; t < NUM_TORRES; t++) {
        if (topo[t] > max_discos) max_discos = topo[t];
        for (int i = 0; i < topo[t]; i++) {
            int tamanho_disco = torres[t][i] - 'A' + 1;
            if (tamanho_disco > tamanho_maximo) tamanho_maximo = tamanho_disco;
        }
    }
    
    // Se não há discos, usa um tamanho mínimo
    if (tamanho_maximo == 0) tamanho_maximo = MAX_DISCOS;
    
    // Desenha linha por linha, de cima para baixo
    for (int nivel = max_discos - 1; nivel >= 0; nivel--) {
        for (int t = 0; t < NUM_TORRES; t++) {
            printf("  "); // Espaçamento entre torres
            
            if (nivel < topo[t]) {
                // Há um disco neste nível
                int tamanho_disco = torres[t][nivel] - 'A' + 1;
                desenhar_disco(tamanho_disco, tamanho_maximo);
            } else {
                // Nível vazio - desenha apenas a haste central
                int espacos_totais = tamanho_maximo * 4 + 3; // Largura total de um disco máximo
                for (int i = 0; i < espacos_totais / 2; i++) printf(" ");
                printf("|");
                for (int i = 0; i < espacos_totais / 2; i++) printf(" ");
            }
            
            printf("    "); // Espaçamento extra entre torres
        }
        printf("\n");
    }
    
    // Desenha a base das torres
    for (int t = 0; t < NUM_TORRES; t++) {
        printf("  ");
        for (int i = 0; i < tamanho_maximo * 4 + 3; i++) {
            printf("=");
        }
        printf("    ");
    }
    printf("\n");
    
    // Numera as torres
    for (int t = 0; t < NUM_TORRES; t++) {
        printf("  ");
        int espacos = (tamanho_maximo * 4 + 3) / 2;
        for (int i = 0; i < espacos; i++) printf(" ");
        printf("%d", t + 1);
        for (int i = 0; i < espacos; i++) printf(" ");
        printf("    ");
    }
    printf("\n");
    printf("Torre:    1");
    for (int i = 0; i < tamanho_maximo * 4 + 3; i++) printf(" ");
    printf("    2");
    for (int i = 0; i < tamanho_maximo * 4 + 3; i++) printf(" ");
    printf("    3\n");
    printf("\n");
}


// --- Funções Auxiliares de Jogada ---

/**
 * @brief Valida se uma jogada é possível.
 * @param origem Torre de origem (1, 2 ou 3).
 * @param destino Torre de destino (1, 2 ou 3).
 * @return 1 se a jogada é válida, 0 caso contrário.
 */
int validar_jogada(int origem, int destino) {
    if (origem < 1 || origem > 3 || destino < 1 || destino > 3) {
        printf("Erro: Torres devem ser 1, 2 ou 3.\n");
        return 0;
    }
    
    if (origem == destino) {
        printf("Erro: Torre de origem e destino devem ser diferentes.\n");
        return 0;
    }
    
    int idx_origem = origem - 1;
    int idx_destino = destino - 1;
    
    if (topo[idx_origem] == 0) {
        printf("Erro: Torre %d esta vazia.\n", origem);
        return 0;
    }
    
    if (topo[idx_destino] > 0) {
        char disco_origem = torres[idx_origem][topo[idx_origem] - 1];
        char disco_destino = torres[idx_destino][topo[idx_destino] - 1];
        
        if (disco_origem > disco_destino) {
            printf("Erro: Nao pode colocar disco maior (%c) sobre disco menor (%c).\n", disco_origem, disco_destino);
            return 0;
        }
    }
    
    return 1;
}

/**
 * @brief Move o disco do topo da torre de origem para a de destino.
 * Assume que a jogada é legal (disco menor sobre maior).
 */
void mover_disco(int origem, int destino) {
    // origem e destino sao indices 1, 2, 3, mas o array usa 0, 1, 2
    int idx_origem = origem - 1;
    int idx_destino = destino - 1;

    // 1. Pega o disco do topo da origem
    char disco = torres[idx_origem][topo[idx_origem] - 1];

    // 2. Coloca o disco no topo do destino
    torres[idx_destino][topo[idx_destino]] = disco;

    // 3. Atualiza os topos
    topo[idx_origem]--;
    topo[idx_destino]++;
}

/**
 * @brief Exibe a jogada e pausa (Questão 4, parte 'mostra_jogada').
 */
void mostra_jogada(int disco_tamanho, int origem, int destino) {
    // Converte o tamanho do disco (ex: 4 para D, 1 para A) para a letra
    char disco_letra = 'A' + disco_tamanho - 1;
    
    printf("\n");
    printf("+======================================+\n");
    printf("|  JOGADA: Mover DISCO %c (tamanho %d)  |\n", disco_letra, disco_tamanho);
    printf("|  Da Torre %d  ->  Para Torre %d        |\n", origem, destino);
    printf("+======================================+\n");
    
    // Realiza a movimentação no tabuleiro
    mover_disco(origem, destino);
    
    // Imprime a nova situacao do jogo
    exibir_tabuleiro();
    
    // Pausa (Dica: Use um scanf para pausar cada jogada.)
    printf("Pressione ENTER para a proxima jogada...");
    // Consome o '\n' pendente (se houver) e espera por outro ENTER
    while (getchar() != '\n');
    getchar(); 
}


// --- 2. Modo Manual de Jogo ---

/**
 * @brief Permite ao jogador jogar manualmente.
 * @param N_discos Número de discos no jogo.
 */
void modo_manual(int N_discos) {
    int origem, destino;
    int movimentos = 0;
    int minimo_movimentos = calcular_potencia(2, N_discos) - 1;
    
    printf("\n+==========================================+\n");
    printf("|            MODO MANUAL ATIVO             |\n");
    printf("|                                          |\n");
    printf("| Instrucoes:                              |\n");
    printf("| - Digite 0 0 para sair                   |\n");
    printf("| - Movimentos minimos necessarios: %d     |\n", minimo_movimentos);
    printf("+==========================================+\n");
    
    while (1) {
        // Verifica se o jogador venceu
        if (topo[2] == N_discos) {
            printf("\n");
            printf("+============================================+\n");
            printf("|             PARABENS!                      |\n");
            printf("|                                            |\n");
            printf("|   Voce resolveu as Torres de Hanoi!       |\n");
            printf("|     Seus movimentos: %d                    |\n", movimentos);
            printf("|     Minimo possivel: %d                    |\n", minimo_movimentos);
            if (movimentos == minimo_movimentos) {
                printf("|     PERFEITO! Voce fez o minimo!          |\n");
            } else {
                printf("|     Tente novamente para fazer o minimo!  |\n");
            }
            printf("+============================================+\n");
            break;
        }
        
        printf("\nMovimento %d - Digite origem e destino (ex: 1 3): ", movimentos + 1);
        
        if (scanf("%d %d", &origem, &destino) != 2) {
            printf("Entrada invalida. Tente novamente.\n");
            while (getchar() != '\n'); // Limpa o buffer
            continue;
        }
        
        // Opção de sair
        if (origem == 0 && destino == 0) {
            printf("Jogo interrompido pelo jogador.\n");
            break;
        }
        
        // Valida e executa a jogada
        if (validar_jogada(origem, destino)) {
            mover_disco(origem, destino);
            movimentos++;
            
            printf("\nMovimento %d executado: Torre %d -> Torre %d\n", movimentos, origem, destino);
            exibir_tabuleiro();
        }
    }
}

// --- 3. Algoritmo Recursivo de Resolução (Questão 4) ---

/**
 * @brief Algoritmo recursivo para resolver as Torres de Hanoi.
 * @param n Número de discos a serem movidos.
 * @param origem Torre de origem (1, 2 ou 3).
 * @param destino Torre de destino (1, 2 ou 3).
 * @param auxiliar Torre auxiliar (1, 2 ou 3).
 */
void hanoi(int n, int origem, int destino, int auxiliar) {
    // CASO BASE: Se houver apenas 1 disco, mova-o diretamente.
    if (n == 1) {
        mostra_jogada(n, origem, destino);
        return;
    }
    
    // 1. Mova n-1 discos da Origem para a Auxiliar, usando o Destino como auxiliar.
    hanoi(n - 1, origem, auxiliar, destino);

    // 2. Mova o maior disco (n) da Origem para o Destino.
    mostra_jogada(n, origem, destino);

    // 3. Mova os n-1 discos da Auxiliar para o Destino, usando a Origem como auxiliar.
    hanoi(n - 1, auxiliar, destino, origem);
}


// --- Função Principal ---

int main() {
    int N_discos, modo;
    
    printf("\n");
    printf("+============================================+\n");
    printf("|        SIMULADOR TORRES DE HANOI          |\n");
    printf("|                                            |\n");
    printf("|  Objetivo: Mover todos os discos da Torre 1|\n");
    printf("|  para a Torre 3, seguindo as regras:      |\n");
    printf("|  - Apenas um disco por vez                 |\n");
    printf("|  - Disco maior nunca sobre disco menor     |\n");
    printf("+============================================+\n");
    printf("\n");
    printf("Quantos discos (N) deseja usar (max %d)? ", MAX_DISCOS);
    
    // Leitura e validacao
    if (scanf("%d", &N_discos) != 1 || N_discos <= 0 || N_discos > MAX_DISCOS) {
        printf("Entrada invalida. Usando N=4 por padrao.\n");
        N_discos = 4;
    }
    
    printf("\nEscolha o modo de jogo:\n");
    printf("1 - Resolucao automatica\n");
    printf("2 - Jogar manualmente\n");
    printf("Sua escolha: ");
    
    if (scanf("%d", &modo) != 1 || (modo != 1 && modo != 2)) {
        printf("Opcao invalida. Usando resolucao automatica.\n");
        modo = 1;
    }
    
    // Consome o '\n' que sobrou do scanf
    while (getchar() != '\n'); 
    
    // 1. Inicializa o tabuleiro (Questao 3)
    inicializar_torre(N_discos);
    int minimo_movimentos = calcular_potencia(2, N_discos) - 1;
    
    printf("\nTabuleiro inicializado com %d discos!\n", N_discos);
    printf("Legenda: Discos sao mostrados com * (maior = mais *)\n");
    printf("A=menor disco, %c=maior disco\n", 'A' + N_discos - 1);
    printf("Numero minimo de movimentos necessarios: %d\n", minimo_movimentos);
    exibir_tabuleiro();
    
    if (modo == 1) {
        // 2. Resolve o problema automaticamente
        printf("\nIniciando a resolucao automatica...\n");
        printf("Pressione ENTER para comecar...");
        getchar();

        // Chama a funcao recursiva: mover N_discos da Torre 1 para a Torre 3, usando a Torre 2
        hanoi(N_discos, 1, 3, 2);
        
        printf("\n");
        printf("+============================================+\n");
        printf("|             PARABENS!                      |\n");
        printf("|                                            |\n");
        printf("|   Voce resolveu as Torres de Hanoi!       |\n");
        printf("|     Total de movimentos: %d                |\n", minimo_movimentos);
        printf("|     (Numero minimo possivel: %d)           |\n", minimo_movimentos);
        printf("+============================================+\n");
    } else {
        // 3. Modo manual
        modo_manual(N_discos);
    } 

    return 0;
}