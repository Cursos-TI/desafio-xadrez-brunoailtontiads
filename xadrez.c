#include <stdio.h>

// =========================================
// FUNÇÕES RECURSIVAS
// =========================================

// Torre (movimento horizontal para direita)
void moverTorre(int casa, int limite) {
    if (casa > limite) return;
    printf("Torre: Movendo para a %dª casa à direita\n", casa);
    moverTorre(casa + 1, limite);
}

// Rainha (movimento para esquerda)
void moverRainha(int casa, int limite) {
    if (casa < limite) return;
    printf("Rainha: Movendo para a %dª casa à esquerda\n", casa);
    moverRainha(casa - 1, limite);
}

// Bispo (movimento diagonal)
void moverBispo(int linha, int limiteVertical, int limiteHorizontal) {
    if (linha > limiteVertical) return;

    for (int coluna = 1; coluna <= limiteHorizontal; coluna++) {
        printf("Bispo: Movendo Diagonal - Linha %d / Coluna %d (Cima e Direita)\n",
               linha, coluna);
    }

    moverBispo(linha + 1, limiteVertical, limiteHorizontal);
}

// Cavalo (movimento em L)
void moverCavalo() {
    printf("\nMovimentos do Cavalo (em 'L'):\n");
    printf("Cavalo: 2 casas para cima e 1 casa para a direita\n");
    printf("Cavalo completou o movimento em L!\n");
}

// =========================================
// PROGRAMA PRINCIPAL
// =========================================

int main() {
    int peca;

    printf("=====================================\n");
    printf("        JOGO DE XADREZ - NÍVEL FINAL\n");
    printf("=====================================\n\n");

    do {
        printf("Escolha uma peça para movimentar:\n");
        printf("1 - Torre\n");
        printf("2 - Bispo\n");
        printf("3 - Rainha\n");
        printf("4 - Cavalo\n");
        printf("5 - Sair do jogo\n");
        printf("Opção: ");

        if (scanf("%d", &peca) != 1) {
            printf("Entrada inválida! Tente novamente.\n\n");
            while (getchar() != '\n');
            continue;
        }

        printf("\n");

        switch (peca) {
            case 1:
                printf("=== MOVIMENTOS DA TORRE ===\n");
                moverTorre(1, 5);
                break;

            case 2:
                printf("=== MOVIMENTOS DO BISPO ===\n");
                moverBispo(1, 3, 3);
                break;

            case 3:
                printf("=== MOVIMENTOS DA RAINHA ===\n");
                moverRainha(8, 1);
                break;

            case 4:
                printf("=== MOVIMENTOS DO CAVALO ===\n");
                moverCavalo();
                break;

            case 5:
                printf("Saindo do jogo...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }

        printf("\n");

    } while (peca != 5);

    printf("=====================================\n");
    printf("      FIM DO JOGO DE XADREZ - NÍVEL FINAL\n");
    printf("=====================================\n");

    return 0;
}
