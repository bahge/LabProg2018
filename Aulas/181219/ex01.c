/*
* Nome: Leandro Costa Garcia
* RGA:
*
* Base do exercício ex01.md
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
	TProduto prod[3];
	char t_nome[120]; 
	int opcao = 0;
	int i, max = 0, min = 0;
	float maior = 0;
	float menor = 0;

	while(opcao == 0){
		printf("\n");
		printf("Selecione uma opção\n");
		printf("1 - Preencher produtos\n");
		printf("2 - Verificar valores\n");
		printf("9 - Sair\n");
		scanf("%i", &opcao);		
	
		if ( opcao == 1) {
			for(i = 0; i < 4; i++) {
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
			for(i = 0; i < 4; i++) {
				if(prod[i].valor > maior){
					maior = prod[i].valor;
					max = i;
				}
				if( (prod[i].valor < menor) || (menor == 0) ){
					menor = prod[i].valor;
					min = i;
				}
			}
			printf("Maior valor\nCódigo: %i, nome: %s, estoque: %i, valor: %.2f\n", prod[max].codigo, prod[max].nome, prod[max].estoque, prod[max].valor);
			printf("Menor valor\nCódigo: %i, nome: %s, estoque: %i, valor: %.2f\n", prod[min].codigo, prod[min].nome, prod[min].estoque, prod[min].valor);
			opcao = 0;
		} 
		if ( opcao == 9 ) {
			printf("Obrigado.\n");
		}
	}
	return 0;
}