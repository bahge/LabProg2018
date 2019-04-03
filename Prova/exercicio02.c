/*
 * exercicio02
 * --------------------------------------------------------------------
 * Nomes: 	| Leandro Costa Garcia 		  |	Fabio Cançado
 * --------------------------------------------------------------------
 * 
 * QUESTÃO 2 - Cubos do tipo OLAP são importantes ferramentas no apoio 
 * à tomada de decisão, uma vez que permitem o cruzamento de diferentes 
 * tipos de dados.
 * Dado o cubo 3x3x3 a seguir:
 * int cubo[3][3][3] = {
 * 		{{12,18,17},{14,12,13},{4,8,5}},
 * 		{{10,19,7},{11,10,13},{4,8,3}},
 * 		{{2,0,17},{4,8,12},{7,18,6}}
 * };
 * Crie um algoritmo que faça o somatório das células de cada face de 
 * um cubo 4x4 e apreste na tela o resultado.
 */


#include <stdio.h>

int main()
{
	int faces[5];
	int c;
	int h;
	
	int cubo[3][3][3] = {
		{{12,18,17},	{14,12,13},		{4,8,5}},
		{{10,19,7},		{11,10,13},		{4,8,3}},
		{{2,0,17},		{4,8,12},		{7,18,6}}
		};
		
	for (int i = 0; i < 6; i++)
	{
		faces[i] = 0;
	}
	
	
	
	/*1 = 12 18 17 	14 12 13 	4 8 5
	2 = 2 0 17 		4 8 12 		7 18 6
	3 = 12 18 17	10 19 7		2 0	17
	4 = 4 8	5		4 8 3		7 18 6
	5 = 12 10 2		14 11 4		4 4 7
	6 = 17 7 17		13 13 12	5 3 6*/
	
	for (c = 0; c < 3; c++)
	{
		for (h = 0; h < 3; h++)
			{
				faces[0] = faces[0] + cubo[0][h][c];
			}
	}
	
	for (c = 0; c < 3; c++)
	{
		for (h = 0; h < 3; h++)
			{
				faces[1] = faces[1] + cubo[2][h][c];
			}
	}
	
	for (c = 0; c < 3; c++)
	{
		for (h = 0; h < 3; h++)
			{
				faces[2] = faces[2] + cubo[h][0][c];
			}
	}
	
	for (c = 0; c < 3; c++)
	{
		for (h = 0; h < 3; h++)
			{
				faces[3] = faces[3] + cubo[h][2][c];
			}
	}
	
	for (c = 0; c < 3; c++)
	{
		for (h = 0; h < 3; h++)
			{
				faces[4] = faces[4] + cubo[h][c][0];
			}
	}
	
	for (c = 0; c < 3; c++)
	{
		for (h = 0; h < 3; h++)
			{
				faces[5] = faces[5] + cubo[h][c][2];
			}
	}


	printf("A: %d\n", faces[0]);
	printf("B: %d\n", faces[1]);
	printf("C: %d\n", faces[2]);
	printf("D: %d\n", faces[3]);
	printf("E: %d\n", faces[4]);
	printf("F: %d\n", faces[5]);
	return 0;
		
}

