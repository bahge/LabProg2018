/**
 * @file    tabelasReferencia.h
 * @author  Leandro Costa Garcia
 * @data    02/dez/2018
 *
 * @param   int       codigo        codigo do produto entre 1 e 40
 * @return  float                   preço do produto 
 * @param   int       valor         recebe o valor total calculado pelo quantidade e valor do produto
 * @return  float                   valor da compra com desconto
 *
 * @brief   prototype das funções de retorno de preço pelo código e desconto pelo valor total
 */
float tabelaPreco(int codigo);
float tabelaDesconto(int valor);