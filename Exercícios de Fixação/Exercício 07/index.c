/**
 * @file    index.c
 * @author  Leandro Costa Garcia
 * @data    06/fev/2019
 *
 * @brief   Resolução do exercício 07
 * 
 * Exercicio 07 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 * 
 * Exercicio 07 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Exercicio 07. If not, see https://www.gnu.org/licenses/.
 * 
 */
#include <stdio.h>
#include <string.h>

typedef struct TProduto {
	int codigo;
	char nome[120];
	int estoque;
	float valor;
} TProduto;

int main() {
	TProduto prod[4];
	char t_nome[120]; 
	int opcao = 0;
	int i, max = 0, min = 0, itensZerados = 0;
	float maior = 0;
	float menor = 0;

	while(opcao == 0){
		printf("\n");
		printf("Selecione uma opção\n");
		printf("1 - Inserir produtos\n");
		printf("2 - Procurar produto de maior valor\n");
        printf("3 - Procurar produto de menor valor\n");
        printf("4 - Procurar produtos com estoque zerado\n");
		printf("9 - Sair\n");
		scanf("%i", &opcao);		
	
		if ( opcao == 1) {
			for(i = 0; i < 5; i++) {
				printf("Insira um código\n");
				scanf("%i", &prod[i].codigo);
				printf("Insira um nome\n");
				scanf("%s", &t_nome);
				strcpy(prod[i].nome, t_nome);
				printf("Insira o valor do estoque\n");
				scanf("%i", &prod[i].estoque);
				printf("Insira o valor do produto\n");
				scanf("%f", &prod[i].valor);
				opcao = 0;
			}
		}
		if ( opcao == 2 ) {
			for(i = 0; i < 5; i++) {
				if( (prod[i].valor > maior) && (prod[i].estoque > 0) ){
					maior = prod[i].valor;
					max = i;
				}
			}
			printf("Maior valor\nCódigo: %i, nome: %s, estoque: %i, valor: %.2f\n", prod[max].codigo, prod[max].nome, prod[max].estoque, prod[max].valor);
			opcao = 0;
		}
        if ( opcao == 3 ) {
			for(i = 0; i < 5; i++) {
				if( ( (prod[i].valor < menor) || (menor == 0) ) && (prod[i].estoque > 0) ) {
					menor = prod[i].valor;
					min = i;
				}
			}
			printf("Menor valor\nCódigo: %i, nome: %s, estoque: %i, valor: %.2f\n", prod[min].codigo, prod[min].nome, prod[min].estoque, prod[min].valor);
			opcao = 0;
		}
        if ( opcao == 4 ) {
			for(i = 0; i < 5; i++) {
				if( (prod[i].estoque == 0) ){
					printf("O produto %s, está zerado no estoque\n", prod[i].nome);
                    itensZerados = itensZerados + 1;
				}
			}
            if ( itensZerados == 0 ) {
                    printf("Todos itens possue saldo!\n");
            }
			opcao = 0;
		}  
		if ( opcao == 9 ) {
			printf("Obrigado.\n");
		}
	}
	return 0;
}