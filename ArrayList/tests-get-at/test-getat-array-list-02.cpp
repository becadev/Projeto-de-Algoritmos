#include <iostream>
#include <chrono>
#include "array_list2.hpp"

int main() {
    unsigned int n;
    int value, index;
    std::cin >> n;
    std::cin >> index;
    array_list l1; // Objeto

    auto beg = std::chrono::high_resolution_clock::now();
    for (unsigned int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        l1.push_back(x); // adicionando elemento ao final do vetor 
    }
    value = l1.get_at(index);
    auto end = std::chrono::high_resolution_clock::now(); // nanosegundos
    auto elapsed = end - beg;

    if (value == -1){
        std::cerr << "[INFO] " << "Elapsed time for "
        << value << " invalid index " << ": " << elapsed.count() << std::endl;
    }else{
        std::cerr << "[INFO] " << "Elapsed time for "
        << "value index " << index << " is " << value << ": " << elapsed.count() << std::endl;
    }
    return 0;
}