/*
* --------------------------------------------------------------------
* Nomes: 	| Leandro Costa Garcia 		  |	Fabio Cançado
* RGA:		|	201811316013				      |	201811316028
* --------------------------------------------------------------------

## Avaliação - Linguagem C

Um jovem estudante de Sistemas de Informação resolveu criar um sistema em linguagem C para a revenda de carros usados da família, como forma de praticar o que vinha aprendendo. Ele fez o levantamento e planejamento inicial do sistema e pensou nos seguintes requisitos:  
  
1. Criar uma estrutura do tipo registro chamada T_CARRO com no mínimo os seguintes dados:
 - Código do carro (inteiro)
 - Nome do carro
 - Marca/fabricante
 - Ano do carro
 - Valor de compra
 - Valor de revenda
  
Ao ser cadastrado, deve-se contabilizar a porcentagem de lucro da venda do carro.  
  
A diferença é que agora, nessa primeira parte da segunda avaliação, a solução deve utilizar lista encadeada com alocação dinâmica e também fazer a leitura e escrita em arquivo físico.  
  
O arquivo físico deve ter um formato CSV (Comma-separated values) onde cada campo será separado por ; (ponto e vírgula) e cada registro (linha) separado por \n (quebra de linha).  
  
Ao iniciar o programa, os dados do arquivo texto devem ser carregados para a lista dinâmica e ao sair os dados devem ser persistidos no arquivos físico.  
  
O sistema deve ter ainda um menu com as seguintes opções:  
1. Cadastrar carro
2. Listar todos os carros cadastrados (listador todos os dados, inclusive o lucro)
3. Excluir carro (a partir do código do carro)
4. Listar carro mais antigo (listador todos os dados, inclusive o lucro)
5. Listar carro com maior porcentagem de lucro (listador todos os dados, inclusive o lucro)
9. Sair (persistir dados no arquivo físico)


*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
// Registro
typedef struct carro{
    int cod;
    char nome[50];
    char marca[30];
    int ano;
    float vCompra;
    float vRevenda;    
    float lucro;
    struct carro *prox;
} T_CARRO;
// Inicializa a lista e o arquivo
T_CARRO *inicio=NULL;
FILE *arq;
// Variáveis Globais
int opcao, maior_cod;

/*
  Cria a lista
*/
void CriaLista() {
   inicio = NULL;
}

/*
  Insere o registro tipo T_CARRO na lista
*/
int InsereNaLista(T_CARRO car)
{
   T_CARRO *pregistro;
   pregistro =  (T_CARRO *) malloc(sizeof(T_CARRO));
   if (pregistro==NULL)
   {
     printf("Erro de alocacao\n");
     return 0;
   }
   pregistro->cod = car.cod;
   strcpy(pregistro->nome, car.nome);
   strcpy(pregistro->marca, car.marca);
   pregistro->ano = car.ano;
   pregistro->vCompra = car.vCompra;
   pregistro->vRevenda = car.vRevenda;
   pregistro->lucro = car.lucro;
   pregistro->prox = NULL;
   if (inicio==NULL)
      inicio = pregistro;
   else {
	  pregistro->prox = inicio;
	  inicio  = pregistro;
	}
   return 1;
}

/*
 Lê o arquivo CSV se existir e envia para inserção na lista
*/
void leArquivoCSV() {
  char aux[200];
  char * temp;
  int campo = 0; 
  T_CARRO registroTemporario;
  maior_cod = 0;
  arq = fopen("carros.csv", "r");
    while (fgets(aux, 200, arq) != NULL) {
      temp = strtok (aux,";;;;;");
      campo = 0;
        while (temp != NULL) {
          if ( campo == 0 ) {
            registroTemporario.cod = atoll(temp);
            campo++;
          } else if ( campo == 1 ) {
            strcpy(registroTemporario.nome, temp);
            campo++;
          } else if ( campo == 2 ) {
            strcpy(registroTemporario.marca, temp);
            campo++;
          } else if ( campo == 3 ) {
            registroTemporario.ano = atoll(temp);
            campo++;
          } else if ( campo == 4 ) {
            registroTemporario.vCompra = atof(temp);
            campo++;
          } else if ( campo == 5 ) {
            registroTemporario.vRevenda = atof(temp);
            campo++;
          } else if ( campo == 6 ) {
            registroTemporario.lucro = atof(temp);
            if ( registroTemporario.cod >= maior_cod ) { maior_cod = registroTemporario.cod; }
            InsereNaLista(registroTemporario);
            campo = 0;
          }
          temp = strtok (NULL,";;;;;");			
        } 
    }
  fclose(arq);
}

