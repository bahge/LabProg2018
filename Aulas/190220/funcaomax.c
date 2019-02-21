#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "numeroaleatorio.h"

int vetor[30];

int MaxNum(int tamVet){
    int maior;
    if ( tamVet < 0 ) {
        return 0;
    } else {
        maior = MaxNum ( tamVet - 1 );
        if ( vetor[tamVet] > maior ){
            maior = vetor[tamVet];
        }
        return maior;
    }
}

void main(){
    int posVetor;
    int numMaxSorteado = 50;
    int valor;

    for(posVetor = 0; posVetor < 30; posVetor++)
    {
        vetor[posVetor] = inumAlet(numMaxSorteado);
    }

    valor = MaxNum(29);
    
    for(posVetor = 0; posVetor < 30; posVetor++)
    {
        printf("%d: %d\n", posVetor, vetor[posVetor]);
    }

    printf("Maior: %d\n", valor);
    
}