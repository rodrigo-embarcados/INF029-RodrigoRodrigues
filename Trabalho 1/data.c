#include <stdio.h>

// Função para verificar se o ano é bissexto
int ehBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

// Função para validar a data
int dataValida(int dia, int mes, int ano) {
    if (ano < 1 || mes < 1 || mes > 12 || dia < 1) return 0;

    int diasNoMes;

    switch (mes) {
        case 2:
            diasNoMes = ehBissexto(ano) ? 29 : 28;
            break;
        case 4: case 6: case 9: case 11:
            diasNoMes = 30;
            break;
        default:
            diasNoMes = 31;
    }

    return dia <= diasNoMes;
}

int main() {
    int dia, mes, ano;

    printf("Digite uma data no formato dd/mm/aaaa: ");
    if (scanf("%d/%d/%d", &dia, &mes, &ano) != 3) {
        printf("Formato inválido.\n");
        return 1;
    }

    if (dataValida(dia, mes, ano)) {
        printf("Data válida: %02d/%02d/%04d\n", dia, mes, ano);
    } else {
        printf("Data inválida.\n");
    }

    return 0;
}