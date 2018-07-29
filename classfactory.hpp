#ifndef CLASSFACTORY_HPP
#define CLASSFACTORY_HPP
#include "derives.hpp"
#include "factory.hpp"

class BaseFactory : Factory<Base> {};

// Register derived types
REGISTER_TYPE_HPP(DerivedA,Base)
REGISTER_TYPE_HPP(DerivedB,Base)

#endif // CLASSFACTORY_HPP
