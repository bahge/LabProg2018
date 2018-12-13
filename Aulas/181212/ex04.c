#include <stdio.h>
/**
 * Vetores multimensionais
 * 
 * Executando array multidimensionais
 * 
 * Primeira parte
 * Tentar imprimir a matriz o mais parecido possível com uma matiz o.0
 * 
 * Segunda parte
 * Somatório de linhas
 * Somatório de colunas
 * 
**/

int matriz[3][3] = {                        
                        {1,2,3},{4,5,6},{7,8,9}
                    };
int main() {
    int i, j;
    int somarlinha[3] = {0,0,0};
    int somarcoluna[3] = {0,0,0};
    int somatotal = 0;
    printf("\n\n");
    for(i=0; i<3; i++)
    {     
        for(j=0; j<3; j++)
        {
            somarlinha[i] = somarlinha[i] + matriz[i][j];
            somarcoluna[j] = somarcoluna[j] + matriz[i][j];
            somatotal = somatotal + somarcoluna[i];
            if (j == 2) {
                printf(" %d  --> %d\n", matriz[i][j], somarlinha[i] );

            } else {
                printf(" %d |", matriz[i][j] );
            }
        }        
    }  
    for(i=0; i<3; i++)
    {
        if ( i == 2) {
            printf(" %d --> %d\n", somarcoluna[i], somatotal );
        } else {
            printf(" %d|", somarcoluna[i] );
        }
    }
    printf("\n\n");
    return 0;
}