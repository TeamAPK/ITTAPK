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
#define TYPELIST2(A,B) TypeList<A, TypeList<B, NullType>>
#define TYPELIST3(A,B,C) TypeList<A, TypeList<B, TypeList<C, NullType>>>
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

template<typename TL, typename F>
struct Contains
{
    static const bool value = IsSame<typename TL::First, F>::value || Contains<typename TL::Rest, F>::value;
};

template<typename F>
struct Contains<NullType, F>
{
    static const bool value = false;
};

#endif //TYPELIST_TYPELIST_H
