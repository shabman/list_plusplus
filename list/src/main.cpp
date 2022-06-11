#include <iostream>
#include "list.hpp"

int main() {
    List<int, 10> list;
    list.push_back(5);
    std::cout << list.length() << '\n';
}