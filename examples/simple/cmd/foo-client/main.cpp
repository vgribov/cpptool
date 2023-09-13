#include <iostream>

#include "foo/foo.hpp"

int main(void)
{
    std::cout << "Foo: " << foo::getFoo() << "\n";
    return 0;
}
