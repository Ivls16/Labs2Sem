#include <iostream>
#include "HashMap.h"

int main() {
    HashMap<int> hmap;
    hmap.insert(123456);
    hmap.insert(555);
    hmap.insert(1488);
    hmap.insert(2009);
    std::cout << hmap.hasKey(555) << ' ' << hmap.hasKey(1488) << ' ' << hmap.hasKey(2009) << '\n';
    hmap.remove(1488);
    hmap.remove(555);
    hmap.remove(100);
    std::cout << hmap.hasKey(555) << ' ' << hmap.hasKey(1488) << ' ' << hmap.hasKey(2009) << '\n';
}
