# include <iostream>
using namespace std;

struct int_node {
    int value;
    int_node* next, * prev;
};

int main(){
    int_node* head, * tail;
    int value;

    int_node *new_node = new int_node; 
    new_node-> value = value;
    new_node-> next  = head; //aponta para o nó que ATUALMENTE é a cabeça da lista, conectando o nó a lista
    new_node-> prev  = nullptr;    // 
    if(head == nullptr)      // Caso a lista esteja vazia a ponta vai apontar para o endereço do proprio nó,  
        tail = new_node;
    else
        head->prev = new_node; // o ponteiro do nó anterior que era antiga cabeça vai apontar para o endereço do value
        head = new_node;  

}