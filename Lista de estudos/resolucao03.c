/**
 * @file    resolucao03.c
 * @author  Leandro Costa Garcia
 * @data    20/fev/2019
 *
 * @brief   Resolução do exercício 03, revisão para primeira prova
 * 
 * Resolução 03 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 * 
 * Resolução 03 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Resolução 03. If not, see https://www.gnu.org/licenses/.
 *  
 * Faça um algoritmo que solicite ao usuário 20 números inteiros positivos 
 * e os armazene num vetor. Os números devem ser ordenados e colocado em outro 
 * vetor. Ao final, deve-se imprimir o vetor informado pelo usuário e o vetor ordenado. 
 * Importante: deve-se criar uma função/procedimento para fazer a ordenação. 
 * Importante: tente utilizar a função do exercício anterior.
 * 
 */
#include <stdio.h>
#include <stdbool.h>
#include "checkNumber.h"

int v[20];


void main() {
	int v2[20]; int aux;
	int vmin; int vmax; int pmax; int pmin;
	int position; int position_v2; int comp;
	int number01; int number02;
	bool change = false;
	
	for(position = 0; position < 20; position++)
	{
		printf("Insira um valor para a posição (%d)", position);
		scanf("%d", &v[position]);
	}

	for(position = 0; position < 20; position++)
	{
		v2[position] = -1;
	}

	pmax = 0;
	pmin = 0;
	vmax = v[pmax];
	vmin = v[pmin];
	for(position = 0; position < 20; position++)
	{
		aux = v[position];
		comp = checkNumber(aux, vmin);		
	}

	printf("Maior: %d - Menor: %d", vmax, vmin);
	
	
}