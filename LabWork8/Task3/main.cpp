#include "Set.h"
#include "Map.h"

int main() {
    Set<int> se;
    se.insert(1);
    se.insert(10);
    se.insert(100);
    se.insert(100);
    se.insert(14);
    se.insert(22);
    se.traverse();
    for (SetIterator<int> it = se.begin(); ; ++it) {
        std::cout << it.node->value.key << ' ';
        if (it == se.end()) {
            break;
        }
    }
    std::cout << '\n';
    se.erase(100);
    se.erase(100);
    se.erase(10);
    se.traverse();
    for (SetIterator<int> it = se.begin(); ; ++it) {
        std::cout << it.node->value.key << ' ';
        if (it == se.end()) {
            break;
        }
    }
    std::cout << '\n';
    se.insert(16);
    se.insert(18);
    se.traverse();
    for (SetIterator<int> it = se.begin(); ; ++it) {
        std::cout << it.node->value.key << ' ';
        if (it == se.end()) {
            break;
        }
    }
    std::cout << '\n';
    for (SetIterator<int> it = se.find(16); ; ++it) {
        std::cout << it.node->value.key << ' ';
        if (it == se.end()) {
            break;
        }
    }
    std::cout << '\n';
    Map<std::string, int> mp;
    std::cout << "mp[A] is " << mp["A"] << '\n';
    mp["A"] = 10;
    mp["Bebra"] = 15;
    mp["Bebra"] = 3;
    for (MapIterator<std::string, int> it = mp.begin(); ; ++it) {
        std::cout << "[" << it.node->value.key << ", " << it.node->value.value << "] ";
        if (it == mp.end()) {
            break;
        }
    }
    std::cout << '\n';
}
