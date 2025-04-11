#include <iostream>
#include "String.h"

int main() {
    String a("nuhai ");
    String b("bebru");
    a += b;
    std::cout << a << ' ' << String::strlen(a) << '\n';
}
