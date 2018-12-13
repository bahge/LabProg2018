#include <stdio.h>
/**
 * Imprimindo o primeiro vetor
 * 
 * Apresentando o conceito de vetor
 * 
 * Faça um vetor de quatro elementos que receba inteiros e posteriormente os imprima
 * 
**/

int main() {

    int vetor[4];
    int soma;
    int i;
    
    for(i=0; i<4; i++)
    {
        printf("Pos %d: ", i + 1);
        scanf(" %d", &vetor[i]);
    }
    
    for(i=0; i<4; i++)
    {
        soma += vetor[i];
    }

    printf("Soma: %d\n",soma);

    return 0;
}