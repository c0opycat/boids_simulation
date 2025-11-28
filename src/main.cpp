//
// Created by arthur on 28/11/2025.
//

#include <iostream>
#include <ostream>
#include "DynamicArray.h++"

int main(int argc, char *argv[]) {
    std::cout << "Hello World!" << std::endl;

    DynamicArray<int> array;
    array.push_back(1);
    array.push_back(2);
    array.push_back(3);

    array.print();

    const int a = array[1];
    std::cout << a << std::endl;

    return 0;
}
