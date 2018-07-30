#ifndef FACTORY_HPP
#define FACTORY_HPP
//---------------------------------------------------------------------------------------
#include <map>
// object creator
//template <typename BClass>
//class ObjectCreator
//{
//public:
//    virtual BClass * creator() = 0;
//};

template<typename DerivedType, typename BaseType, typename KeyType>
class ObjectCreator {
public:
    ObjectCreator(KeyType key);

    static BaseType * creator() {
        return new DerivedType();
    }
};



// object factory
template <typename BaseType, typename KeyType>
class Factory
{
protected:
    typedef std::map<KeyType, BaseType *(*)()> CreatorMap;
public:

    static void registerType(
            const KeyType& name, BaseType *(*creator)() )
        {
            getCreatorMaps()->insert(std::make_pair(name,creator));
        }

    BaseType * create(const KeyType& classname) {
        typename CreatorMap::iterator it = getCreatorMaps()->find(classname);
        if(it==getCreatorMaps()->end())
            return 0;
        return it->second();
    }

private:
    static CreatorMap *getCreatorMaps();
    static CreatorMap *creator_maps;
};

template<typename DerivedType, typename BaseType, typename KeyType>
ObjectCreator<DerivedType,BaseType,KeyType>::ObjectCreator(KeyType key)
{
        Factory<BaseType, KeyType>::registerType(key, &(ObjectCreator<DerivedType,BaseType,KeyType>::creator));
}

template<typename BaseType, typename KeyType>
typename Factory<BaseType, KeyType>::CreatorMap* Factory<BaseType, KeyType>::creator_maps =
        new typename Factory<BaseType, KeyType>::CreatorMap;

template<typename BaseType, typename KeyType>
typename Factory<BaseType, KeyType>::CreatorMap *Factory<BaseType, KeyType>::getCreatorMaps()
{
    if(!creator_maps) creator_maps = new CreatorMap;
    return creator_maps;
}

// macro for registering derived creator function in Factory
//#define REGISTER_TYPE_HPP(dklass, ktype, key, bklass) \
//class dklass##Creator : public ObjectCreator<bklass> { \
//public: \
//    dklass##Creator(ktype key); \
//    bklass * creator() { \
//        return new dklass(); \
//    } \
//}; \
//static dklass##Creator global_##dklass##Creator;

//#define REGISTER_TYPE_CPP(dklass, ktype, key, bklass) \
//dklass##Creator::dklass##Creator() { \
//    Factory<bklass, ktype>::registerType(key, this); \
//} \


#define REGISTER_FACTORY_HPP(dtype, btype, ktype,key) \
static ObjectCreator<dtype, btype, ktype> global_##dtype##_Creator(key);

//------------------------------------------------------------------------------------------
#endif // FACTORY_HPP
