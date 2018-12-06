#-*- coding: utf-8 -*-
'''
@file    ex02.py
@authors Leandro Costa Garcia
@data    05/dez/2018
@brief   Resolução do exercício 02 - python

ex02.py is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
any later version.

ex02.py is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ex02.py. If not, see https://www.gnu.org/licenses/.

Fazer em um novo arquivo:
    - Solicitar a idade do usuário
    - Se for maior de 18 informar que ele é maior de idade
    - Se for menor, porém maior ou igual 16, informar que ele já pode votar
    - Se for menor que 16 solicitar o contato de um responsável
'''

idadeUser=int(input("Quantos invernos tchê? "))
if (idadeUser < 16):
    contato=input("Quem te manda? ")
elif(idadeUser >= 16) and (idadeUser <18):
    print("Você é menor, mas já pode votar.")
elif(idadeUser >= 18):
    print("Você é maior.")
