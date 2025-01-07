#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__

class array_list {
private:
    int* data;
    unsigned int size, capacity; // qtd de elementos atuais, capacidade maxima da lista
    void increase_capacity() {     // função para aumentar a capacidade a lista
        int* new_array = new int[this->capacity*2]; // cria array com capacidade maior do que a atual, dobro do tamanho atual
        for (int i = 0 ; i < this->size ; i++){
            new_array[i] = this->data[i]; // adiciona os elementos que compõe a array anterior (data)
        }
        int* old_array = this->data;
        delete[] old_array;    // Elimina a antiga array
        this->capacity *= 2;  // Atualiza a capacidade atual da array   

    }
public:
    array_list() { // método construtor
        data = new int[8];
        this->size = 0;
        this->capacity = 8;
    }
    ~array_list() { // método destrutor
        delete[] data;
    }
    unsigned int size() { // Retorna a quantidade de elementos armazenados
        return this->size;
    }
    unsigned int capacity() { // Retorna o espaço reservado para armazenar os elementos
        return this->capacity;
    }
    double percent_occupied() { // Retorna um valor entre 0.0 a 1.0 com o percentual de memória usada.
        
    } 
    bool insert_at(unsigned int index, int value) { // Insere elemento no índice index
        if(index > this->size) // se o index for maior que o tamanho do vetor, será inválido
            return false;
        if(this->size == this->capacity) // caso não seja inválido, mas houver necessidade de aumentar a capacidade
            increase_capacity();
        int *new_array = this->data; // vetor para salvar os valores do vetor principal
        for (int i = index ; i < this->size ; i++){ // inicia o loop no indice oferecido
            if (i == index){ // adicionando valor no index oferecido
                new_array[index] = value;
            }else{
                new_array[i] = this->data[i];
            }
        }
        delete [] this->data;
        this->data = new_array; // colocando o novo vetor no vetor principal
        this->size++; // atualizando tamanho do vetor;
        return true;
    } 
    bool remove_at(unsigned int index) { // Remove elemento do índice index
        if (index >= this->size)
            return false; // Não removeu
        for (int i = index + 1; i < this->size; ++i) {
            this->data[i - 1] = this->data[i];
        }
        this->size--;
        return true; // Removeu
    }
    int get_at(unsigned int index) { // Retorna elemento no índice index, -1 se índice inválido
        if ((index >= this->size) or (index < 0)) // verifica se o índice é válido
            return -1;
        return this->data[index];
    }
    void clear() { // Remove todos os elementos, deixando o vetor no estado inicial
        int *new_data = new int[8]; // vetor novo representando estado inicial
        delete[] this->data; // deleta o vetor antigo
        this->data = new_data; // vetor limpo
    } 
    void push_back(int value) { // adiciona elemento ao final do vetor
        if (this->size == this->capacity)
            increase_capacity();
        this->size++; // atualiza o size
        this->data[this->size] = value; 
    }
    void push_front(int value) {// Adiciona um elemento no ``início'' do vetor
        int *new_array = new int[this->capacity+1]; // cria novo vetor com capacidade maior
        for(int i = 1 ; i < this->size ; i++)
            new_array[i] = data[i];
        delete[] this->data; 
        new_array[0] = value; // adiciona o elemento no inicio do vetor
        this->data = new_array; // salva no *vetor  'principal'
        this->capacity ++; // atualiza a capacidade
        this->size ++; // atualiza o size
    }// Achei de melhor desempenho fazer tudo aqui do que realizar um increase, pois se eu realizasse um increase quando chegasse aqui teria que realizar mais um for para mover os elementos
    bool pop_back() {// Remove um elemento do ``final'' do vetor
        if (0 == this->size)
            return false; // Não removeu
        int *new_array = new int[this->capacity]; // cria novo vetor com capacidade maior
        for(int i = 0 ; i < this->size-1 ; i++)    // for realizado até o penúltimo elemento
            new_array[i] = data[i];
        delete[] this->data; // limpa a memória
        this->data = new_array; // salva no *vetor  'principal'
        this->size --; // atualiza o size
        return true; // removeu
    } 
    bool pop_front(){ // Remove um elemento do ``início'' do vetor
        if (0 == this->size)
            return false; // Não removeu
        int *new_array = new int[this->capacity-1]; // cria novo vetor com capacidade menor
        for(int i = 1 ; i < this->size-1 ; i++)     // for realizado a partir do segundo elemento do vetor
            new_array[i] = data[i];
        delete[] this->data; // limpa a memória
        this->data = new_array; // salva no *vetor  'principal'
        this->size --; // atualiza o size
        return true; // removeu
    } 
    int back(){// Retorna o elemento do ``final'' do vetor
        return this->data[this->size];
    } 
    int front(){// Retorna o elemento do ``início'' do vetor
        return this->data[0];
    } 
    bool remove(int value){ // Remove value do vetor caso esteja presente
        for (int index = 0 ; index < size ; index++){
            if(data[index] == value){ // verifica se o valor está no vetor
                for (int i = index + 1; i < this->size; ++i) {
                    this->data[i - 1] = this->data[i];
                }
                this->size--;
                return true;
            } 
        }
        return false; // se percorrer o vetor inteiro e não encontrar o valor, então retorna false
    }
    int find(int value) {   // Retorna o índice de value, −1 caso value não esteja presente
        for (int index = 0 ; index < this->size ; index++){
            if(value == this->data[index])
                return index;
        }
        return -1;
    } 
    int count(int value) {  // Retorna quantas vezes value occorre no vetor
        int cont = 0;
        for (int i = 0 ; i < this->size ; i++){
            if(this->data[i] == value) // verifica se o valor está no vetor
                cont++;
        }
        return cont; // retorna a quantidade de vezes que o valor aparece
    } 
    int sum() { // Retorna a soma dos elementos do vetor
        int soma = 0;
        for (int i = 0 ; i < this->size ; i++){
            soma += this->data[i];
        }
        return soma;
    } 
};

#endif // __ARRAY_LIST_IFRN__