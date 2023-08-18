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

* K está definido previamente no código como uma constante de tamanho 20;

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

Ao se iniciar o programa, foi preciso realizar a leitura das stopwords e adicionadas e um _unordered_set_. Após a leitura das stopwords, é necessário realizar a leitura do arquivo onde o mesmo foi realizado abrindo o arquivo de forma binária, permitindo assim pegar todo o conteúdo contido no arquivo e aloca-lo diretamente na memória.

A presença de caracteres especiais e a codificação do texto podem dificultar a leitura do arquivo quando tratados em ASCII. Se o texto estiver em uma codificação específica, é crucial assegurar que a leitura seja feita corretamente com o devido tratamento desses caracteres. Portanto, para lidar com a leitura de caracteres especiais, optou-se por utilizar a codificação UTF-8.

A leitura do arquivo pode ser sensível às diferenças entre letras maiúsculas e minúsculas, o que pode levar a falhas na correspondência. Por exemplo, ao procurar por "palavra", a substring "Palavra" não seria encontrada em um contexto sensível a maiúsculas e minúsculas. Para abordar isso, a função tolower() foi aplicada a todos os caracteres, garantindo que todas as letras fossem consideradas como minúsculas. Isso elimina a distinção entre letras maiúsculas e minúsculas.

Para a criação do heap foram utilizadas 3 funçãoes principais sendo elas:</p>
```make_heap```: responsável pela montagem do heap quando o mesmo estiver com todos os k elementos.</p>
```push_heap```: responsável por adicionar um novo elemento ao heap e garantir que as propriedades do heap sejam mantidas.</p>
```pop_heap```: responsável por remover o elemento no topo de um heap e, em seguida, reorganizar a estrutura do heap para restaurar suas propriedades após a remoção.</p>

Para a criação de uma hash foi utilzado o _unordered_map_, uma classe da biblioteca padrão do C++ que implementa uma tabela de hash, uma estrutura de dados que permite armazenar pares de chave-valor de forma eficiente e oferecer acesso rápido aos valores com base em suas chaves.

Para se realizar a leitura das palavras contidas nos textos e salva-las dentro da hash, foi feito a leitura de caractere por caractere construindo assim, as palavras que podem ser analisado os finais de cada palavra apardir do "\n", pois quando o mesmo for encontrado significa que foi alcançado o final de uma linha e assim, uma palavra foi totalmente construída.

Além disso, é importante observar que todas as sentenças presentes no arquivo de entrada serão finalizadas com ".", "!" ou "?", como está sendo lido um único caractere por vez, sempre que encontrarmos algumas das sentenças mencionadas pdemos concluir que a construção da palavra foi finalizada

Além dos espaços, sinais de pontuação e quebras de linha, não foram incluídos outros caracteres como parte das palavras, sendo eles:</p>
* ```,```</p>
* ```(```</p>
* ```)```</p>
* ```;```</p>
* ```/```</p>
* ```:```</p>
* ```—```</p>
* ```"```</p>
* ```'```</p>

Após a construção de cada palvra, era verificado se a mesma era uma stopword e em caso de stopword a palavra era simplesmente descartada, caso contrário a palavra era incluida na hash sendo ela uma chave para acessar um valor inteiro, sendo esse valor a frequência da palavra nos textos fornecidos.

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

Foi decidido fazer tal implementação utilizando uma hash e um heap devido a complexidade do algoritmo, pois caso implementado adequadamente, o custo deste metódo é de O(n log k), onde n é o tamanho da coleção de dados e k é o número de itens mais relevantes. Por outro lado, caso decidido salvar todas as palavras no map e ordena-lo de acordo com a frequência das palavras para achar os top k elementos, teríamos um custo de O(n log n), sendo este um custo mais significativo para o algoritmo.

Para a impleeentação do heap, foi escolhido uma estrutura de heap mínimo devido a praticidade para encontrar o menor valor do heap caso contrário de um heap máximo, que seria mais trabalhoso para se encontrar o a palavra com menor frequência. Utilizando-se um heap mínimo, podemos a todo momento verificar e fazer a remoção apenas da raiz tornando assim mais eficiente a remoção do elemento.

