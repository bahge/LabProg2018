/**
 * @file    tabelasReferencia.h
 * @author  Leandro Costa Garcia
 * @data    02/dez/2018
 *
 * @param   float     salario       salário para cálculo das férias
 * @return  float                   salário acrescido de 1/3 do valor recebido
 * @param   float     salario       salário para cálculo do décimo terceiro
 * @param   int       meses         recebe o número de meses trabalhados
 * @return  float                   valor do décimo terceiro pegando a proporção de meses trabalhados
 *
 * @brief   prototype das funções de retorno do cálculo de férias e do décimo terceiro
 */
float ferias(float salario);
float decimoterceiro(float salario, int meses);