#!/usr/bin/env python
# -*- coding: utf-8 -*-

# --------------------------------------------------------------------
# Nomes: 	| Leandro Costa Garcia 		  |	Fabio Cançado
# RGA:		|	201811316013				      |	201811316028
# --------------------------------------------------------------------
#
# Avaliação - Linguagem Phyton
#
# Esta etapa da segunda avaliação deve ser desenvolvida utilizando a linguagem Python. E assim como a primeira parte, a segunda parte também terá como ponto de partida a primeira questão da primeira avaliação:
#
# Um jovem estudante de Sistemas de Informação resolveu criar um sistema em linguagem Phyton para a revenda de carros usados da família, como forma de praticar o que vinha aprendendo.
# Ele fez o levantamento e planejamento inicial do sistema e pensou nos seguintes requisitos:
# 
# 1. Criar uma estrutura do tipo registro chamada T_CARRO com no mínimo os seguintes dados:
# - Código do carro (inteiro)
# - Nome do carro
# - Marca/fabricante
# - Ano do carro
# - Valor de compra
# - Valor de revenda
#
# Ao ser cadastrado, deve-se contabilizar a porcentagem de lucro da venda do carro.
#
# Todavia, ao invés de desenvolver uma lista encadeada de alocação dinâmica, deveremos utilizar pelo menos duas estruturas de dados nativas da linguagem Python. Também será necessário fazer fazer a leitura e escrita em arquivo físico.
#
# O arquivo físico deve ter um formato CSV (Comma-separated values) onde cada campo será separado por ";" (ponto e vírgula) e cada registro (linha) separado por \n (quebra de linha).
#
# Ao iniciar o programa, os dados do arquivo texto devem ser carregados para a lista dinâmica e ao sair os dados devem ser persistidos no arquivos físico.
#
# O sistema deve ter ainda um menu com as seguintes opções:
# 1. Cadastrar carro
# 2. Listar todos os carros cadastrados (listador todos os dados, inclusive o lucro)
# 3. Excluir carro (a partir do código do carro)
# 4. Listar carro mais antigo (listador todos os dados, inclusive o lucro)
# 5. Listar carro com maior porcentagem de lucro (listador todos os dados, inclusive o lucro)
# 6. Sair (persistir dados no arquivo físico)

# Insere o registro na lista
def insereNaLista(carros):
    print("----------------------------------- Cadastro de Veiculo -----------------------------------\n")
    if ( carros == [] ):
        cod = 1
    else:
        carros.sort(key=lambda x: x[0], reverse=True)
        cod = carros[0][0] + 1
    print("Novo carro, código: " + str(cod))
    nome = input("Digite um nome: ")
    marca = input("Digite uma marca: ")
    ano = int(input("Digite o ano: "))
    vCompra = float(input("Digite o valor de compra: "))
    vRevenda = float(input("Digite o valor de revenda: "))
    lucro = ( ( vRevenda - vCompra ) / vCompra ) * 100
    carros.append((cod, nome, marca, ano, vCompra, vRevenda, lucro))
    print("------------------------------------------------------------------------------------------\n")
    print("\nCarro cadastrado com sucesso!\n")

# Imprime na tela todos os carros
def listaCarros(carros, opt_par):
    if (opt_par == None):
        if(carros == []):
            print("\tNão há carros, cadastrados na lista!\n")
        else:
            print("----------------------------------- Lista de Veículos -----------------------------------\n")
            carros.sort(key=lambda x: x[0])
            for carro in carros:
                cod, nome, marca, ano, vCompra, vRevenda, lucro = carro
                print("\tCod: " + str(cod) + "\t\t\t\t\t\t\t\t" + "Ano: " + str(ano))
                print("Nome: " + str(nome) + "\t\t\t" + "Marca: " + str(marca))
                print("Valor de compra: R$ " + "{0:.2f}".format(vCompra) + "\t\t\t\t" + "Valor de revenda: R$ " + "{0:.2f}".format(vRevenda))
                print("Porcentagem de lucro: " + "{0:.2f}".format(lucro) + "%\n")
            print("------------------------------------------------------------------------------------------\n")
        pass
    if (opt_par == 1):
        if(carros == []):
            print( "\tNão há carros, cadastrados na lista!\n" )
        else:
            print("- Maior lucro ----------------------------------------------------------------------------\n")
            print("\tCod: " + str(carros[0][0]) + "\t\t\t\t\t\t\t\t" + "Ano: " + str(carros[0][3]))
            print("Nome: " + str(carros[0][1]) + "\t\t\t" + "Marca: " + str(carros[0][2]))
            print("Valor de compra: R$ " + "{0:.2f}".format(carros[0][4]) + "\t\t\t\t" + "Valor de revenda: R$ " + "{0:.2f}".format(carros[0][5]))
            print("Porcentagem de lucro: " + "{0:.2f}".format(carros[0][6]) + "%\n")
            print("------------------------------------------------------------------------------------------\n")
        pass
    if (opt_par == 2):
        if(carros == []):
            print( "\tNão há carros, cadastrados na lista!\n" )
        else:
            print("- Mais antigo ----------------------------------------------------------------------------\n")
            print("\tCod: " + str(carros[0][0]) + "\t\t\t\t\t\t\t\t" + "Ano: " + str(carros[0][3]))
            print("Nome: " + str(carros[0][1]) + "\t\t\t" + "Marca: " + str(carros[0][2]))
            print("Valor de compra: R$ " + "{0:.2f}".format(carros[0][4]) + "\t\t\t\t" + "Valor de revenda: R$ " + "{0:.2f}".format(carros[0][5]))
            print("Porcentagem de lucro: " + "{0:.2f}".format(carros[0][6]) + "%\n")
            print("------------------------------------------------------------------------------------------\n")
        pass

