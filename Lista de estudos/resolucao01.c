/**
 * @file    resolucao01.c
 * @author  Leandro Costa Garcia
 * @data    20/fev/2019
 *
 * @brief   Resolução do exercício 01, revisão para primeira prova
 * 
 * Resolução 01 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 * 
 * Resolução 01 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Resolução 01. If not, see https://www.gnu.org/licenses/.
 * 
 * Faça   um   algoritmo   que   receba   dois   valores   e   retorne 
 * todos   os   números   inteiros compreendidos entre eles. O algoritmo
 * deve estar preparado para o caso do primeiro número ser maior do que
 * o segundo e vice-versa.
 * 
 */
#include <stdio.h>


int main() {

    int num01, num02, ini, fim;

        printf("Digite o primeiro número: ");
        scanf("%d", &num01);
        printf("Digite o segundo número: ");
        scanf("%d", &num02);

        if ( num01 == num02 ) {
            printf("Os números são iguais!\n");
        }
        if ( num01 > num02 ) {
            fim = num01 + 1;
            for(ini = num02; ini < fim; ini++)
            {
                printf("%d \n", ini);
            }  
        }
        if ( num02 > num01 ) {
            fim = num01;
            for(ini = num02; ini >= fim; ini--)
            {
                printf("%d \n", ini);
            }  
        }
		return 0;
}