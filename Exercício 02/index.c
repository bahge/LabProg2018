/**
 * @file    index.c
 * @author  Leandro Costa Garcia
 * @data    02/dez/2018
 *
 * @brief   Resolução do exercício 02
 * 
 * Exercicio 02 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 * 
 * Exercicio 02 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Exercicio 02. If not, see https://www.gnu.org/licenses/.
 * 
 */
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