## Funções do C++ utilizadas

```unordered_map```</p>

```unordered_set```</p>

```make_heap```</p>

```push_heap```</p>

```pop_heap```</p>

## Arquivos

* ```main.cpp```: Possui a função int main(), que define o local de início (entry point) do programa e retorna o exit code;
* ```Item.hpp```: Arquivo que define a classe Itens, assim como seus atributos e métodos que será compartilhado entre os arquivos do programa;
* ```Item.cpp```: Possui o corpo do construtor, destrutor e métodos da classe _Item_ definidos no arquivos _Item.hpp_;
* ```Utils.hpp```: Arquivo que define a classe Utils, assim como seus atributos e métodos que será compartilhado entre os arquivos do programa;
* ```Utils.cpp```: Possui os metódos da classe _Utils_ definidos no arquivos _Utils.hpp_;

## Código-fonte

### main.cpp

Este trecho de código em C++ representa o arquivo "main.cpp". A função main() é responsável por iniciar o programa, processar os arquivos de entrada, contar a frequência das palavras, selecionar as palavras mais frequentes usando um heap mínimo e imprimir os resultados, bem como calcular o tempo de execução.

### Item.hpp e Item.cpp

O arquivo Item.hpp contém o cabeçalho que define a classe Item(Considere a classe Item como os dados da palavra). Nele, estão os atributos relacionados ao nome e à frequência de cada palavra, bem como os métodos para acessar e modificar esses atributos. Essa classe permite representar e gerenciar as informações de cada item, como seu nome e com que frequência ele aparece na coleção de dados. Aqui está uma explicação das principais utilidades e funcionalidades da classe Utils:

* ```Item(wstring nome, int frequencia)``` Construtor da classe Item que aceita dois parâmetros: o nome da palavra (uma string ampla) e a sua frequencia (um número inteiro). Ele é usado para criar um novo objeto Item com os valores fornecidos.

* ```Item()``` Construtor padrão da classe Item. Ele cria um objeto Item com valores padrão para o nome e a frequencia.

* ```void setNome(wstring nome)``` Função que define o nome do item. Ela aceita uma string ampla nome como parâmetro e atribui esse valor ao atributo privado nome da classe.

* ```wstring getNome()``` Função que obtém o nome do item. Ela retorna a string ampla que representa o nome do item.

* ```void setFrequencia(int frequencia)``` Função que define a frequencia do item. Ela aceita um número inteiro frequencia como parâmetro e atribui esse valor ao atributo privado frequencia da classe.

* ```int getFrequencia()``` Função que obtém a frequencia do item. Ela retorna o valor inteiro que representa a frequência do item.

* ```bool operator<(const Item& other) const``` Sobrecarga do operador de comparação <. Essa função permite comparar dois objetos Item para determinar qual deles é "menor" com base em algum critério de comparação (neste caso, a frequência do item). Ela retorna true se o item atual for considerado "menor" do que o outro item passado como parâmetro.

Essas funções permitem criar e manipular objetos da classe Item, definindo seus atributos e realizando comparações entre eles. Através de funções de "get" e "set", os valores dos atributos podem ser acessados e modificados de maneira controlada.

### Utils.hpp e Utils.cpp

A classe Utils em "Utils.hpp" e "Utils.cpp" desempenha um papel fundamental ao oferecer funcionalidades auxiliares para facilitar operações comuns e complexas no programa. Esta classe foi projetada para encapsular diversas funções que não estão diretamente relacionadas à lógica principal da ordenação, mas que são essenciais para o funcionamento do programa como um todo.

Em "Utils.hpp" estão definidos os cabeçalhos dos métodos da classe Utils, enquanto em "Utils.cpp" estão as implementações concretas desses métodos. Aqui está uma explicação das principais utilidades e funcionalidades da classe Utils:

