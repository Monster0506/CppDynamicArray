#include <iostream>

#include "array.hpp"

int main() {
    Array<int> a;
    for (int i = 0; i < 200; ++i) {
        a.push_back(i);
    }

    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << std::endl;
    }
}
