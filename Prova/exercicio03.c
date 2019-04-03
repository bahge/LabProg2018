/*
 * exercicio03
 * --------------------------------------------------------------------
 * Nomes: 	| Leandro Costa Garcia 		  |	Fabio Cançado
 * --------------------------------------------------------------------
 * 
 * QUESTÃO 3 - A partir de um vetor com 30 caracteres (A,B,C,D,E,F) 
 * gerados aleatoriamente, faça um algoritmo que identifique os 
 * caracteres repetidos e ao final imprima:
 * a) Vetor com os caracteres gerados aleatoriamente;
 * b) “Relatório” dos caracteres que se repetem e quantas vezes se 
 * repetem.
 * 
 * Importante: Desejável a utilização de vetor/matriz na solução.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *caracteresAleatorios() {
  char static vetor[30];

  for(int i = 0 ; i < 30; i++) {
    vetor[i] = 65 + (rand() % 6);
  } 

  return vetor;  
}

char *caracteres;

int main(void) {
	int somatorio[6];

  srand(time(0));

  caracteres = caracteresAleatorios();

  for (int v = 0; v < 6; v++)
  {
	  somatorio[v] =0;
  }
  

  for(int i = 0 ; i < 30 ; i++ ) {
		int pos = i+1;
		if ( pos % 3 == 0 ) {
			printf("%d: \t%c \n", i+1,caracteres[i]);
		} else {
		    printf("%d: \t%c \t", i+1,caracteres[i]);
		}
		
		switch(caracteres[i])
		{
		case 65: 
				somatorio[0] = somatorio[0] + 1;
				break;
		case 66:
				somatorio[1] = somatorio[1] + 1;
				break;
		case 67: 
				somatorio[2] = somatorio[2] + 1;
				break;
		case 68: 
				somatorio[3] = somatorio[3] + 1;
				break;
		case 69: 
				somatorio[4] = somatorio[4] + 1;
				break;
		default : somatorio[5] = somatorio[5] + 1;
		}
  }  
  printf("---------------------------------------------\n");
  printf("- A: %d                                     -\n", somatorio[0]);
  printf("- B: %d                                     -\n", somatorio[1]);
  printf("- C: %d                                     -\n", somatorio[2]);
  printf("- D: %d                                     -\n", somatorio[3]);
  printf("- E: %d                                     -\n", somatorio[4]);
  printf("- F: %d                                     -\n", somatorio[5]);
  printf("---------------------------------------------\n");
  return 0;
}
