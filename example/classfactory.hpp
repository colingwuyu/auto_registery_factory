#ifndef CLASSFACTORY_HPP
#define CLASSFACTORY_HPP
#include "derives.hpp"
#include "factory.hpp"
#include <string>
// Register derived types
//REGISTER_TYPE_HPP(DerivedA,std::string, "DerivedA", Base)
//REGISTER_TYPE_HPP(DerivedB,std::string, "DerivedB", Base)
//REGISTER_TYPE_HPP(DerivedA,int, 1, Base)
//REGISTER_TYPE_HPP(DerivedB,int, 2, Base)

REGISTER_FACTORY_HPP(DerivedA, Base, std::string,"DerivedA")
REGISTER_FACTORY_HPP(DerivedB, Base, std::string,"DerivedB")
//REGISTER_FACTORY(DerivedA, Base, int, 1)
//REGISTER_FACTORY(DerivedB, Base, int, 2)

#endif // CLASSFACTORY_HPP