# exclui um elemento de acordo com o código
def excluirCarro(carros):
    exclusao = False
    excluir = int(input("Digite o código do carro que queira excluir: "))
    for carro in carros:
        cod, nome, marca, ano, vCompra, vRevenda, lucro = carro
        if(excluir == cod):
            exclusao = True
            print("Carro encontrado\n")
            print("\tCod: " + str(cod) + "\t\t\t\t\t\t\t\t" + "Ano: " + str(ano))
            print("Nome: " + str(nome) + "\t\t\t" + "Marca: " + str(marca))
            print("Valor de compra: R$ " + "{0:.2f}".format(vCompra) + "\t\t\t\t" + "Valor de revenda: R$ " + "{0:.2f}".format(vRevenda))
            print("Porcentagem de lucro: " + "{0:.2f}".format(lucro) + "%\n")
            confApagar = int(input("Deseja remover o carro? Digite 1 para apagar."))
            if ( confApagar == 1 ):
                carros.remove(carro)
                print("\nCarro excluído com sucesso!\n")
                pass
            else:
                print("Registro não apagado")
                pass
    if ( exclusao != True ):
        print("\nNão existe nenhum carro com esse código!\n")


# função que lê do arquivo e grava no arquivo
def lerArquivo(carros):
    cod_carros = 0
    try:
        arquivo = open("carros.csv","r")
        for linha in arquivo:
            linha = linha.split(";")
            if ( int( linha[0] ) > int( cod_carros ) ):
                cod_carros = linha[0]
                pass
            cod = int(linha[0])
            nome = linha[1]
            marca = linha[2]
            ano = int(linha[3])
            vCompra = float(linha[4])
            vRevenda = float(linha[5]) 
            lucro = float(linha[6])
            carros.append((cod, nome, marca, ano, vCompra, vRevenda, lucro))
        arquivo.close()
    except IOError:
        print("Não há registros.")
        
# Grava a lista no arquivo
# carros - lista usada durante a execução do app
def gravarArquivo(carros):
    sep = ';'
    arq = open("carros.csv","w")
    for carro in carros:
        cod, nome, marca, ano, vCompra, vRevenda, lucro = carro
        arq.write(str(cod) + sep + nome + sep + marca + sep + str(ano) + sep + str(vCompra) + sep + str(vRevenda) + sep + str(lucro) + "\n")
    arq.close()

# Tela de Abertura
def telaAbertura():
    print('Digite uma opcao:')
    print('1. Cadastrar o carro')
    print('2. Listar todos os carros cadastrados')
    print('3. Excluir carro')
    print('4. Listar carro mais antigo')
    print('5. Listar o carro com maior porcentagem de lucro')
    print('6. Sair')

# Função main, principal do app
def main():
    carros = [] #lista
    lerArquivo(carros)
    telaAbertura()
    opcao = int(input("Opção: "))
    while opcao != 6:
        if opcao == 1:
            insereNaLista(carros)
        elif opcao == 2:
            listaCarros(carros, None)
        elif opcao == 3:
            excluirCarro(carros)
        elif opcao == 4:
            carros.sort(key=lambda x: x[3])
            listaCarros(carros, 2)
        elif opcao == 5:
            carros.sort(key=lambda a: a[6], reverse=True)
            listaCarros(carros, 1)
        else:
            print("Opção Inválida!")
        telaAbertura()
        opcao = int(input("Opção: "))
    print("Obrigado")
    gravarArquivo(carros)

# chama a função main, que por sua vez chama todas as outras
main()