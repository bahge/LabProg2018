/* ==========================
* Bibliotecas
* =========================== */
#include <stdio.h>

/* ==========================
* Função Exponenciação
* =========================== */
int func_elevar(int base, int expoente){
    //Condição de retorno único
    if (expoente == 0 ){
        return 1;
    }
    //Condição de recursividade
    else {
        return base * func_elevar(base, expoente - 1);
    }
}

/* ==========================
* Main
* =========================== */
void main(){
    //Variáveis
    int base, expoente, calculo;

    //Entrada da base pelo usuário e validação
    printf("Digite uma base positiva\n");
    scanf("%d", &base);
    while ( base < 1 ){
        printf("A base não pode ser menor que 1, digite novamente\n");
        scanf("%d", &base);
    }

    //Entrada do expoente pelo usuário e validação
    printf("Digite uma expoente positiva\n");
    scanf("%d", &expoente);
    while ( expoente < 1 ){
        printf("A expoente não pode ser menor que 1, digite novamente\n");
        scanf("%d", &expoente);
    }

    //Chamada da função recursiva
    calculo = func_elevar(base, expoente);
    
    //Apresentação do resultado
    printf("O resultado é: %d\n", calculo);
}