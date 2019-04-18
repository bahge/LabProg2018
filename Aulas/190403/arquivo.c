#include <stdio.h>

int main () {

    FILE *arq;
    FILE *arq_copia; 
    char aux;

    arq = fopen("lorem_ipsum.txt", "r");
    arq_copia = fopen ("lorem_copia.txt", "r");

    if ( arq_copia == NULL ) {
        printf("Arquivo de copia criado.\n");
        arq_copia = fopen ("lorem_copia.txt", "w"); 
    }
    else {
        printf("Arquivo de copia aberto para nova insercao.\n");
        arq_copia = fopen ("lorem_copia.txt", "a");
    }
    
    int count_linhas = 0;
    
    printf("Arquivo aberto para leitura.\n ---   ---   ---   ---   ---   ---   ---   ---   ---   --- \n");
    
    while (fscanf(arq, "%c", &aux) != EOF) {
        printf("%c", aux);
        if (aux == '\n') {
            count_linhas++;
        }
        fprintf(arq_copia,"%c", aux); 
    }

    fclose(arq);
    fprintf(arq_copia,"%c", '\n');
    fclose(arq_copia);

    printf("\n ---   ---   ---   ---   ---   ---   ---   ---   ---   --- \n");
    printf("\n Linhas: %d \n", count_linhas);
    printf("\n ---   ---   ---   ---   ---   ---   ---   ---   ---   --- \n");
    
    return(0);
}