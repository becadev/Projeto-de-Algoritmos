#include <iostream>
#include <chrono>
#include "array_list1.hpp"

int main() {
    unsigned int n;
    std::cin >> n;
    array_list l1; // Objeto

    auto beg = std::chrono::high_resolution_clock::now();
    for (unsigned int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        l1.push_back(x); // adicionando elemento ao final do vetor 
    }
    auto end = std::chrono::high_resolution_clock::now(); // nanosegundos
    auto elapsed = end - beg;

    std::cerr << "[INFO] " << "Elapsed time to return the sum " << l1.sum() << " of the vector " << ": " << elapsed.count() << std::endl;
    return 0;
}