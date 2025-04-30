#include <stdio.h>
#include <stdlib.h>  // Para usar a função abs()

// Definindo o tamanho do tabuleiro e das habilidades
#define TAMANHO 10      // Tamanho do tabuleiro (10x10)
#define TAM_HAB 5       // Tamanho das habilidades (5x5)

#define AGUA 0
#define NAVIO 3
#define EFEITO 5

// Função para preencher todo o tabuleiro com água (valor 0)
void iniciarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para mostrar o tabuleiro no terminal
void mostrarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("    ");
    for (int j = 0; j < TAMANHO; j++) {
        printf(" %c", 'A' + j);  // Letras A até J nas colunas
    }
    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d |", i + 1);  // Números 1 até 10 nas linhas
        for (int j = 0; j < TAMANHO; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para colocar navios no tabuleiro
void colocarNavios(int tabuleiro[TAMANHO][TAMANHO]) {
    // Navio na horizontal (linha 2, colunas 2 a 4)
    tabuleiro[1][1] = NAVIO;
    tabuleiro[1][2] = NAVIO;
    tabuleiro[1][3] = NAVIO;

    // Navio na vertical (coluna 7, linhas 7 a 9)
    tabuleiro[6][6] = NAVIO;
    tabuleiro[7][6] = NAVIO;
    tabuleiro[8][6] = NAVIO;

    // Navio em diagonal ↘ (de cima para baixo e esquerda para direita)
    tabuleiro[4][0] = NAVIO;
    tabuleiro[5][1] = NAVIO;
    tabuleiro[6][2] = NAVIO;

    // Navio em diagonal ↙ (de cima para baixo e direita para esquerda)
    tabuleiro[0][9] = NAVIO;
    tabuleiro[1][8] = NAVIO;
    tabuleiro[2][7] = NAVIO;
}

// Função para criar habilidade em forma de cone (aponta para baixo)
void criarCone(int cone[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i >= j - 2 && i >= 2 - j) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }
}

// Função para criar habilidade em forma de cruz
void criarCruz(int cruz[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
}

// Função para criar habilidade em forma de octaedro (losango)
void criarOctaedro(int losango[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                losango[i][j] = 1;
            } else {
                losango[i][j] = 0;
            }
        }
    }
}

// Função para aplicar o efeito da habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int habilidade[TAM_HAB][TAM_HAB], int linhaCentro, int colunaCentro) {
    int deslocamento = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int linha = linhaCentro - deslocamento + i;
            int coluna = colunaCentro - deslocamento + j;

            // Só aplica se estiver dentro do tabuleiro
            if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO) {
                // Se for área de habilidade (1) e não tiver navio
                if (habilidade[i][j] == 1 && tabuleiro[linha][coluna] != NAVIO) {
                    tabuleiro[linha][coluna] = EFEITO;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    // Começa preenchendo o tabuleiro com água
    iniciarTabuleiro(tabuleiro);

    // Coloca os navios no tabuleiro
    colocarNavios(tabuleiro);

    // Cria as formas das habilidades
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(octaedro);

    // Aplica as habilidades no tabuleiro em pontos diferentes
    aplicarHabilidade(tabuleiro, cone, 2, 2);        // Cone no ponto (3, C)
    aplicarHabilidade(tabuleiro, cruz, 5, 5);        // Cruz no ponto (6, F)
    aplicarHabilidade(tabuleiro, octaedro, 7, 8);    // Octaedro no ponto (8, I)

    // Mostra o tabuleiro final
    mostrarTabuleiro(tabuleiro);

    return 0;
}
