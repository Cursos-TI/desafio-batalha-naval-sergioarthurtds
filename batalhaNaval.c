#include <stdio.h>

#define TAM 10  // Tamanho do tabuleiro (10x10)
#define NAVIO 3 // Valor que representa o navio no tabuleiro

int main() {
    int tabuleiro[TAM][TAM];

    int linhaH = 2;    // Linha do navio horizontal (linha 3, pois começa do 0)
    int colunaH = 4;   // Coluna do navio horizontal (coluna 5)

    int linhaV = 5;    // Linha do navio vertical (linha 6)
    int colunaV = 1;   // Coluna do navio vertical (coluna 2)

    int i, j;

    // Inicializa o tabuleiro com água (0)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona navio horizontal, se houver espaço e sem sobreposição
    if (colunaH + 3 <= TAM &&
        tabuleiro[linhaH][colunaH] == 0 &&
        tabuleiro[linhaH][colunaH + 1] == 0 &&
        tabuleiro[linhaH][colunaH + 2] == 0) {
        
        tabuleiro[linhaH][colunaH] = NAVIO;
        tabuleiro[linhaH][colunaH + 1] = NAVIO;
        tabuleiro[linhaH][colunaH + 2] = NAVIO;
    }

    // Posiciona navio vertical, se houver espaço e sem sobreposição
    if (linhaV + 3 <= TAM &&
        tabuleiro[linhaV][colunaV] == 0 &&
        tabuleiro[linhaV + 1][colunaV] == 0 &&
        tabuleiro[linhaV + 2][colunaV] == 0) {
        
        tabuleiro[linhaV][colunaV] = NAVIO;
        tabuleiro[linhaV + 1][colunaV] = NAVIO;
        tabuleiro[linhaV + 2][colunaV] = NAVIO;
    }

    // Exibe os índices das colunas (A a J)
    printf("    ");
    for (j = 0; j < TAM; j++) {
        printf(" %c", 'A' + j);  // Converte 0→A, 1→B, etc.
    }
    printf("\n");

    // Exibe o tabuleiro com índice de linha (1 a 10)
    for (i = 0; i < TAM; i++) {
        printf("%2d |", i + 1);  // Mostra o número da linha
        for (j = 0; j < TAM; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
