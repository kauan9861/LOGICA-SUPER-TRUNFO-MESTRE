#include <stdio.h>

int main() {
    // Dados da Carta 1
    char nome1[30];
    unsigned long int pop1;
    float area1, pib1, densidade1;

    // Dados da Carta 2
    char nome2[30];
    unsigned long int pop2;
    float area2, pib2, densidade2;

    int escolha1, escolha2;
    float valor1_c1, valor1_c2;
    float valor2_c1, valor2_c2;

    printf("### SUPER TRUNFO DE PAÍSES ###\n");

    // Cadastro carta 1
    printf("\nDigite o nome do país da Carta 1: ");
    scanf(" %[^\n]", nome1);
    printf("População: ");
    scanf("%lu", &pop1);
    printf("Área: ");
    scanf("%f", &area1);
    printf("PIB: ");
    scanf("%f", &pib1);
    densidade1 = area1 != 0 ? (float)pop1 / area1 : 0;

    // Cadastro carta 2
    printf("\nDigite o nome do país da Carta 2: ");
    scanf(" %[^\n]", nome2);
    printf("População: ");
    scanf("%lu", &pop2);
    printf("Área: ");
    scanf("%f", &area2);
    printf("PIB: ");
    scanf("%f", &pib2);
    densidade2 = area2 != 0 ? (float)pop2 / area2 : 0;

    // Menu do primeiro atributo
    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Densidade Populacional\n");
    scanf("%d", &escolha1);

    // Menu do segundo atributo com verificação
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Densidade Populacional\n");
    scanf("%d", &escolha2);

    if (escolha1 == escolha2) {
        printf("Erro: você escolheu o mesmo atributo duas vezes.\nEncerrando o programa.\n");
        return 1;
    }

    // Pegar valores da primeira escolha
    switch (escolha1) {
        case 1:
            valor1_c1 = pop1;
            valor1_c2 = pop2;
            break;
        case 2:
            valor1_c1 = area1;
            valor1_c2 = area2;
            break;
        case 3:
            valor1_c1 = pib1;
            valor1_c2 = pib2;
            break;
        case 4:
            valor1_c1 = densidade1;
            valor1_c2 = densidade2;
            break;
        default:
            printf("Atributo inválido.\n");
            return 1;
    }

    // Pegar valores da segunda escolha
    switch (escolha2) {
        case 1:
            valor2_c1 = pop1;
            valor2_c2 = pop2;
            break;
        case 2:
            valor2_c1 = area1;
            valor2_c2 = area2;
            break;
        case 3:
            valor2_c1 = pib1;
            valor2_c2 = pib2;
            break;
        case 4:
            valor2_c1 = densidade1;
            valor2_c2 = densidade2;
            break;
        default:
            printf("Atributo inválido.\n");
            return 1;
    }

    // Comparar atributos
    int pontos1 = 0, pontos2 = 0;

    // Comparação do primeiro atributo
    if (escolha1 == 4) { // Densidade: menor vence
        if (valor1_c1 < valor1_c2) pontos1++;
        else if (valor1_c2 < valor1_c1) pontos2++;
    } else {
        if (valor1_c1 > valor1_c2) pontos1++;
        else if (valor1_c2 > valor1_c1) pontos2++;
    }

    // Comparação do segundo atributo
    if (escolha2 == 4) {
        if (valor2_c1 < valor2_c2) pontos1++;
        else if (valor2_c2 < valor2_c1) pontos2++;
    } else {
        if (valor2_c1 > valor2_c2) pontos1++;
        else if (valor2_c2 > valor2_c1) pontos2++;
    }

    // Soma dos atributos
    float soma1 = valor1_c1 + valor2_c1;
    float soma2 = valor1_c2 + valor2_c2;

    // Resultado
    printf("\n--- RESULTADO ---\n");
    printf("%s - Atributos: %.2f + %.2f = %.2f\n", nome1, valor1_c1, valor2_c1, soma1);
    printf("%s - Atributos: %.2f + %.2f = %.2f\n", nome2, valor1_c2, valor2_c2, soma2);

    if (soma1 > soma2) {
        printf("Vencedor: %s\n", nome1);
    } else if (soma2 > soma1) {
        printf("Vencedor: %s\n", nome2);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
