#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Cidades
// Tema 2 - Comparação das Cartas (Nível Mestre)

struct Carta {
    char codigo[10];
    char nome[50];
    char estado[3];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
};

// Funções auxiliares
float calcularDensidade(struct Carta c) {
    return c.populacao / c.area;
}

float calcularSuperPoder(struct Carta c) {
    return c.populacao + c.area + c.pib + c.pontos_turisticos + (1.0 / calcularDensidade(c));
}

// Menu de atributos
void mostrarMenuAtributos() {
    printf("\nEscolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - Super Poder\n");
}

// Comparação de atributos (com operador ternário)
int comparar(float valor1, float valor2, int menorVence) {
    return menorVence ? (valor1 < valor2 ? 1 : valor1 > valor2 ? 2 : 0)
                      : (valor1 > valor2 ? 1 : valor1 < valor2 ? 2 : 0);
}

int main() {
    struct Carta c1, c2;
    int escolha1, escolha2;
    float v1_a, v2_a, v1_b, v2_b;
    int vencedor1 = 0, vencedor2 = 0;

    // Cadastro das Cartas:
    printf("Digite os dados da Carta 1:\n");
    printf("Código: "); scanf(" %s", c1.codigo);
    printf("Nome: "); scanf(" %[^\n]", c1.nome);
    printf("Estado: "); scanf(" %s", c1.estado);
    printf("População: "); scanf("%lu", &c1.populacao);
    printf("Área: "); scanf("%f", &c1.area);
    printf("PIB: "); scanf("%f", &c1.pib);
    printf("Pontos Turísticos: "); scanf("%d", &c1.pontos_turisticos);

    printf("\nDigite os dados da Carta 2:\n");
    printf("Código: "); scanf(" %s", c2.codigo);
    printf("Nome: "); scanf(" %[^\n]", c2.nome);
    printf("Estado: "); scanf(" %s", c2.estado);
    printf("População: "); scanf("%lu", &c2.populacao);
    printf("Área: "); scanf("%f", &c2.area);
    printf("PIB: "); scanf("%f", &c2.pib);
    printf("Pontos Turísticos: "); scanf("%d", &c2.pontos_turisticos);

    // Menu para comparação
    mostrarMenuAtributos();
    printf("Escolha o primeiro atributo: ");
    scanf("%d", &escolha1);
    printf("Escolha o segundo atributo: ");
    scanf("%d", &escolha2);

    // Comparação do primeiro atributo
    switch (escolha1) {
        case 1: v1_a = c1.populacao; v2_a = c2.populacao; vencedor1 = comparar(v1_a, v2_a, 0); break;
        case 2: v1_a = c1.area; v2_a = c2.area; vencedor1 = comparar(v1_a, v2_a, 0); break;
        case 3: v1_a = c1.pib; v2_a = c2.pib; vencedor1 = comparar(v1_a, v2_a, 0); break;
        case 4: v1_a = c1.pontos_turisticos; v2_a = c2.pontos_turisticos; vencedor1 = comparar(v1_a, v2_a, 0); break;
        case 5: v1_a = calcularDensidade(c1); v2_a = calcularDensidade(c2); vencedor1 = comparar(v1_a, v2_a, 1); break;
        case 6: v1_a = calcularSuperPoder(c1); v2_a = calcularSuperPoder(c2); vencedor1 = comparar(v1_a, v2_a, 0); break;
        default: printf("Atributo inválido.\n");
    }

    // Comparação do segundo atributo
    switch (escolha2) {
        case 1: v1_b = c1.populacao; v2_b = c2.populacao; vencedor2 = comparar(v1_b, v2_b, 0); break;
        case 2: v1_b = c1.area; v2_b = c2.area; vencedor2 = comparar(v1_b, v2_b, 0); break;
        case 3: v1_b = c1.pib; v2_b = c2.pib; vencedor2 = comparar(v1_b, v2_b, 0); break;
        case 4: v1_b = c1.pontos_turisticos; v2_b = c2.pontos_turisticos; vencedor2 = comparar(v1_b, v2_b, 0); break;
        case 5: v1_b = calcularDensidade(c1); v2_b = calcularDensidade(c2); vencedor2 = comparar(v1_b, v2_b, 1); break;
        case 6: v1_b = calcularSuperPoder(c1); v2_b = calcularSuperPoder(c2); vencedor2 = comparar(v1_b, v2_b, 0); break;
        default: printf("Atributo inválido.\n");
    }

    // Exibição dos Resultados:
    printf("\nResultado:\n");
    if (vencedor1 == vencedor2) {
        if (vencedor1 == 1) {
            printf("A cidade vencedora é: %s (venceu nos dois atributos)\n", c1.nome);
        } else if (vencedor1 == 2) {
            printf("A cidade vencedora é: %s (venceu nos dois atributos)\n", c2.nome);
        } else {
            printf("Empate nos dois atributos!\n");
        }
    } else {
        printf("Empate técnico: cada cidade venceu em um atributo diferente.\n");
    }

    return 0;
}
