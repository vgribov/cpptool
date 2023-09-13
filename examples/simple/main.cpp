#include <iostream>

#include "foo/foo.hpp"
#include "bar/bar.hpp"
#include "config.hpp"

int main(void)
{
    std::cout << "Config: " << example::config() << "\n"
              << "Foo: " << foo::getFoo() << "\n";

    std::runtime_error *err = nullptr;
    bar::doBar(&err);
    if (err != nullptr) {
        std::cerr << "bar::doBar: " << err->what() << "\n";
        return 1;
    }
    std::cout << "bar::doBar: OK\n";

    return 0;
}
