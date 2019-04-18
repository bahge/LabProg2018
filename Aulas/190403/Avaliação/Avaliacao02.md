## Avaliação - Linguagem Phyton

Esta etapa da segunda avaliação deve ser desenvolvida utilizando a linguagem Python. E assim como a primeira parte, a segunda parte também terá como ponto de partida a primeira questão da primeira avaliação:

Um jovem estudante de Sistemas de Informação resolveu criar um sistema em linguagem Phyton para a revenda de carros usados da família, como forma de praticar o que vinha aprendendo.
Ele fez o levantamento e planejamento inicial do sistema e pensou nos seguintes requisitos:

1. Criar uma estrutura do tipo registro chamada T_CARRO com no mínimo os seguintes dados:
- Código do carro (inteiro)
- Nome do carro
- Marca/fabricante
- Ano do carro
- Valor de compra
- Valor de revenda

Ao ser cadastrado, deve-se contabilizar a porcentagem de lucro da venda do carro.

Todavia, ao invés de desenvolver uma lista encadeada de alocação dinâmica, deveremos utilizar pelo menos duas estruturas de dados nativas da linguagem Python. Também será necessário fazer fazer a leitura e escrita em arquivo físico.

O arquivo físico deve ter um formato CSV (Comma-separated values) onde cada campo será separado por ";" (ponto e vírgula) e cada registro (linha) separado por \n (quebra de linha).

Ao iniciar o programa, os dados do arquivo texto devem ser carregados para a lista dinâmica e ao sair os dados devem ser persistidos no arquivos físico.

O sistema deve ter ainda um menu com as seguintes opções:
1. Cadastrar carro
2. Listar todos os carros cadastrados (listador todos os dados, inclusive o lucro)
3. Excluir carro (a partir do código do carro)
4. Listar carro mais antigo (listador todos os dados, inclusive o lucro)
5. Listar carro com maior porcentagem de lucro (listador todos os dados, inclusive o lucro)
6. Sair (persistir dados no arquivo físico)