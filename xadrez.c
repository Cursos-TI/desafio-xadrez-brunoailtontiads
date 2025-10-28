#include <stdio.h>

// =========================================
// FUNÇÕES RECURSIVAS
// =========================================

// Função recursiva para movimentar a TORRE (movimento horizontal)
void moverTorre(int casa, int limite) {
    if (casa > limite) return; // condição de parada
    printf("Torre: Movendo para a %dª casa à direita\n", casa);
    moverTorre(casa + 1, limite); // chamada recursiva
}

// Função recursiva para movimentar a RAINHA (movimento para esquerda)
void moverRainha(int casa, int limite) {
    if (casa > limite) return;
    printf("Rainha: Movendo para a %dª casa à esquerda\n", casa);
    moverRainha(casa + 1, limite);
}

// Função recursiva para o BISPO com loops aninhados (movimento diagonal)
void moverBispo(int linha, int limiteVertical, int limiteHorizontal) {
    if (linha > limiteVertical) return; // condição de parada

    for (int coluna = 1; coluna <= limiteHorizontal; coluna++) {
        printf("Bispo: Movendo Diagonal - Linha %d / Coluna %d (Cima e Direita)\n", linha, coluna);
    }

    moverBispo(linha + 1, limiteVertical, limiteHorizontal); // chamada recursiva
}

// =========================================
// FUNÇÃO COM LOOPS COMPLEXOS (CAVALO)
// =========================================

void moverCavalo() {
    printf("\nMovimentos do Cavalo (em 'L'):\n");

    int movimentos = 0;

    for (int vertical = 1; vertical <= 2; vertical++) { // sobe 2 casas
        for (int horizontal = 1; horizontal <= 1; horizontal++) { // direita 1 casa
            movimentos++;
            printf("Cavalo: Movimento %d -> %d casas para cima e %d casa para a direita\n", movimentos, vertical, horizontal);

            if (vertical == 2 && horizontal == 1) {
                printf("Cavalo completou o movimento em L!\n");
                break; // encerra o movimento final
            }
        }
        if (movimentos >= 2) continue; // controla o fluxo
    }
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
        scanf("%d", &peca);

        printf("\n");

        switch (peca) {
            case 1:
                printf("=== MOVIMENTOS DA TORRE ===\n");
                moverTorre(1, 5);
                printf("\n");
                break;

            case 2:
                printf("=== MOVIMENTOS DO BISPO ===\n");
                moverBispo(1, 3, 3);
                printf("\n");
                break;

            case 3:
                printf("=== MOVIMENTOS DA RAINHA ===\n");
                moverRainha(1, 8);
                printf("\n");
                break;

            case 4:
                printf("=== MOVIMENTOS DO CAVALO ===\n");
                moverCavalo();
                printf("\n");
                break;

            case 5:
                printf("Saindo do jogo...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n\n");
        }

    } while (peca != 5);

    printf("\n=====================================\n");
    printf("      FIM DO JOGO DE XADREZ - NÍVEL FINAL\n");
    printf("=====================================\n");

    return 0;
}