/*
 Cadastra o carro na lista, incrementando o código automaticamente
*/
int CadastraCarro(){
    char t_nome[50], t_marca[30];
    int t_cod, t_ano, ret;
    float t_vCompra, t_vRevenda, t_lucro;
    T_CARRO registroTemporario;

  printf("----------------------------------- Cadastro de Veiculo -----------------------------------\n");
    t_cod = maior_cod + 1;
    printf("Novo codigo: %d\n", t_cod);
    printf("Digite um nome: ");
    scanf("%s", &t_nome);
    printf("Digite uma marca: ");
    scanf("%s", &t_marca);
    printf("Digite o ano: ");
    scanf("%d", &t_ano);
    printf("Digite o valor de compra: ");
    scanf("%f", &t_vCompra);
    printf("Digite o valor de revenda: ");
    scanf("%f", &t_vRevenda);
    t_lucro =  ( ( ( t_vRevenda - t_vCompra ) / t_vCompra ) * 100 );
    printf("Lucro: R$ %10.2f %%\n", t_lucro);
      // Cria o registro para inserir na lista
      registroTemporario.cod = t_cod;
      strcpy (registroTemporario.nome, t_nome);
      strcpy (registroTemporario.marca, t_marca);
      registroTemporario.ano = t_ano;
      registroTemporario.vCompra =  t_vCompra;
      registroTemporario.vRevenda = t_vRevenda;
      registroTemporario.lucro = t_lucro;

      ret = InsereNaLista(registroTemporario);

      if ( ret == 1 ) {
        return 1;
      }
      return 0;   
}

/*
 Imprime toda a lista, com paramentro na tela ou no arquivo
 1 - Imprime na tela
 2 - Imprime no arquivo
*/
void Imprime(int noarquivo)
{
  T_CARRO *ponteiroAtual;
    if (inicio == NULL)
    {
      printf("\n\tA lista esta vazia.\n\n");
      return;
    }
    if ( noarquivo == 2) {
      arq = fopen ("carros.csv", "w");
    }
    ponteiroAtual = inicio;
    while (ponteiroAtual !=NULL) {
      if ( noarquivo == 1 ) {        
        for(int i = 0; i < 78; i++) { printf(" "); }
        printf("______________\n ");
        for(int i = 0; i < 76; i++) { printf("_"); }
        printf("/ Ano: \t%d\\ \n", ponteiroAtual->ano);
        printf(" \tNome: \t%s \t\t\t\tCod: %d\n", ponteiroAtual->nome, ponteiroAtual->cod);
        printf(" \tMarca: \t%s \n", ponteiroAtual->marca);
        printf("\tCompra: R$ %10.2f \tRevenda: R$ %10.2f \t\tLucro: \t%10.2f %% \n",  ponteiroAtual->vCompra, ponteiroAtual->vRevenda, ponteiroAtual->lucro);
      printf("\n");
      } else {
        fprintf(arq,"%d;%s;%s;%d;%.2f;%.2f;%.2f\n", ponteiroAtual->cod,  ponteiroAtual->nome, ponteiroAtual->marca, ponteiroAtual->ano, ponteiroAtual->vCompra, ponteiroAtual->vRevenda, ponteiroAtual->lucro);
      }
    ponteiroAtual = ponteiroAtual->prox;
    }
    if ( noarquivo == 2) {
      fclose(arq);
    }
}

