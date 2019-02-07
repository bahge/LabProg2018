/**
 * @file    index.c
 * @author  Leandro Costa Garcia
 * @data    06/fev/2019
 *
 * @brief   Resolução do exercício 05
 * 
 * Exercicio 05 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 * 
 * Exercicio 05 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Exercicio 05. If not, see https://www.gnu.org/licenses/.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "numeroaleatorio.h"

void main(){
    // Variáveis
    int vetor[15];
    int posicao, vmin, vmax, pmin, pmax, valor_maximo;

    printf("Entre com o maior valor para sorteio: ");
    scanf(" %d", &valor_maximo);
    vmin = valor_maximo + 1;
    vmax = 0;

    srand(time(0));

    for (posicao = 0; posicao <15; posicao++) {
        vetor[posicao] = numero(vmin);
    }

    for (posicao = 0; posicao <15; posicao++) {
        if (vetor[posicao] > vmax) {
            vmax = vetor[posicao];
            pmax = posicao + 1;
        }
        if (vetor[posicao] < vmin) {
            vmin = vetor[posicao];
            pmin = posicao + 1;
        }
    }
    printf("Máximo: %d \t Posição: %d\n", vmax, pmax);
    printf("Mínimo: %d \t Posição: %d\n", vmin, pmin);
}