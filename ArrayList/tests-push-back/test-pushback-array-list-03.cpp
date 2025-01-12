#include <iostream>
#include <chrono>
#include "array_list3.hpp"

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
    int unsigned resultado = l1.size();
    auto end = std::chrono::high_resolution_clock::now(); // nanosegundos
    auto elapsed = end - beg;
    if (not (resultado == n)) {
        std::cerr << "[ERROR] check push_back method!\n";
        exit(1);
    }
    std::cerr << "[INFO] " << "Elapsed time for "
        << n << " pushes back: "
        << elapsed.count() << std::endl;
    return 0;
}