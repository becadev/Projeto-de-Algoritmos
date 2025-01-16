#include <iostream>
#include <chrono>
#include "linked_list.hpp"

int main() {
    unsigned int n, index, value;
    std::cin >> n;
    std::cin >> index;
    std::cin >> value;
    linked_list l1; // Objeto

    auto beg = std::chrono::high_resolution_clock::now();
    for (unsigned int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        l1.push_back(x); // adicionando elemento ao final do vetor 
    }
    bool resultado = l1.insert_at(index, value);
    auto end = std::chrono::high_resolution_clock::now(); // nanosegundos
    auto elapsed = end - beg;

    if (resultado){
        std::cerr << "[INFO] " << "Elapsed time for "
        << "True, the value " << value << " Insert at " << index << ": " << elapsed.count() << std::endl;
    }else{
        std::cerr << "[INFO] " << "Elapsed time for "
        << "False, the value " << value << " not Insert at " << index << ": " << elapsed.count() << std::endl;
    }
    return 0;
}