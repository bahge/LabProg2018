#include <stdio.h>
#include <string.h>

typedef struct TAluno {
	
	int rga;
	char nome[120];
	int cod_curso;
	float coeficiente;
	float notas[4];
	
} TAluno;

int main() {

	TAluno joao;
	
	joao.rga = 201811316;
	strcpy(joao.nome, "João Alves");
	
	printf("%d : %s",joao.rga,joao.nome);

	return 0;

}