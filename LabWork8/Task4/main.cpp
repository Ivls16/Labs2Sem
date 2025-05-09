#include "HashMap.h"
#include <iostream>

int main() {
    HashMap<std::string, std::string, Hasher> map;
    map["bebra"] = "freddy";
    std::cout << map.contains("bebra") << '\n';
    map["freddy"] = "chicka";
    std::cout << map["freddy"] << ' ' << map["chicka"] << ' ' << map["bebra"] << '\n';
    map.erase("bebra");
    std::cout << map["bebra"] << '\n';
}
