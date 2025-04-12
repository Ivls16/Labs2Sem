#include <iostream>
#include "Bitset.h"

int main() {
    Bitset<5> b(7); // 00111
    b.flip(); // 11000
    std::cout << b.to_string();
}
