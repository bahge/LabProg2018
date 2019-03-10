/**
 * @file    index.c
 * @author  Leandro Costa Garcia
 * @data    09/mar/2019
 *
 * @brief   Resolução do exercício 08
 * 
 * Exercicio 08 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 * 
 * Exercicio 08 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Exercicio 08. If not, see https://www.gnu.org/licenses/.
 * 
 */
#include <stdio.h>

int checkNumber(int a, int b){
	if (a > b) {
		return 1;
	}
	if (b > a) {
		return -1;
	}
	if (a == b) {
		return 0;
	}
}

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