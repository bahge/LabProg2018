#-*- coding: utf-8 -*-
'''
@file    ex01.py
@authors Leandro Costa Garcia
@data    05/dez/2018
@brief   Resolução do exercício 01 - python

ex01.py is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
any later version.

ex01.py is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ex01.py. If not, see https://www.gnu.org/licenses/.

'''
# Comentário uma linha

'''
    Comentário
    multiplas
    linhas
'''

variavel = 10

print(type(variavel)) #para verificar o tipo
print("Valor da variavel: "+str(variavel))

variavel = "string"

print("Novo valor da variável:"+variavel)

num = "11"
soma = int(num) + 10

nome="Leandro"
rga=2018
curso="SI"
cr=7.5

#concatenação utilizando o operador %
print("%s, matricula n. %d curso %s e coeficiente %.2f" %(nome, rga, curso, cr))
print("{0}, matricula n. {1} curso {2} e coeficiente {3}" .format(nome, rga, curso, cr))

#entrada de dados "scanf"
numero=int(input("Rascunha um número ai, tchê: "))

if (numero > 10):
    print("Você digitou um n. maior que 10")
    outro_numero=input("Digite outro número: ")