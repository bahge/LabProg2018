#include <stdio.h>
/**
 * Vetores
 * 
 * Apresentando erros de memória apartir de um vetor
 * 
 * Escreva duas variáveis, receba uma sequencia de vetor e imprima posições antes e após o tamanho do vetor
 * 
**/

int main() {

    int d;
    int vetor[5];
    int f;
    int i;
    
    d = 100;
    for(i=0; i<5; i++)
    {
        printf("Pos %d: ", i + 1);
        scanf(" %d", &vetor[i]);
    }
    f = 200;

    printf("\n Vetor posição -1: %d \n", vetor[-1]);
    printf("\n Vetor posição 5: %d \n", vetor[5]);
    //Curiosidade
    printf("\n Vetor posição -2: %d \n", vetor[-2]);
    
    return 0;
}