# Projeto de Algoritmos
> O objetivo desse projeto é implementar biblioteca de classes para manipulação de um vetor dinâmico de números inteiros. Sendo elas duas classes distintas, uma implementada com alocação dinâmica de arrays, realocando mais memória, quando necessário, e outra implementada com lista duplamente ligada.

Tópicos presente neste documento:
 1. [Estrutura do projeto](#struct)
 2. [Como realizar testes](#tests)
 3. [Desempenho](#performance)
 4. [Aprendizados](#learnings)
 5. [Conclusão](#conclusion)

*******

<div id='struct'/>  

## Estrutura do projeto:  
O projeto está separado em dois diretórios de classes diferentes: ArrayList baseado em arrays dinâmicos e LinkedList baseado em nós interligados. Ambas com três formas distintas de aumento de array implementadas:

1. Capacidade inicial de 100 (cem) e aumento de 100 cada vez que precisar de mais -> "array_list1.hpp" e "linked_list1.hpp"
2. Capacidade inicial de 1000 (mil) e aumento de 1000 cada vez que precisar de mais -> "array_list2.hpp" e "linked_list2.hpp"
3. Capacidade inicial de 8 (oito) e aumento de duplica cada vez que precisar de mais -> "array_list3.hpp" e "linked_list3.hpp"

Dentro de cada diretório estão localizado os casos tests utilizados, pastas contendo o arquivo-main utilizado para o teste de cada método implementado, assim como também um arquivo.txt contendo o resultado dos testes realizados.
Seguindo a seguinte organização:


``` php
    ArrayList/
    |__ tests-nome-do-método
        |__ test-nome-do-método-array-list-01.cpp
        |__ test-nome-do-método-array-list-02.cpp
        |__ test-nome-do-método-array-list-03.cpp
        |__ resultado-tests.txt
    |__ array_list1.hpp
    |__ array_list2.hpp
    |__ array_list3.hpp

    LinkedList/
    |__ tests-nome-do-método
        |__ test-nome-do-método-linked-list-01.cpp
        |__ test-nome-do-método-linked-list-02.cpp
        |__ test-nome-do-método-linked-list-03.cpp
        |__ resultado-tests.txt
    |__ linked_list1.hpp
    |__ linked_list2.hpp
    |__ linked_list3.hpp
  
```
<div id='tests'/>  

## Como realizar testes: 

-> Baixar o arquivo contendo todos os diretórios; </br>
-> Abrir o diretório raiz da classe que deseja executa (ArrayList ou LinkedList)
``` cpp
cd ArrayList
```
-> Compilar: 
``` cpp
g++ -Wall -o programa nome-da-pasta-do-arquivo/nome-do-arquivo -I.
./programa < Casos-testes/nome-da-pasta-de-teste/e1.txt >> nome-do-arquivo-que-deseja-salvar.txt 2>&1
```
Exemplo:
``` cpp
g++ -Wall -o programa test-pop-front/test-popfront-array-list-01.cpp -I.
./programa < tests/remove/e1.txt >> test-pop-front/resultado-tests.txt 2>&1
```
-> O resultado do teste será encaminhado para o resultado-tests.txt, mostrando as informações sobre o return do método e o tempo de execução;

<div id='performance'/>  

## Desempenho: 
O gráfico a seguir representa o desempenho e o tempo de execução das três formas distintas de aumento de array implementadas. O método Push-Back foi a implementação escolhida como parâmetro para essa análise por ser o método principal utilizado para incrementar os vetores nas classes de testes dos métodos:

<img src="gráfico.png">
