#include <iostream>

#include "foo.hpp"

int main(void) {
    auto want = "Foo Value";
    auto get = foo::getFoo();

    if (get != want) {
        std::cerr << "Error: getFoo() = " << get << ", want " << want << "\n";
        return 1;
    }
    std::cout << "OK\n";
}
