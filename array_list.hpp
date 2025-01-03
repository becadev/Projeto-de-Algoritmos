#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__

class array_list {
private:
    int* data;
    unsigned int size, capacity; // qtd de elementos atuais, capacidade maxima da lista
    void increase_capacity() {     // função para aumentar a capacidade a lista
        int* new_array_ = new int[this->capacity* 2]; // cria array com capacidade maior do que a atual, dobro do tamanho atual
        for (int i = 0 ; i < this->size ; i++){
            new_array[i] = this->data[i]; // adiciona os elementos que compõe a array anterior (data)
        }
        int* old_array = this->data;
        delete[] old_array;         // Elimina a antiga array
        this->capacity *= 2;  // Atualiza a capacidade atual da array
        // return new_array;
    }
public:
    array_list() { // método construtor
        data = new int[8];
        this->size_ = 0;
        this->capacity_ = 8;
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
    double percent_occupied() {} // Retorna um valor entre 0.0 a 1.0 com o percentual de memória usada.
    bool insert_at(unsigned int index, int value) {} // Insere elemento no índice index
    bool remove_at(unsigned int index) { // Remove elemento do índice index
        if (index >= this->size_)
            return false; // Não removeu
        for (int i = index + 1; i < this->size_; ++i) {
            this->data[i - 1] = this->data[i];
        }
        this->size_--;
        return true; // Removeu
    }
    int get_at(unsigned int index) { // Retorna elemento no índice index, −1 se índice inválido
        // TODO: Check if index is valid
        return this->data[index];
    }
    void clear() {} // Remove todos os elementos, deixando o vetor no estado inicial

    void push_back(int value) { // adiciona elemento ao final do vetor
        if (this->size_ == this->capacity_)
            increase_capacity();
        this->data[size_++] = value;
    }
    void push_front(int value) {} // Adiciona um elemento no ``início'' do vetor
    bool pop_back() {} // Remove um elemento do ``final'' do vetor
    bool pop_front() {} // Remove um elemento do ``início'' do vetor
    int back(){} // Retorna o elemento do ``final'' do vetor
    int front(){} // Retorna o elemento do ``início'' do vetor
    bool remove(int value) {} // Remove value do vetor caso esteja presente
    int find(int value) {} // Retorna o índice de value, −1 caso value não esteja presente
    int count(int value) {} // Retorna quantas vezes value occorre no vetor
    int sum() {} // Retorna a soma dos elementos do vetor
};


#endif // __ARRAY_LIST_IFRN__