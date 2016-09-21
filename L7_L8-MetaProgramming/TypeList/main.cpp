#include <iostream>
#include "TypeList.h"

int main() {

/* Must be true */
    std::cout << "IsSame <int , int >:: value=" << IsSame<int, int>::value << std::
    endl;

/* Must be false */
    std::cout << "IsSame <int , char >:: value=" << IsSame<int, char>::value << std
    ::endl;

    typedef TYPELIST3(int, char, long) TL;
/* Must be true */
    std::cout << "Contains <TL , int >:: value =" << Contains<TL, int>::value << std::endl;
/* Must be false */
    std::cout << "Contains <TL , std :: string >:: value =" << Contains<TL, std::string>::value << std::endl;

    return 0;
}