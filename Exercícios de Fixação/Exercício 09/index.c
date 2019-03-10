/**
 * @file    index.c
 * @author  Leandro Costa Garcia
 * @data    09/mar/2019
 *
 * @brief   Resolução do exercício 09
 * 
 * Exercicio 09 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 * 
 * Exercicio 09 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Exercicio 09. If not, see https://www.gnu.org/licenses/.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "numeroaleatorio.h"

int v[30];
int maior;

int checkNumber(int position){

    if ( position < 0 ) {
        return 0;
    } else {
        maior = checkNumber ( position - 1 );
        if ( v[position] > maior ){
            maior = v[position];
        }
        return maior;
    }
	
}

void main() {
	int position;
	int vmax = 30;
	int max_value;

	srand(time(0));

	for(position = 1; position < 31; position++)
	{
		v[position] = numero(vmax);
	}
	
	for(position = 1; position < 31; position++)
	{
		if ( ( position % 5) == 0 ) {
			printf("%d \n", v[position]);
		} else {
			printf("%d \t", v[position]);
		}
	}

	max_value = checkNumber(29);

	printf("Maior: %d\n", max_value);
	
}