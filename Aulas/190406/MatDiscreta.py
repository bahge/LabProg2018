# -*- coding: utf-8 -*-

def helpEuclides():
    print("1. Mostrar o que é o algoritmo de Euclides")
    print("+--------------------------------------------------------------------------------------+")
    print("| Algorítmo de Euclides                                                                |")
    print("+--------------------------------------------------------------------------------------+")
    print("| Em matemática, o algoritmo de Euclides é um método simples e eficiente de encontrar  |")
    print("| o máximo divisor comum entre dois números inteiros diferentes de zero.               |")
    print("| O MDC de dois números inteiros é o maior número inteiro que divide ambos sem deixar  |")
    print("| resto.                                                                               |")
    print("| O algoritmo de Euclides é baseado no princípio de que o MDC não muda se o menor      |")
    print("| número for subtraído ao maior.                                                       |")
    print("| Ele é um elemento-chave dos algoritmos RSA, um método de criptografia de chave       |")
    print("| pública usado no comércio eletrônico.                                                |")
    print("| Ele é usado para resolver as equações de diofantina, tal como na descoberta de       |")
    print("| números que seja safistatório em múltiplas congruências ou inverso multiplicativo de |")
    print("| um número finito.                                                                    |")
    print("+--------------------------------------------------------------------------------------+")
    return ("")

def fnc_mdc(a, b):
    if b==0:
        return a
    else:
        return fnc_mdc(b, a % b)

def ehprimo(numero):
    print("+--------------------------------------------------------------------------------------+")
    divisores = 0
    for divisor in range(1, numero):
        if numero % divisor == 0:
            divisores = divisores + 1
            if divisores > 1:
                break
    if divisores > 1:
        msg = "não é primo"
    else:
        msg = "é primo"
    return msg

def menu(opcao):
    if opcao == "0":
        print("")
    elif opcao == "1":
        print(helpEuclides())
    elif opcao == "2":
        print("2. Mostrar se um número é primo")
        print("+--------------------------------------------------------------------------------------+")
        st_numero=input("Digite um número: ")
        numero = int(st_numero)
        c=ehprimo(numero)
        print("O número ", numero, ": ",c)
        print("+--------------------------------------------------------------------------------------+")
    elif opcao == "3":
        print("3. Mostrar o MDC entre dois números")
        print("+--------------------------------------------------------------------------------------+")
        a=input("Digite o primeiro número inteiro: ")
        b=input("Digite o segundo número inteiro: ")
        a_int = int(a)
        b_int = int(b)
        c=fnc_mdc(a_int, b_int)
        print("O MDC é: ", c)
        print("+--------------------------------------------------------------------------------------+")
    elif opcao == "9":
        print("9. Sair")
        print("+--------------------------------------------------------------------------------------+")
        print("Obrigado por acessar")
    else:    
        print("Opção inválida, insira outra opção.")

print("    _________________________________________________________________________________________________________________________________________________    ")
print("  /                                           _                         |   .--.--.      ,---,  |                           __  __   ___              \  ")
print(" |    _____          __                     /_/ __  .__                 |  /  /    '. ,`--.' |  |                     _.._ |  |/  `.'   `.             | ")
print(" |   /     \ _____ _/  |_  ____   _____ _____ _/  |_|__| ____ _____     | |  :  /`. / |   :  :  |                   .' .._||   .-.  .-.   '     .|     | ")
print(" |  /  \ /  \ __  \    __\/ __ \ /     \ __  \    __\  |/ ___\ __  \    | |  |  |--`  :   |  '  |                   | '    |  |  |  |  |  |   .' |_    | ")
print(" | /    Y    \/ __ \|  | \  ___/|  Y Y  \/ __ \|  | |  \  \___ / __ \_  | |  :  ;_    |   :  |  |    __      __   __| |__  |  |  |  |  |  | .'     |   | ")
print(" | \____|__  (____  /__|  \___  >__|_|  (____  /__| |__|\___  >____  /  |  \  \    `. '   '  ;  |   |  |    '  | |__   __| |  |  |  |  |  |'--.  .-'   | ")
print(" |         \/     \/          \/      \/     \/             \/     \/   |   `----.   \|   |  |  |   |. |    |' |    | |    |  |  |  |  |  |   |  |     | ")
print(" |              ________  .__                             __            |   __ \  \  |'   :  ;  |   |  |    |  |    | |    |__|  |__|  |__|   |  |     | ")
print(" |              \______ \ |__| ______ ___________   _____/  |______     |  /  /`--'  /|   |  '  |   |   \__/.  |    | |                       |  '.'   | ")
print(" |               |    |  \|  |/  ___// ___\_  __ \_/ __ \   __\__  \    | '--'.     / '   :  |  |   |          |    | |                       |   /    | ")
print(" |               |    `   \  |\___ \   \___|  | \/\  ___/|  |  / __ \_  |   `--'---'  ;   |.'   |   \_________/     |_|                       `'-'     | ")
print(" |              /_______  /__/____  >\___  >__|    \___  >__| (____  /  |            '---'      |                                                      | ")
print(" |                      \/        \/     \/            \/          \/   |_______________________|______________________________________________________| ")
print(" | Projeto para avaliação parcial                                       | Nome: Leandro Costa Garcia                                              2019 | ")
print(" |______________________________________________________________________|______________________________________________________________________________| ")
print("")
print("Opções cadastradas")
print("1. Mostrar o que é o algoritmo de Euclides")
print("2. Mostrar se um número é primo")
print("3. Mostrar o MDC entre dois números")
print("9. Sair")
print("")

opcao = "0"
while opcao != "9":
    opcao = str(input("Digite uma opção: "))
    menu(opcao)
else:
    print("Leandro Costa Garcia")
    print("+--------------------------------------------------------------------------------------+")
    print("")