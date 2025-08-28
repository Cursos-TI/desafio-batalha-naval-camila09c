#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("  "); // Espaço para alinhar com as colunas
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Imprime os índices das colunas
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Imprime o índice da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para validar se o navio cabe no tabuleiro e não se sobrepõe
int validarPosicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') { // Navio horizontal
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            return 0; // Fora dos limites
        }
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != AGUA) {
                return 0; // Sobreposição
            }
        }
    } else if (orientacao == 'V') { // Navio vertical
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            return 0; // Fora dos limites
        }
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != AGUA) {
                return 0; // Sobreposição
            }
        }
    }
    return 1; // Posição válida
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') { // Navio horizontal
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    } else if (orientacao == 'V') { // Navio vertical
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}

int main() {
    // Declaração e inicialização do tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas dos navios (pre-definidas)
    int navio1_linha = 2;
    int navio1_coluna = 3;
    char navio1_orientacao = 'H'; // Horizontal

    int navio2_linha = 5;
    int navio2_coluna = 6;
    char navio2_orientacao = 'V'; // Vertical

    printf("Tabuleiro inicial (vazio):\n");
    exibirTabuleiro(tabuleiro);
    printf("\n");

    // Tenta posicionar o primeiro navio
    if (validarPosicao(tabuleiro, navio1_linha, navio1_coluna, navio1_orientacao)) {
        posicionarNavio(tabuleiro, navio1_linha, navio1_coluna, navio1_orientacao);
        printf("Navio 1 posicionado em (%d,%d) com sucesso.\n", navio1_linha, navio1_coluna);
    } else {
        printf("Nao foi possivel posicionar o Navio 1. Verifique os limites ou sobreposicao.\n");
    }

    // Tenta posicionar o segundo navio
    if (validarPosicao(tabuleiro, navio2_linha, navio2_coluna, navio2_orientacao)) {
        posicionarNavio(tabuleiro, navio2_linha, navio2_coluna, navio2_orientacao);
        printf("Navio 2 posicionado em (%d,%d) com sucesso.\n", navio2_linha, navio2_coluna);
    } else {
        printf("Nao foi possivel posicionar o Navio 2. Verifique os limites ou sobreposicao.\n");
    }

    printf("\nTabuleiro com navios posicionados:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
