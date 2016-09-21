#ifndef TYPELIST_TYPELIST_H
#define TYPELIST_TYPELIST_H

struct NullType{};

template<typename L, typename R>
struct TypeList
{
    typedef L First;
    typedef R Rest;
};

#define TYPELIST1(A) TypeList<A, NullType>
#define TYPELIST4(A,B,C,D) \
TypeList<A, TypeList<B, TypeList<C, TypeList<D, NullType>>>>


template<typename T, typename U>
struct IsSame
{
    static const bool value = false;
};

template<typename T>
struct IsSame<T, T>
{
    static const bool value = true;
};

#endif //TYPELIST_TYPELIST_H
