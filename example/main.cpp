#include "classfactory.hpp"
#include <iostream>

int main() {
    Factory<Base> bfac;
    Base * a = bfac.create("DerivedA");
    Base * b = bfac.create("DerivedB");
    std::cout << a->name() << std::endl;
    std::cout << b->name() << std::endl;
}
