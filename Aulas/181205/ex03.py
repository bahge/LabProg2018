#-*- coding: utf-8 -*-
'''
@file    ex03.py
@authors Leandro Costa Garcia
@data    05/dez/2018
@brief   Resolução do exercício 03 - python

ex03.py is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
any later version.

ex03.py is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ex03.py. If not, see https://www.gnu.org/licenses/.

Faça um programa com duas opções:
    1- imprimir um número de trás pra fente até chegar em 0
    2- imprimir de 0 até chegar no "número"
O "número" deve ser fornecido pelo usuário


n=0
while(n<30):
    n = n+1
    print(n)
else :
    print("Condição näo é mais atendida")

for j in range(100):
    print(j)

for i in range(1, 18, 2):
    print(i)

'''
numero=int(input("Digite um número\n"))
numeroMenu=int(input("Selecione uma opção: \n 1 - Do número até 0 \n 2 - De 0 até o número\n"))

if (numeroMenu==1):
    for j in range(numero, -1, -1):
        print(j)
elif (numeroMenu==2):
    for j in range(-1, numero, 1):
        print(j+1)