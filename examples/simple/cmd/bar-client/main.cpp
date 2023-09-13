#include <iostream>

#include "bar/bar.hpp"

int main(void)
{
    std::runtime_error *err = nullptr;
    bar::doBar(&err);
    if (err != nullptr) {
        std::cerr << "bar::doBar: " << err->what() << "\n";
        return 1;
    }
    std::cout << "OK\n";

    return 0;
}
