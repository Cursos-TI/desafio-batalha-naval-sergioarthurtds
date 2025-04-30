#include <stdio.h>

#define TAM 10
#define NAVIO 3

int main() {
    int tabuleiro[TAM][TAM];

    // Posições dos navios
    int linhaH = 1, colunaH = 1;
    int linhaV = 6, colunaV = 6;
    int linhaDiag1 = 4, colunaDiag1 = 0;      // ↘
    int linhaDiag2 = 0, colunaDiag2 = 9;      // ↙

    int i, j;

    // Inicializa tabuleiro com 0 (água)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Navio horizontal →
    if (colunaH + 3 <= TAM &&
        tabuleiro[linhaH][colunaH] == 0 &&
        tabuleiro[linhaH][colunaH + 1] == 0 &&
        tabuleiro[linhaH][colunaH + 2] == 0) {

        tabuleiro[linhaH][colunaH] = NAVIO;
        tabuleiro[linhaH][colunaH + 1] = NAVIO;
        tabuleiro[linhaH][colunaH + 2] = NAVIO;
    }

    // Navio vertical ↓
    if (linhaV + 3 <= TAM &&
        tabuleiro[linhaV][colunaV] == 0 &&
        tabuleiro[linhaV + 1][colunaV] == 0 &&
        tabuleiro[linhaV + 2][colunaV] == 0) {

        tabuleiro[linhaV][colunaV] = NAVIO;
        tabuleiro[linhaV + 1][colunaV] = NAVIO;
        tabuleiro[linhaV + 2][colunaV] = NAVIO;
    }

    // Diagonal ↘
    if (linhaDiag1 + 3 <= TAM && colunaDiag1 + 3 <= TAM &&
        tabuleiro[linhaDiag1][colunaDiag1] == 0 &&
        tabuleiro[linhaDiag1 + 1][colunaDiag1 + 1] == 0 &&
        tabuleiro[linhaDiag1 + 2][colunaDiag1 + 2] == 0) {

        tabuleiro[linhaDiag1][colunaDiag1] = NAVIO;
        tabuleiro[linhaDiag1 + 1][colunaDiag1 + 1] = NAVIO;
        tabuleiro[linhaDiag1 + 2][colunaDiag1 + 2] = NAVIO;
    }

    // Diagonal ↙
    if (linhaDiag2 + 3 <= TAM && colunaDiag2 - 2 >= 0 &&
        tabuleiro[linhaDiag2][colunaDiag2] == 0 &&
        tabuleiro[linhaDiag2 + 1][colunaDiag2 - 1] == 0 &&
        tabuleiro[linhaDiag2 + 2][colunaDiag2 - 2] == 0) {

        tabuleiro[linhaDiag2][colunaDiag2] = NAVIO;
        tabuleiro[linhaDiag2 + 1][colunaDiag2 - 1] = NAVIO;
        tabuleiro[linhaDiag2 + 2][colunaDiag2 - 2] = NAVIO;
    }

    // Cabeçalho com colunas A-J
    printf("    ");
    for (j = 0; j < TAM; j++) {
        printf(" %c", 'A' + j);
    }
    printf("\n");

    // Impressão do tabuleiro
    for (i = 0; i < TAM; i++) {
        printf("%2d |", i + 1);
        for (j = 0; j < TAM; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
