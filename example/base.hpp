#ifndef BASE_HPP
#define BASE_HPP
#include <string>
#include "factory.hpp"

class Base {
public:
    Base(){}
    virtual std::string name() {return "Base";}
};


//typedef Loki::SingletonHolder<
//            Factory< std::string,
//                     boost::function< boost::shared_ptr< Base >() >
//                   >,
//            Loki::CreateStatic > SomeFactory;
/*#define REGISTER_SOME_FACTORY( type ) \
    static bool BOOST_PP_CAT( type, __regged ) = \
    SomeFactory::Instance().RegisterCreator( BOOST_PP_STRINGIZE( type ), boost::bind( &boost::make_shared< type >, _1 ) );
*/

#endif // BASE_HPP
