#include <iostream>
#include <chrono>
#include "array_list1.hpp"

int main() {
    unsigned int n;
    int value;
    std::cin >> n;
    std::cin >> value;
    array_list l1; // Objeto

    auto beg = std::chrono::high_resolution_clock::now();
    for (unsigned int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        l1.push_back(x); // adicionando elemento ao final do vetor 
    }
    int resultado = l1.find(value);
    auto end = std::chrono::high_resolution_clock::now(); // nanosegundos
    auto elapsed = end - beg;

    if (resultado != -1){
        std::cerr << "[INFO] " << "Elapsed time to find value " << resultado
        << ": " << elapsed.count() << std::endl;
    }else{
        std::cerr << "[INFO] " << "Elapsed time to not find value " << resultado
        << ": " << elapsed.count() << std::endl;
    }
    return 0;
}