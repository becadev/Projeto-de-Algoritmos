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
        l1.push_front(x); // adicionando elemento a l1
    }
    unsigned int resultado = l1.size();
    auto end = std::chrono::high_resolution_clock::now(); // nanosegundos
    auto elapsed = end - beg;
    if (not (resultado == n)) {
        std::cerr << "[ERROR] check push_front method!\n";
        exit(1);
    }
    std::cerr << "[INFO] " << "Elapsed time for "
        << n << " pushes front: "
        << elapsed.count() << std::endl;
    return 0;
}