#include <stdio.h>
#include <stdbool.h>
#include "tabelasReferencia.h"

void main()
{
    // Variáveis
    bool opcao = true, opmes = true;
    int codigo, meses;
    float salario, resSalario;
    // Mensagem de boas vindas
    printf("\n----------------------------------------------------------\n");
    printf("\E[33mBem vindo\E[0m\n");
    printf("----------------------------------------------------------\n");
    // Opções   
    OPCAO: while( opcao ){
        printf("\nSelecione uma opção\n");
        printf("\E[34m1 \E[0m- Férias\n");
        printf("\E[34m2 \E[0m- Décimo Terceiro\n");
        printf("\E[34m3 \E[0m- Sair\n");
        scanf("%d", &codigo);
        
        if ( codigo > 0 && codigo < 4 ){
            opcao = false;
        } else {
           printf("Código não encontrado\nFavor digite um código entre 1 e 3\n"); 
        }
    }

    switch (codigo)
    {
        case 1:
            printf("\E[34mDigite o valor do seu salário:\E[0m\n");
            scanf("%f", &salario);
            resSalario = ferias(salario);
            printf("O valor das férias são: \E[33mR$ %.2f\E[0m\n", resSalario);
            opcao = true;
            opmes = true;
            goto OPCAO;
            break;

        case 2:
            printf("\E[34mDigite o valor do seu salário:\E[0m\n");
            scanf("%f", &salario);

            while ( opmes ) {
                printf("\E[34mDigite o número de meses trabalhados:\E[0m\n");
                scanf("%d", &meses);
                if ( meses > 0 && meses < 13 ) {
                    opmes = false;    
                }   else {
                    printf("O intervalo de meses deve ser entre 1 e 12\n"); 
                }
            }
            resSalario = decimoterceiro(salario, meses);
            printf("\nO valor do seu Décimo Terceiro é: \E[33mR$ %.2f\E[0m\n", resSalario);
            opcao = true;
            opmes = true;
            goto OPCAO;
            break;

        default:
            printf("\E[31m\nObrigado\E[0m\n\n");
            break;
    }
}
