# Top K Elementos

O problema de encontrar os "top k itens" é uma tarefa comum, onde o objetivo é identificar os k elementos mais valiosos ou significativos a partir de uma grande coleção de dados. A necessidade de identificar esses elementos de alto valor surge em uma variedade de aplicações, tendo como exemplo a análise de dados e muito mais.

Este repositório explora a solução para o problema dos "top k itens" usando duas estruturas de dados essenciais: hash e heap. A combinação de uma tabela de hash eficiente e uma estrutura de heap possibilita a identificação dos k elementos mais valiosos de maneira otimizada. No cenário em que a coleção de dados é extensa, essa abordagem oferece uma forma de lidar com o desafio computacional de seleção dos principais elementos, mantendo o desempenho e a escalabilidade em mente.

O trabalho mostrado neste repositório tem como objetivo fazer a leitura e análise de diferentes textos fornecidos pelo usuário, podendo assim retornar os top K elementos mais frequentes apresentados nos textos. Por definição neste trabalho, k que é o número de elementos com mais frequência a serem obtidos terá o valor definido como 20, onde será apenas salvo e mostrado na tela apenas os 20 elementos mais frequentes nos textos fornecidos.

## Principais considerações

* Este programa deverá ler um arquivo contento um texto sem nenhuma formatação ("arquivo ASCII") onde cada sentença termina por um sinal de pontuação (".", "?", "!"");

* Cada parágrafo é separado por pelo menos uma linha em branco;

* Desconsirou-se, na análise a ser feita pelo seu programa, as "stop words", que não possuem conteúdo semântico. A lista de "stop words" deve ser fornecida através de um arquivo (stopwords.txt) na pasta dataset;

* Uma palavra é uma sequência de letras delimitada por espaço em branco, "coluna da esquerda", "coluna da direita" e símbolos de pontuação;

* Os arquivos de entrada são "inputN.data" (sendo N um número inteiro crescente iniciando-se apartir de 1) e "stopwords.txt";

## Desenvolvimento do problema

O desenvolvimento do algoritmo envolve:

1- Criação da Tabela de Disperção (Hash):

* Para cada palavra da coleção de dados de entrada, tokeniza-se o elemento e utiliza-se uma tabela de hash para contar a frequência de cada token. Isso permite uma contagem eficiente dos elementos em O(n) tempo.

2- Criação da Árvore de Prioridades (Heap) de Tamanho k:

* Inicialmente, insere-se os primeiros k elementos da tabela de hash em um heap de tamanho k. Isso cria uma estrutura inicial de itens mais valiosos.

3- Comparação e Atualização:

* Para cada elemento restante na tabela de hash, compara-se a contagem com o menor valor do heap (o elemento de menor frequência). Se a contagem for maior do que o menor valor da heap, o elemento de menor valor é removido, e o novo elemento é inserido no heap. Isso mantém a lista dos k itens de maior valor atualizada.

4- Impressão dos Resultados:

* Ao final do processo, a heap conterá os k elementos com maiores valores (frequências) da coleção de dados.

Deve-se ressaltar que o valor k mencionado para a construção do heap, está predefinido como 20, garantindo assim que seja criada uma hash com apenas 20 elementos.

## Decisões de implementação

Para se obter e salvar as palavras contidas nos arquivos, é criado uma varíavel _char_ onde se é feito a alocação de forma dinâmica do tamanho do arquivo e salvando todo conteúdo do mesmo na variável. Tal metódo utilizado para a leitura dos arquivos, apresentam tanto vantagens quanto desvantagens para a execução do programa. Algumas delas são: 

```Vantagens:``` </p>
* Leitura rápida e eficiente da variável em memória.
* Ideal para pequenos arquivos que cabem facilmente na memória.
* Menos operações de I/O de arquivo, o que pode economizar tempo.

```Desvantagens:``` </p>
* Se o arquivo for muito grande, pode consumir uma quantidade significativa de memória.
* Não é eficiente para arquivos muito grandes que não cabem na memória.

Após a análise das vantagens e desvantagens listadas, foi decidido utilizar deste metódo devido a extensa quantidade de leitura que seria executado mantendo o arquivo aberto, podendo assim causar uma lentidão no algoritmo, que por sua vez, pode ser mais prejudicial ao código do que consumir uma quantidade da memória para salvar todo conteúdo do texto em uma variável.

A leitura de stopwords por outro lado, foi feito diretamente do arquivo, devido a menor quantidade de ações referente a menor quantidade de operações realizadas com o arquivo. A seguir, podemos verificar algumas vantagens e desvantagens de tal metódo: 

```Vantagens:``` </p>
* Eficiente para arquivos muito grandes que não cabem na memória.
* Evita consumir toda a memória com o conteúdo do arquivo.
* Permite processar o arquivo em partes, o que pode ser útil para operações de busca, filtragem, etc.

```Desvantagens:``` </p>
* Pode haver mais operações de leitura/escrita no arquivo, o que pode ser mais lento.
* Pode ser mais complexo de implementar corretamente, especialmente para garantir a leitura correta de palavras, lidar com delimitadores, etc.

A ausência de certos caracteres especiais foi um dos grandes motivos para utilizar tal implementação pois não foi necessário a verificação de todos caracteres para analisar onde começa e onde se termina cada palavra. Outros fatores que influenciaram na escolha desta implementação, foi a maior facilidade de implementação e uma menor quantidade de operações de leitura no arquivo.

porque foi usado uma hash junto de um heap?

## Funções do C++ utilizadas

## Arquivos

* ```main.cpp```: Possui a função int main(), que define o local de início (entry point) do programa e retorna o exit code;
* ```Item.hpp```: Arquivo que define a classe Itens, assim como seus atributos e métodos que será compartilhado entre os arquivos do programa;
* ```Item.cpp```: Possui o corpo do construtor, destrutor e métodos da classe _Item_ definidos no arquivos _Item.hpp_;
* ```Utils.hpp```: Arquivo que define a classe Utils, assim como seus atributos e métodos que será compartilhado entre os arquivos do programa;
* ```Utils.cpp```: Possui os metódos da classe _Utils_ definidos no arquivos _Utils.hpp_;

## Código-fonte

## Exemplos de entrada e saída

## Conclusão

## Compilação e Execução

Esse código possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


# Contato

✉️ <i>leanndrosousac@gmail.com</i>
</a>
