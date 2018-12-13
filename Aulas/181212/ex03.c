#include <stdio.h>
/**
 * Vetores de string
 * 
 * Trabalhando com string
 * 
 * Ler por gets, visto que por scanf a leitura para no espaço
 * 
**/

int main() {

    char nome[40] = "Leandro";
    char sobrenome[40] = "Garcia";
    char nome_completo[80];

    printf("%s %s \n", nome, sobrenome);
    printf("Digite seu nome completo: ");
    gets(nome_completo);
    printf("Você digitou: %s\n", nome_completo);
    
    return 0;
}