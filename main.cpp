#include <iostream>
#include "list.hpp"

int main() {
    List<int, 10> list;
    list.push_back(9);
    std::cout << list.at(0) << '\n';
}