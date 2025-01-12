Forma para compilar os arquivos:

Abra a pasta raiz do tipo de Lista (ArrauList ou LinkedList):
    Ex:
        cd ArrayList

g++ -Wall -o programa nome-da-pasta-do-arquivo/nome-do-arquivo -I.
./programa < Casos-testes/nome-da-pasta-de-teste/e1.txt >> nome-do-arquivo-que-deseja-salvar.txt 2>&1

    Ex:
        g++ -Wall -o programa test-pop-front/test-popfront-array-list-01.cpp -I.
        ./programa < tests/remove/e1.txt >> test-pop-front/resultado-tests.txt 2>&1
