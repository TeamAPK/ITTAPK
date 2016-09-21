#include <iostream>
#include "TypeList.h"

int main() {

/* Must be true */
    std::cout << "IsSame <int , int >:: value=" << IsSame<int, int>::value << std::
    endl;

/* Must be false */
    std::cout << "IsSame <int , char >:: value=" << IsSame<int, char>::value << std
    ::endl;

    return 0;
}