#include <iostream>
#include <chrono>
#include "linked_list.hpp"

int main() {
    unsigned int n;
    std::cin >> n;
    linked_list l1; // Objeto
    auto beg = std::chrono::high_resolution_clock::now();
    for (unsigned int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        l1.push_back(x); // adicionando elemento ao final do vetor 
    }
    bool resultado = l1.pop_front();
    auto end = std::chrono::high_resolution_clock::now(); // nanosegundos
    auto elapsed = end - beg;
    if (resultado){
        std::cerr << "[INFO] " << "Elapsed time for "
        << "True" << " pop front "
        << elapsed.count() << std::endl;
    }else{
    std::cerr << "[INFO] " << "Elapsed time for "
        << "False" << " pop front "
        << elapsed.count() << std::endl;
    }
    return 0;
}