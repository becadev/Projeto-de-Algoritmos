# Projeto de Algoritmos
> O objetivo desse projeto é implementar biblioteca de classes para manipulação de um vetor dinâmico de números inteiros. Sendo elas duas classes distintas, uma implementada com alocação dinâmica de arrays, realocando mais memória, quando necessário, e outra implemenatada com lista duplamente ligada.

Tópicos presente neste documento:
 1. [Estrutura do projeto:](#struct)
 2. [Implementações:](#implementation)
 3. [Como realizar testes:](#tests)
 4. [Desempenho](#performance)
 5. [Aprendizados](#learnings)
 6. [Conclusão](#conclusion)

*******

<div id='struct'/>  

## Estrutura do projeto:  
O projeto está separado em dois diretórios de classes diferentes (ArrayList e LinkedList) com três formas distintas de aumento de array implementadas:

1. Capacidade inicial de 100 (cem) e aumento de 100 cada vez que precisar de mais -> "array_list1"
2. Capacidade inicial de 1000 (mil) e aumento de 1000 cada vez que precisar de mais -> "array_list2"
3. Capacidade inicial de 8 (oito) e aumento de duplica cada vez que precisar de mais -> "array_list3"

Dentro de cada diretório estão localizado os casos tests utilizados, pastas contendo o arquivo-main utilizado para o teste de cada método implementado, assim como também um arquivo.txt contendo o resultado dos testes realizados.
Seguindo a seguinte organização:

``` php
    ArrayList/
    |__ 
   
