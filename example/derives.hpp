#ifndef DERIVES_HPP
#define DERIVES_HPP
#include "base.hpp"

class DerivedA : public Base {
public:
    std::string name() {return "DerivedA";}
};

class DerivedB : public Base {
public:
    std::string name() {return "DerivedB";}
};
#endif // DERIVES_HPP
