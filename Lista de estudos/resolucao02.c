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
 * Escreva uma função que faça comparação entre dois números inteiros (a e b)
 * e retorne:
 * 1: caso o número “a” seja maior;
 * -1: caso o número “b” seja maior;
 * 0: caso “a” e “b” sejam iguais.
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