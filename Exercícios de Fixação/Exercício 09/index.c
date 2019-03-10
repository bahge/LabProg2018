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

int checkNumber(int position){
	if (position == 30) {
		return 
	}
	
}

void main() {
	int position;
	int vmax;

	srand(time(0));

	vmax = 30;

	for(position = 1; position < 31; position++)
	{
		v[position] = numero(vmax);
	}
	
	for(position = 1; position < 31; position++)
	{
		printf("Valor de %d: %d \n", position, v[position]);
	}
	
}