* ```wchar_t* getText(const locale loc, string name)``` O método _getText_, recebe como parâmetro uma constante do tipo locale, tal parâmetro garante que as operações de leitura e manipulação de texto sejam sensíveis à localização, também é passado uma string chamada name que é referente ao nome do arquivo que será feito a leitura. A função _getText_, oferece a capacidade de ler um arquivo de texto e retornar seu conteúdo como um array de caracteres wchar_t. Isso é crucial para processar e analisar o conteúdo dos arquivos de entrada que contêm os textos. Além disso, a classe lida com a codificação UTF-8, garante que caracteres especiais sejam tratados corretamente.

* ```unordered_set<wstring> getStopWords(const locale loc)``` O método _getStopWords_, recebe como parâmetro uma constante do tipo locale, tal parâmetro garante que as operações de leitura e manipulação de texto sejam sensíveis à localização. A função getStopWords, lê um arquivo contendo palavras de parada (stop words), que são palavras que geralmente são filtradas em processos de análise de texto, como na contagem de frequência de palavras. Essas palavras incluem termos como "e", "de", "para", que são frequentes e geralmente não fornecem informações significativas, retorando todas stopwords obtidas em uma estrutura chamada _unordered_set_.

* ```void printHeap(vector<Item> heap);``` O método _printHeap_, recebe como parâmetro um vector de Item que representa o heap. A função _printHeap_, é responsável por imprimir os elementos contidos em um heap, sendo ele o heap que armazena as palavras k mais frequentes. Isso é importante para visualizar os resultados do processamento das palavras e verificar se a lógica do heap está funcionando corretamente.

A classe Utils é uma forma eficiente de organizar essas funcionalidades auxiliares, isolando-as do restante do código e promovendo a reutilização de código. Ao reunir essas operações em uma única classe, você está seguindo princípios de modularidade e coesão, tornando o código mais organizado, legível e manutenível. Além disso, a classe ajuda a abstrair detalhes de implementação e proporciona uma interface mais intuitiva para o uso dessas funcionalidades em outras partes do programa.

## Exemplos de entrada e saída

Ao se compilar e iniciar a execução do programa, o algoritmo fornece uma mensagem na tela perguntando a quantidade de arquivos que o usuário deseja fazer a leitura. Foram realizados dois testes, o primeiro teste foi utilizado lendo apenas o arquivo _input1.data_. O segundo teste foi realizado utilizando dois arquivos sendo eles: _input1.data_ e _input.data_. A seguir segue o exemplo dos 2 arquivos de teste: </p>

#Imagem 1

Após a execução do programa é mostrado na tela os top k elementos, sendo eles as k palavras mais frequentes nos arquivos. Segue abaixo os exemplos de saídas para cada um dos casos de testes: </p>

#Imagem 2

Como podemos observar nos exemplos mostrados acima, vemos que o heap está ordenado na forma de um heap mínimo, onde o nó pai é menor que os seus filhos direito e esquerdo, tendo o filho esquerdo na posição 2i e o filho direito na posição 2i+1, referente ao nó pai. Também podemos verificar que as palavras listadas na saída do programa, são as k palavras mais frequentes presentes nos textos.

## Máquina de teste

<table style="width: 100%;" border="1">
  <tr align="center">
    <td colspan="2">
      <div>
        <br>
          <p class="sizeText color">Notebook Acer</p>
        <br>        
      </div>
    </td>
  <tr>
  <tr align="center">
    <td>
      <div>
        <br>
          <p class="sizeText color">RAM</p>
        <br>
      </div> 
    </td>
    <td>
      <br>
        <p class="sizeText color">6GB DDR3</p>
      <br>
    </td>
  </tr>
  <tr align="center">
    <td style="width: 20%;">
      <p class="sizeText color">
        <br>
          <p class="sizeText color">SO</p>
        <br>
      </p>
    </td>
    <td >
      <br>
        <p class="sizeText color">Windows 10, 64bits</p>
      <br>
    </td>
  </tr>
  <tr align="center">
    <td style="width: 20%;">
      <br>
        <p class="sizeText color">    
          CPU
        </p>
      <br>
    </td>
    <td>
      <br>
        <p class="sizeText color">Intel core i5 4° geração 1,70GHz</p>
      <br>
    </td>
  </tr>
</table>

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