/*
 Busca o registro do carro conforme o parâmentro
 1 - Parâmetro de busca por ano de fabrição
 2 - Parâmetro de busca por lucro
 3 - Codigo
*/
T_CARRO procuraCarro(int parametro, int codigo) {
   T_CARRO *ponteiroAtual;
   T_CARRO registroTemporario;
   int intCompara = 30000;
   float floatCompara = 0;
    registroTemporario.cod = 0;
    if (inicio == NULL)
    {
      printf("\n \tA lista esta vazia.\n\n");
      return registroTemporario;
    }
    ponteiroAtual = inicio;
    while (ponteiroAtual !=NULL) {
      if ( parametro == 1 ) {
        if( intCompara > ponteiroAtual->ano ) {
          intCompara = ponteiroAtual->ano;
          registroTemporario.cod = ponteiroAtual->cod;
          strcpy (registroTemporario.nome, ponteiroAtual->nome);
          strcpy (registroTemporario.marca, ponteiroAtual->marca);
          registroTemporario.ano = ponteiroAtual->ano;
          registroTemporario.vCompra =  ponteiroAtual->vCompra;
          registroTemporario.vRevenda = ponteiroAtual->vRevenda;
          registroTemporario.lucro = ponteiroAtual->lucro;
        }

      } else if ( parametro == 2 ) {
        if( floatCompara < ponteiroAtual->lucro ) {
          floatCompara = ponteiroAtual->lucro;
          registroTemporario.cod = ponteiroAtual->cod;
          strcpy (registroTemporario.nome, ponteiroAtual->nome);
          strcpy (registroTemporario.marca, ponteiroAtual->marca);
          registroTemporario.ano = ponteiroAtual->ano;
          registroTemporario.vCompra =  ponteiroAtual->vCompra;
          registroTemporario.vRevenda = ponteiroAtual->vRevenda;
          registroTemporario.lucro = ponteiroAtual->lucro;
        }
      } else if ( parametro == 3 ) {
        if( codigo == ponteiroAtual->cod ) {
          registroTemporario.cod = ponteiroAtual->cod;
          strcpy (registroTemporario.nome, ponteiroAtual->nome);
          strcpy (registroTemporario.marca, ponteiroAtual->marca);
          registroTemporario.ano = ponteiroAtual->ano;
          registroTemporario.vCompra =  ponteiroAtual->vCompra;
          registroTemporario.vRevenda = ponteiroAtual->vRevenda;
          registroTemporario.lucro = ponteiroAtual->lucro;
        } 
      }
      ponteiroAtual = ponteiroAtual->prox;
    }
    
  return (registroTemporario);
}

/*
  Remove o carro da lista
  O usuário só pode chegar aqui se o carro esta presente na lista
  1 - Codigo
  O retorno será 0 se não encontrar o registro
*/
int RemoveCarro(int codigo) {
  T_CARRO *ponteiroAtual, *ponteiroAnterior;

  ponteiroAtual = inicio;
  ponteiroAnterior = inicio;
  while (ponteiroAtual !=NULL) {
    if (ponteiroAtual->cod == codigo) {
      if (ponteiroAtual == inicio) {
        inicio = inicio->prox;
        free(ponteiroAtual);
        return 1;
      } else {
        ponteiroAnterior->prox = ponteiroAtual->prox;
        free(ponteiroAtual);
        return 1;
      }
    } else {
      ponteiroAnterior = ponteiroAtual;
      ponteiroAtual = ponteiroAtual->prox;
    }
  }
  return 0;
}

