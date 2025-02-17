#include <iostream>
#include "thirdparty/mylib/mylib.h"
#include "thirdparty/mylib/mymath.h"

void hello_main()
{
    std::cout << "Hello from main!" << std::endl;
}

int main()
{
    hello_lib();
    hello_main();
    std::cout << "add(1, 2) = " << add(1, 2) << std::endl;
    std::cout << "mutiply(3, 4) = " << mutiply(3, 4) << std::endl;
    return 0;
}