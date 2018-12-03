/**
 * @file    index.c
 * @author  Leandro Costa Garcia
 * @data    02/dez/2018
 *
 * @brief   Resolução do exercício 01
 * 
 * Exercicio 01 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 * 
 * Exercicio 01 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Exercicio 01. If not, see https://www.gnu.org/licenses/.
 * 
 */
#include <stdio.h>
#include <stdbool.h>
#include "tabelasReferencia.h"


void main () {
    // Variáveis
    bool opcao = true;
    int codigo, quantidade;
    float preco, precoTotal, desconto, valorDesconto, valorFinal;
    // Mensagem de boas vindas
    printf("\n----------------------------------------------------------\n");
    printf("\E[33mBem vindos ao sistema de compras\E[0m\n");
    printf("----------------------------------------------------------\n");
    // Opções   
    while( opcao ){
        printf("\E[34mFavor digitar o código do produto a ser comprado\E[0m\n");
        scanf("%d", &codigo);
        
        if ( codigo > 0 && codigo < 41 ){
            opcao = false;
        } else {
           printf("Código não encontrado\nFavor digite um valor entre 1 e 40\n"); 
        }
    }
    // Reaproveitamento da variável opcao para teste do valor da quantidade de produto
    opcao = true;
    while( opcao ){
        printf("\E[34mFavor digitar a quantidade de produto\E[0m\n");
        scanf("%d", &quantidade);
        
        if ( quantidade > 0 ){
            opcao = false;
        } else {
           printf("A quantidade digitada deve ser maior que 0\n");
        }
    }
    preco = tabelaPreco(codigo);
    precoTotal = preco * quantidade;
    desconto = tabelaDesconto(precoTotal);
    valorDesconto = precoTotal - ( precoTotal * ( 1 - ( desconto / 100 ) ) );
    valorFinal = precoTotal - valorDesconto;
    printf("\E[33m----------------------------------------------------------\E[0m\n");
    printf("  O preço unitário é:             \E[34mR$ %.2f\E[0m \n", preco);
    printf("  O preço total da Nota é:        \E[34mR$ %.2f\E[0m \n", precoTotal);
    printf("  O desconto da Nota é:           \E[34mR$ %.2f\E[0m", valorDesconto);
    printf("    ==> \E[31m%.2f%\E[0m\n", desconto);
    printf("\E[33m----------------------------------------------------------\E[0m\n");
    printf("  O valor final:                  \E[34mR$ %.2f\E[0m\n\n", valorFinal);
}

