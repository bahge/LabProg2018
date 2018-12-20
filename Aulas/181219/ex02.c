/*
* Nome: Leandro Costa Garcia
* RGA: 
*
* Base do exercício ex02.md
*/

#include <stdio.h>

int potencia(int a, int b) {
    int resultado, i;
    resultado = 1;
    for(i = 1; i < b + 1; i++) {
        resultado = resultado * a;
    }
    return resultado;    
}

void main() {
    int base, expoente, resultado;
    printf("Digite a base: \n");
    scanf("%i", &base);
    printf("Digite o expoente: \n");
    scanf("%i", &expoente);
    resultado = potencia(base, expoente);
    printf("Resultado: %i \n", resultado);
}