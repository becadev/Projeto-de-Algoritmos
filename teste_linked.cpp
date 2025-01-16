# include <iostream>
using namespace std;

struct int_node {
    int value;
    int_node* next, * prev;
};
void increase_capacity_(int capacity, int size, int *data) {     // função para aumentar a capacidade a lista
        int* new_array = new int[capacity*2]; // cria array com capacidade maior do que a atual, dobro do tamanho atual
        for (unsigned int i = 0 ; i < size ; i++){
            new_array[i] = data[i]; // adiciona os elementos que compõe a array anterior (data)
        }
        delete[] data;    // Elimina a antiga array
        data = new_array;
        capacity *= 2;  // Atualiza a capacidade atual da array   
    }
bool insert(int value, int size, int capacity, int *data){
    if(size == capacity)
        increase_capacity_(capacity, size, data);
    for(int i = size ; i > 0 ; i--){
        if(value-1 == data[i]){
            data[i+1] = value;
            for (int i = 0 ; i < 11 ; i++){
                cout << data[i] << endl;
            }
            return true;
        }
    }
    return false;
}

int main(){
    int size, capacity, value;
    cin >> value;
    int *data = new int[10];
    for(int i = 0 ; i < 10 ; i++){
        cin >> data[i];
    }
    bool ok = insert(value, size,capacity, data);
    cout << ok;
}
