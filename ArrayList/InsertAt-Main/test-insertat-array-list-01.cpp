#include <iostream>
#include <chrono>
#include "array_list3.hpp"

int main() {
    unsigned int n, index, value;
    std::cin >> n;
    std::cin >> index;
    std::cin >> value;
    array_list l1; // Objeto

    auto beg = std::chrono::high_resolution_clock::now();
    for (unsigned int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        l1.push_back(x); // adicionando elemento ao final do vetor 
    }
    auto end = std::chrono::high_resolution_clock::now(); // nanosegundos
    auto elapsed = end - beg;
    if (l1.insert_at(index, value)){
        std::cerr << "[INFO] " << "Elapsed time for "
        << "True, the value " << value << " Insert at " << index << ": " << elapsed.count() << std::endl;
    }else{
        std::cerr << "[INFO] " << "Elapsed time for "
        << "False, the value " << value << " not Insert at " << index << ": " << elapsed.count() << std::endl;
    }
    return 0;
}