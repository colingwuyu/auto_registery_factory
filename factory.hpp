#ifndef FACTORY_HPP
#define FACTORY_HPP
//#include <boost/shared_ptr.hpp>
//#include <boost/function.hpp>
//#include <boost/bind.hpp>
//#include <boost/unordered_map.hpp>
//#include <boost/make_shared.hpp>
//#include <loki/Singleton.h>

//template< typename KeyType, class B>
//class Factory
//{

//    typedef boost::unordered_map< KeyType, boost::shared_ptr<B>() > CreatorMap;
//public:
//    Factory() {creatorMap_ = boost::shared_ptr<CreatorMap>(new CreatorMap);}
//    bool RegisterCreator(KeyType key, ProductCreatorType creator) {
//        creatorMap_->insert(std::make_pair<KeyType,ProductCreatorType>(key,creator));
//        return true;
//    }
//    boost::shared_ptr< B > Create(KeyType key) {
//        CreatorMap::iterator it = creatorMap_->find(key);
//        if(it==creatorMap_->end())
//            return 0;
//        return it->second();
//    }

//private:
//    boost::shared_ptr<CreatorMap> creatorMap_;
//};

//---------------------------------------------------------------------------------------
#include <string>
#include <map>
// object creator
template <typename BClass>
class ObjectCreator
{
public:
    virtual BClass * creator() = 0;
};

// object factory
template <typename BClass>
class Factory
{
protected:
    typedef std::map<std::string, ObjectCreator<BClass>*> CreatorMap;
public:

    static void registerType(
            const std::string& name, ObjectCreator<BClass> *creator)
        {
            getCreatorMaps()->insert(std::make_pair(name,creator));
        }

    BClass * create(const std::string& classname) {
        typename CreatorMap::iterator it = getCreatorMaps()->find(classname);
        if(it==getCreatorMaps()->end())
            return 0;
        return it->second->creator();
    }
    static CreatorMap *getCreatorMaps();

private:
    static CreatorMap *creator_maps;
};


// macro for registering derived creator function in Factory
#define REGISTER_TYPE_HPP(dklass, bklass) \
class dklass##Creator : public ObjectCreator<bklass> { \
public: \
    dklass##Creator(); \
    bklass * creator() { \
        return new dklass(); \
    } \
}; \
static dklass##Creator global_##dklass##Creator;

#define REGISTER_TYPE_CPP(dklass,bklass) \
dklass##Creator::dklass##Creator() { \
    Factory<bklass>::registerType(#dklass, this); \
} \

template<typename BClass>
typename Factory<BClass>::CreatorMap* Factory<BClass>::creator_maps = new typename Factory<BClass>::CreatorMap;

template<typename BClass>
typename Factory<BClass>::CreatorMap *Factory<BClass>::getCreatorMaps()
{
    if(!creator_maps) creator_maps = new CreatorMap;
    return creator_maps;
}

//------------------------------------------------------------------------------------------
#endif // FACTORY_HPP