/*
-------------------------------- Função main ----------------------------------------
*/
int main() {
  int cod_apagar, optExcluir, resp;
  T_CARRO busca;
  CriaLista();
  leArquivoCSV();

telaabertura:
	opcao = 0;
	while ( ( opcao <= 0 ) || ( opcao >= 7 ) )  {
		printf("Digite uma opcao: \n");
		printf("1. Cadastrar o carro \n");
		printf("2. Listar todos os carros cadastrados \n");
    printf("3. Excluir carro \n");
		printf("4. Listar carro mais antigo \n");
		printf("5. Listar o carro com maior porcentagem de lucro \n");
		printf("6. Sair \n");
		scanf("%d", &opcao);
	}
	
	switch(opcao)
		{
		case 1: 
        printf("1. Cadastrar o carro \n");
        resp = 0;
        resp = CadastraCarro();
        if ( resp == 1 ) {
          printf("\n Carro cadastrado com sucesso!");
          maior_cod++;
        } else {
          printf("\n Erro ao cadastrar o veiculo!");
        }
        goto telaabertura;
				break;
		case 2: 
				printf("2. Listar todos os carros cadastrados \n");
				Imprime(1);
        printf("\n\n");
				goto telaabertura;
				break;
		case 3: 
				printf("3. Excluir carro \n");
          printf("Digite o codigo do carro para apagar \n");
          scanf("%d", &cod_apagar);
          busca = procuraCarro(3, cod_apagar);
            if ( busca.cod != 0 ) {
              for(int i = 0; i < 78; i++) { printf(" "); }
                printf("______________\n ");
                for(int i = 0; i < 76; i++) { printf("_"); }
                printf("/ Ano: \t%d\\ \n", busca.ano);
                printf(" \tNome: \t%s \t\t\t\tCod: %d\n", busca.nome, busca.cod);
                printf(" \tMarca: \t%s \n", busca.marca);
                printf("\tCompra: R$ %10.2f \tRevenda: R$ %10.2f \t\tLucro: \t%10.2f %% \n",  busca.vCompra, busca.vRevenda, busca.lucro);
                printf("\nTem certeza que deseja apagar o registro: %d ? ( Digite '1' para sim e '2' para nao )", cod_apagar);
                optExcluir = 0;
                while ( ( optExcluir <= 0 ) || ( optExcluir > 3 ) )  {
                  printf("Digite uma opcao: \n");
                  scanf("%d", &optExcluir);
                }
                if ( optExcluir == 1 ) {
                  resp = 0;
                  resp = RemoveCarro(cod_apagar);
                  if ( resp == 1 ) {
                    printf("\n Apagado com sucesso\n");
                  } else {
                    printf("\n Erro ao apagar arquivo\n");
                  }
                }
                if ( optExcluir == 2 ) {
                  printf("O registro foi mantido");
                }
                  
            } else {
              printf("Erro ao buscar carro para apagar");
              printf("\nVerifique o codigo");
            }
        printf("\n\n");
				goto telaabertura;
				break;
		case 4: 
				printf("4. Listar carro mais antigo \n");
        busca = procuraCarro(1, 0);
        if ( busca.cod != 0 ) {
          for(int i = 0; i < 78; i++) { printf(" "); }
            printf("______________\n ");
            for(int i = 0; i < 76; i++) { printf("_"); }
            printf("/ Ano: \t%d\\ \n", busca.ano);
            printf(" \tNome: \t%s \t\t\t\tCod: %d\n", busca.nome, busca.cod);
            printf(" \tMarca: \t%s \n", busca.marca);
            printf("\tCompra: R$ %10.2f \tRevenda: R$ %10.2f \t\tLucro: \t%10.2f %% \n",  busca.vCompra, busca.vRevenda, busca.lucro);         
        } else {
          printf("Erro ao buscar carro mais antigo");  
        }
        printf("\n\n");
				goto telaabertura;
				break;
    case 5: 
				printf("5. Listar o carro com maior porcentagem de lucro \n");
        busca = procuraCarro(2, 0);
        if ( busca.cod != 0 ) {
          for(int i = 0; i < 78; i++) { printf(" "); }
            printf("______________\n ");
            for(int i = 0; i < 76; i++) { printf("_"); }
            printf("/ Ano: \t%d\\ \n", busca.ano);
            printf(" \tNome: \t%s \t\t\t\tCod: %d\n", busca.nome, busca.cod);
            printf(" \tMarca: \t%s \n", busca.marca);
            printf("\tCompra: R$ %10.2f \tRevenda: R$ %10.2f \t\tLucro: \t%10.2f %% \n",  busca.vCompra, busca.vRevenda, busca.lucro);
        } else {
          printf("Erro ao buscar com maior porcentagem de lucro");  
        }
        printf("\n\n");
				goto telaabertura;
				break;
    case 6: 
				printf("6. Sair \n");
        Imprime(2);
		default: 
        printf("Obrigado");
		}
  return 0;
}