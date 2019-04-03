/*
 * exercicio01.c
 * --------------------------------------------------------------------
 * Nomes: 	| Leandro Costa Garcia 		  |	Fabio Cançado
 * --------------------------------------------------------------------
 * 
 * 
 * QUESTÃO 1. (5,0pts) Um jovem estudante de Sistemas de Informação 
 * resolveu criar um sistema em linguagem C para a revenda de carros 
 * usados da família, como forma de praticar o que vinha aprendendo. 
 * Ele fez o levantamento e planejamento inicial do sistema e pensou 
 * nos seguintes requisitos:
 *	• Criar uma estrutura do tipo registro chamada T_CARRO com no mínimo
 *  os seguintes dados:
 *		◦ Nome do carro
 *		◦ Marca/fabricante
 *		◦ Ano do carro
 *		◦ Valor de compra
 *		◦ Valor de revenda
 * Ao ser cadastrado, deve-se contabilizar a porcentagem de lucro do 
 * carro.
 * O sistema deve ter ainda um menu com as seguintes opções:
 * 1. Cadastrar carro
 * 2. Listar todos os carros cadastrados (listador todos os dados, 
 * inclusive o lucro);
 * 3. Listar carro mais antigo (listador todos os dados, inclusive 
 * o lucro);
 * 4. Listar carro com maior porcentagem de lucro (listador todos os 
 * dados, inclusive o lucro)
 * Importante:
 *		• Implemente uma função/procedimento para cada item do menu;
 *		• Deve ser criado um vetor do tipo T_CARRO que receba até 
 * 		  100 itens.
 * 
 */


#include <stdio.h>
#include <string.h>

typedef struct Carro {
  char nome[50];
  char marca[30];
  int ano;
  float vCompra;
  float vRevenda;    
  float lucro;
} Carro;

  int posicao = 0;
  Carro cadastro[100];
  int opcao;

void cadastrar(int posicao) {
	char Tnome[50];
	char Tmarca[30];
	
	printf("Digite o nome do carro:");
	scanf ("%s", Tnome);
    strcpy (cadastro[posicao].nome, Tnome);
	printf("Digite a marca:");
	scanf ("%s", Tmarca);
    strcpy (cadastro[posicao].marca, Tmarca);
    printf("Digite o ano do veículo:");
	scanf ("%d", &cadastro[posicao].ano);
	printf("Digite o valor de compra:");
	scanf ("%f", &cadastro[posicao].vCompra);
	printf("Digite posicao = posicao + 1;o valor de revenda:");
	scanf ("%f", &cadastro[posicao].vRevenda);
	cadastro[posicao].lucro =  ( ( ( cadastro[posicao].vRevenda - cadastro[posicao].vCompra ) / cadastro[posicao].vCompra ) * 100 );
	
	printf("Nome: \t%s \nMarca: \t%s \nAno: \t%d \nCompra: \tR$ %10.2f \nRevenda: \tR$ %10.2f \nLucro: \t%10.2f %\n", cadastro[posicao].nome, cadastro[posicao].marca, cadastro[posicao].ano, cadastro[posicao].vCompra, cadastro[posicao].vRevenda, cadastro[posicao].lucro);
	printf("=-------------------------------------------------------=\n");
	printf("");
}

void listar_todos() {
	int i;
	for (i = 0; i < posicao; i++)
	{
			printf("Nome: \t%s \nMarca: \t%s \nAno: \t%d \nCompra: \tR$ %10.2f \nRevenda: \tR$ %10.2f \nLucro: \t%10.2f %\n\n", cadastro[i].nome, cadastro[i].marca, cadastro[i].ano, cadastro[i].vCompra, cadastro[i].vRevenda, cadastro[i].lucro);
			printf("===========================================================\n");
	}
}

void listar_mais_experiente() {
	int i;
	int posicao_experiente;
	int mais_experiente;
	
	posicao_experiente = 0;
	mais_experiente = cadastro[posicao_experiente].ano;
	
	for (i = 0; i < posicao; i++)
	{
		if ( cadastro[i].ano < mais_experiente ) {
			posicao_experiente = i;
			mais_experiente = cadastro[posicao_experiente].ano;
		}
	}
	printf("=========================================================\n");
	printf("= O carro mais experiente é: 						    =\n");
	printf("=-------------------------------------------------------=\n");
	printf("Nome: \t%s \nMarca: \t%s \nAno: \t%d \nCompra: \tR$ %10.2f \nRevenda: \tR$ %10.2f \nLucro: \t%10.2f %\n\n", cadastro[posicao_experiente].nome, cadastro[posicao_experiente].marca, cadastro[posicao_experiente].ano, cadastro[posicao_experiente].vCompra, cadastro[posicao_experiente].vRevenda, cadastro[posicao_experiente].lucro);
	printf("=========================================================\n");
}

void listar_mais_vantajoso() {
	int i;
	int posicao_vantajoso;
	int mais_vantajoso;
	
	posicao_vantajoso = 0;
	mais_vantajoso = cadastro[posicao_vantajoso].lucro;
	
	for (i = 0; i < posicao; i++)
	{
		if ( cadastro[i].lucro > mais_vantajoso ) {
			posicao_vantajoso = i;
			mais_vantajoso = cadastro[posicao_vantajoso].lucro;
		}
	}
	printf("=========================================================\n");
	printf("= A melhor venda foi do carro: 							=\n");
	printf("=-------------------------------------------------------=\n");
	printf("Nome: \t%s \nMarca: \t%s \nAno: \t%d \nCompra: \tR$ %10.2f \nRevenda: \tR$ %10.2f \nLucro: \t%10.2f %\n\n", cadastro[posicao_vantajoso].nome, cadastro[posicao_vantajoso].marca, cadastro[posicao_vantajoso].ano, cadastro[posicao_vantajoso].vCompra, cadastro[posicao_vantajoso].vRevenda, cadastro[posicao_vantajoso].lucro);
	printf("=========================================================\n");
}

int main()
  
{
	opcao = 0;

telaabertura:
	opcao = 0;
	while ( ( opcao <= 0 ) || ( opcao >= 6 ) )  {
		printf("Digite uma opção: \n");
		printf("1. Cadastrar o carro \n");
		printf("2. Listar todos os carros \n");
		printf("3. Listar o carro mais antigo \n");
		printf("4. Listar o carro com maior porcentagem de lucro \n");
		printf("5. Sair \n");
		scanf("%d", &opcao);
	}
	
	switch(opcao)
		{
		case 1: 
				cadastrar(posicao);
				posicao = posicao + 1;
				goto telaabertura;
				break;
		case 2: 
				listar_todos();
				goto telaabertura;
				break;
		case 3: 
				listar_mais_experiente();
				goto telaabertura;
				break;
		case 4: 
				listar_mais_vantajoso();
				goto telaabertura;
				break;
		default : printf("Obrigado");
		}
	
	return 0;
}

