/**
 * @file    resolucao02.c
 * @author  Leandro Costa Garcia
 * @data    20/fev/2019
 *
 * @brief   Resolução do exercício 02, revisão para primeira prova
 * 
 * Resolução 02 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 * 
 * Resolução 02 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Resolução 02. If not, see https://www.gnu.org/licenses/.
 * 
 * Faça   um   algoritmo   que   receba   dois   valores   e   retorne 
 * todos   os   números   inteiros compreendidos entre eles. O algoritmo
 * deve estar preparado para o caso do primeiro número ser maior do que
 * o segundo e vice-versa.
 * 
 */
#include <stdio.h>
#include "checkNumber.h"

void main() {
	int a;
	int b;
	int ret;
	printf("Insira um número inteiro: ");
	scanf("%d", &a);
	printf("Insira um número inteiro: ");
	scanf("%d", &b);

	ret = checkNumber(a, b);
	printf("O retorno é: %d", ret);

}