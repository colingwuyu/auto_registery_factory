#include "classfactory.hpp"
#include <iostream>

int main() {
    Factory<Base, std::string> bfac;
    Base * a = bfac.create("DerivedA");
    Base * b = bfac.create("DerivedB");
    std::cout << a->name() << std::endl;
    std::cout << b->name() << std::endl;


//    Factory<Base, int> bfac_int;
//    Base * aint = bfac_int.create(1);
//    Base * bint = bfac_int.create(2);
//    std::cout << aint->name() << std::endl;
//    std::cout << bint->name() << std::endl;
}
