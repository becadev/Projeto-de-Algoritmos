#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__
#include <sstream>
#include <iomanip>
class array_list {
private:
    int* data;
    unsigned int size_, capacity_; // qtd de elementos atuais, capacidade maxima da lista
    void increase_capacity_() {     // função para aumentar a capacidade a lista
        int* new_array = new int[this->capacity_+100]; // cria array com capacidade maior do que a atual, dobro do tamanho atual
        for (unsigned int i = 0 ; i < this->size_ ; i++){
            new_array[i] = this->data[i]; // adiciona os elementos que compõe a array anterior (data)
        }
        delete[] this->data;    // Elimina a antiga array
        this->data = new_array;
        this->capacity_ += 100;  // Atualiza a capacidade atual da array   
    }
public:
    array_list() { // método construtor
        data = new int[100];
        this->size_ = 0;
        this->capacity_ = 100;
    }
    ~array_list() { // método destrutor
        delete[] data;
    }
    unsigned int size() { // Retorna a quantidade de elementos armazenados
        return this->size_;
    }
    unsigned int capacity() { // Retorna o espaço reservado para armazenar os elementos
        return this->capacity_;
    }
    double percent_occupied() { // Retorna um valor entre 0.0 a 1.0 com o percentual de memória usada.
        if(this->size_ == 0)
            return 0.0;
        return static_cast<double>((this->capacity_)/(this->size_))/100;
    } 
    bool insert_at(unsigned int index, int value) { // Insere elemento no índice index
        if(index > this->size_) // se o index for maior que o tamanho do vetor, será inválido
            return false;
        if(this->size_ == this->capacity_) // caso não seja inválido, mas houver necessidade de aumentar a capacidade
            increase_capacity_();
        for (unsigned int i = this->size_ ; i > index ; i--){ // inicia o loop no indice oferecido
            if (i == index){ // adicionando valor no index oferecido
                this->data[i] = this->data[i-1]; // move os elementos de posição
            }
        }
        this->data[index] = value; // colocando value no index oferecido
        this->size_++; // atualizando tamanho do vetor;
        return true;
    } 
    bool remove_at(unsigned int index) { // Remove elemento do índice index
        if (index >= this->size_)
            return false; // Não removeu
        for (unsigned int i = index + 1; i < this->size_; ++i) {
            this->data[i - 1] = this->data[i];
        }
        this->size_--;
        return true; // Removeu
    }
    int get_at(unsigned int index) { // Retorna elemento no índice index, -1 se índice inválido
        if ((index >= this->size_) or (index < 0)) // verifica se o índice é válido
            return -1;
        return this->data[index];
    }
    void clear() { // Remove todos os elementos, deixando o vetor no estado inicial
        int *new_data = new int[8]; // vetor novo representando estado inicial
        delete[] this->data; // deleta o vetor antigo
        this->data = new_data; // vetor limpo
    } 
    void push_back(int value) { // adiciona elemento ao final do vetor
        if (this->size_ == this->capacity_)
            increase_capacity_();
        this->data[this->size_] = value; //Adiciona o elemento ao final do vetor
        this->size_++; // atualiza o size_
    }
    void push_front(int value) {// Adiciona um elemento no ``início'' do vetor
        if(this->capacity_ == this->size_){
            increase_capacity_();
        }
        for (unsigned i = this->size_ ; i > 0 ; i--){ // move os elementos deixando o índice zero vago
            this->data[i] = data[i-1];
        }
        this->data[0] = value;
        this->size_ ++; // atualiza o size_
    }
    bool pop_back() {// Remove um elemento do ``final'' do vetor
        if (0 == this->size_)
            return false; // Não removeu
        this->size_ --;   // atualiza o size_
        return true;      // removeu
    } 
    bool pop_front(){ // Remove um elemento do ``início'' do vetor
        if (0 == this->size_)
            return false; // Não removeu
        for(unsigned int i = 1 ; i < this->size_ ; i++)  // for realizado a partir do segundo elemento do vetor
            data[i-1] = data[i];
        this->size_ --; // atualiza o size_
        return true; // removeu
    } 
    int back(){// Retorna o elemento do ``final'' do vetor
        return this->data[this->size_-1];
    } 
    int front(){// Retorna o elemento do ``início'' do vetor
        return this->data[0];
    } 
    bool remove(int value){ // Remove value do vetor caso esteja presente
        for (unsigned int index = 0 ; index < size_ ; index++){
            if(data[index] == value){ // verifica se o valor está no vetor
                for (unsigned int i = index + 1; i < this->size_; ++i) {
                    this->data[i - 1] = this->data[i];
                }
                this->size_--;
                return true;
            } 
        }
        return false; // se percorrer o vetor inteiro e não encontrar o valor, então retorna false
    }
    int find(int value) {   // Retorna o índice de value, −1 caso value não esteja presente
        for (unsigned int index = 0 ; index < this->size_ ; index++){
            if(value == this->data[index])
                return index;
        }
        return -1;
    } 
    int count(int value) {  // Retorna quantas vezes value occorre no vetor
        int cont = 0;
        for (unsigned int i = 0 ; i < this->size_ ; i++){
            if(this->data[i] == value) // verifica se o valor está no vetor
                cont++;
        }
        return cont; // retorna a quantidade de vezes que o valor aparece
    } 
    int sum() { // Retorna a soma dos elementos do vetor
        int soma = 0;
        for (unsigned int i = 0 ; i < this->size_ ; i++){
            soma += this->data[i];
        }
        return soma;
    } 
};

#endif // __ARRAY_LIST_IFRN__