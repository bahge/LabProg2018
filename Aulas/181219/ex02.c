/*
* Nome: Leandro Costa Garcia
* RGA: 
*
* Base do exercício ex02.md
*/

#include <stdio.h>

float potencia(int a, int b) {
    
    int i;
    float resultado = 1;

    if ( b < 0 ){
        for (i=b; i<0;i++){
            resultado = resultado / a;
        }
        if ( b % 2 != 0) {
            resultado = resultado * -1; 
        }
    } 
    else if (b > 0) {
        for (i=0; i<b; i++){
            resultado = resultado * a;
        }
    }
    
    return resultado;    
}

void main() {
    int base, expoente;
    float resultado;
    printf("Digite a base: \n");
    scanf("%i", &base);
    printf("Digite o expoente: \n");
    scanf("%i", &expoente);
    resultado = potencia(base, expoente);
    printf("Resultado: %.4f \n", resultado);
}