#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__


class linked_list {
    private:
        struct int_node {
            int value;
            int_node* next, * prev;
        };
        int_node* head, * tail;        // armazena o primeiro e o ultimo elemento da lista 
        unsigned int size_, capacity_;
    public:
        linked_list() { // contrutor
            this->head = nullptr;
            this->tail = nullptr;
            this->size_ = 0;
        }
        ~linked_list() {
           int_node  *old_node = new int_node;
            // while : enquanto o proximo do atual não for igual a null
            // vai deletando nó por nó
        }
        unsigned int size() { // Retorna a quantidade de elementos armazenados
            return this->size_;
        } // Desempenho Big(O) : O(1)
        // unsigned int capacity() // Retorna o espaço reservado para armazenar os elementos --> não há necessidade de ter esse método já que os elementos não inseridos em ordem e também não estão dinamicamente armazenado em um espaço da memória
        double percent_occupied() {} // Retorna um valor entre 0.0 a 1.0 com o percentual da memória usada.
        bool insert_at(unsigned int index, int value) {} // Insere elemento no índice index
        bool remove_at(unsigned int index) {} // Remove elemento do índice index

        int get_at(unsigned int index) { // Retorna elemento no índice index, −1 se índice inválido
            if (index > this->size_)
                return -1;
            int_node* atual = this->head;
            for (int i = 0; i < index ; i++){ // percorrer toda lista até chega ao indice desejado
                atual = atual-> next;
            }
            return atual->value; // retornar o valor presente no index oferecido
        } // Desempenho Big(O) : O(n)
        void clear() { // Remove todos os elementos, deixando o vetor no estado inicial
            int_node* atual = this->head; // 
            while(atual != nullptr){ // percorrer a lista apagando item por item
                int_node * excluir = atual; // cria um ponteiro para o elemento que será excluído
                atual = excluir -> next; // o atual que será excluído aponta para o endereço do próximo da lista que será excluído
                delete excluir;
            }
            this->size_ = 0;
        }  // Desempenho Big(O) : O(n)
        void push_back(int value) { // Adiciona um elemento no ``final'' do vetor
            int_node * new_node = new int_node;
            new_node -> value = value;
            new_node -> next  = nullptr;
            new_node -> prev  = this-> tail; // Aponta para o final da lista de antes, head = [[prev], [v1] , [next]]
            if(this->head  == nullptr)       // Caso a lista esteja vazia o head vai apontar para o endereço do proprio nó
                this->head = new_node; 
            else // Caso não for vazia, o tail e o next irá apontar para o próprio nó
                this->tail->next = new_node;
            this->tail = new_node;
            this->size_++;
        } // Desempenho Big(O) : O(1)
        void push_front(int value) { // Adiciona um elemento no ``início'' do vetor
            int_node *new_node = new int_node; 
            new_node-> value = value;
            new_node-> next  = this->head; // O new_node se torna a cabeça da lista
            new_node-> prev  = nullptr;    // O Prev se torna nulo por new_node ser o novo primeiro elemento da lista
            if(this->head == nullptr)      // Caso a lista esteja vazia a cauda vai apontar para o endereço do proprio nó,  
                this->tail = new_node;
            else
                this->head->prev = new_node; // o 
            this->head = new_node;
            this->size_++;
        } // Desempenho Big(O) : O(1)
        bool pop_back() { // Remove um elemento do ``final'' do vetor
            if (this->size_ == 0){
                return false;
            }
            if (this->head == this->tail){ // caso a lista tennha apenas um único elemento
                delete this->head;
                this-> head = nullptr;
                this-> tail = nullptr;
                this->size_ --;
                return true;
            }
            this->tail = this->tail->prev; // o tail da lista agora será o endereço do anterior da cauda, ou seja o penultimo item da lista
            delete this->tail->next;       // irá deletar o proximo elemento do penúltimo da lista que agora será o ultimo
            this->tail->next = nullptr;    // apontará para nulo por ser o ultimo da lista
            this->size_ --;
            return true;
        } // Desempenho Big(O) : O(1)
        bool pop_front() {// Remove um elemento do ``início'' do vetor
            if (this->size_ == 0){ // verifica se há elementos na lista
                return false;
            }
            if (this->head == this->tail){ // caso a lista tennha apenas um único elemento
                delete this->head;
                this->head = nullptr;
                this->tail = nullptr;
                this->size_ --;
                return true;
            }
            this->head = this->head->next;
            delete this->head->prev;
            this->head->prev = nullptr;
            this->size_ --;
            return true;
        } // Desempenho Big(O) : O(1)
        int back(){ // Retorna o elemento do ``final'' do vetor
            return this->tail->value;
        } // Desempenho Big(O) : O(1)
        int front(){ // Retorna o elemento do ``início'' do vetor
            return this->head->value;
        } // Desempenho Big(O) : O(1)
        bool remove(int value){ // Remove value do vetor caso esteja presente
            int_node* atual = this->head; 
            for (int i = 0 ; i < size_ ; i++){
                if(atual->value == value){
                    return true;
                }
                int_node * lookup = atual;  // cria um ponteiro para o elemento que para procurar o ultimo elemento
                atual = lookup -> next;     // o atual será o próximo elemento da lista
            }
            int_node* antecessor = atual->prev;
            antecessor->next = atual->next;
            delete atual;
            return false;
        } // Desempenho Big(O) : O(n)
        int find(int value) { // Retorna o índice de value, −1 caso value não esteja presente

        } 
        int count(int value) {} // Retorna quantas vezes value occorre no vetor
        int sum() {} // Retorna a soma dos elementos do vetor
};
#endif // __LINKED_LIST_IFRN__