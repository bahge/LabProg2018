/**
 * @file    index.c
 * @author  Leandro Costa Garcia
 * @data    06/fev/2019
 *
 * @brief   Resolução do exercício 06
 * 
 * Exercicio 06 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 * 
 * Exercicio 06 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Exercicio 06. If not, see https://www.gnu.org/licenses/.
 * 
 */
#include <stdio.h>
#include <stdbool.h>

void main(){
    // Variáveis
    bool transposta = true;
    int matrizA[3][3];
    int matrizB[3][3];
    int posicaoMatrizALinha, posicaoMatrizAColuna;
    int posicaoMatrizBLinha, posicaoMatrizBColuna;

    printf("Entre com os valores de matriz A:\n");

    for(posicaoMatrizALinha = 0; posicaoMatrizALinha < 3; posicaoMatrizALinha++)
    {
        for( posicaoMatrizAColuna = 0; posicaoMatrizAColuna < 3; posicaoMatrizAColuna++)
        {
            printf("Digite o valor da posição: A[%d][%d]:", posicaoMatrizALinha, posicaoMatrizAColuna);
            scanf("%d", &matrizA[posicaoMatrizALinha][posicaoMatrizAColuna]);
        }
        
    }
    
    printf("Entre com os valores de matriz B:\n");

    for(posicaoMatrizBLinha = 0; posicaoMatrizBLinha < 3; posicaoMatrizBLinha++)
    {
        for( posicaoMatrizBColuna = 0; posicaoMatrizBColuna < 3; posicaoMatrizBColuna++)
        {
            printf("Digite o valor da posição: B[%d][%d]:", posicaoMatrizBLinha, posicaoMatrizBColuna);
            scanf("%d", &matrizB[posicaoMatrizBLinha][posicaoMatrizBColuna]);
        }
        
    }
    
    for(posicaoMatrizALinha = 0; posicaoMatrizALinha < 3; posicaoMatrizALinha++)
    {
        for( posicaoMatrizBColuna = 0; posicaoMatrizBColuna < 3; posicaoMatrizBColuna++)
        {
            if( matrizA[posicaoMatrizALinha][posicaoMatrizBColuna] != matrizB[posicaoMatrizBColuna][posicaoMatrizALinha]) {
                
                transposta = false;
            }

        }
    }

    if (transposta != true) {
        printf("A matriz não é transposta.\n");
    } else {
        printf("A matriz é transposta.\n");
    }
}