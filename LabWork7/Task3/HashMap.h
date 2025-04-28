#ifndef TASK3_HASHMAP_H
#define TASK3_HASHMAP_H


#include <vector>

template <typename Key>
class HashMap {
public:
    void insert(const Key& key);
    void remove(const Key& key);
    bool hasKey(const Key& key);

private:
    size_t bucketsCount = 1, keysCount = 0;
    std::vector<std::vector<Key>> table = std::vector<std::vector<Key>>(1);

    size_t hash(const Key& key);
    bool overloaded();
    void rebuild();
};

template<typename Key>
void HashMap<Key>::rebuild() {
    std::vector<Key> temp;
    for (auto &vec : table) {
        temp.insert(end(temp), begin(vec), end(vec));
        vec.clear();
    }
    bucketsCount *= 2;
    keysCount = 0;
    table.resize(bucketsCount);
    for (auto &u : temp) {
        insert(u);
    }
}

template<typename Key>
void HashMap<Key>::insert(const Key &key) {
    size_t bucketIndex = hash(key);
    if (std::count(begin(table[bucketIndex]), end(table[bucketIndex]), key) == 0) {
        table[bucketIndex].push_back(key);
        keysCount++;
        if (overloaded()) {
            rebuild();
        }
    }
}

template<typename Key>
void HashMap<Key>::remove(const Key &key) {
    size_t bucketIndex = hash(key);
    auto it = std::find(begin(table[bucketIndex]), end(table[bucketIndex]), key);
    if (it != end(table[bucketIndex])) {
        table[bucketIndex].erase(it);
        keysCount--;
    }
}

template<typename Key>
bool HashMap<Key>::hasKey(const Key &key) {
    size_t bucketIndex = hash(key);
    return std::count(begin(table[bucketIndex]), end(table[bucketIndex]), key) > 0;
}

template<typename Key>
size_t HashMap<Key>::hash(const Key &key) {
    return std::hash<Key>{}(key) % bucketsCount;
}

template<typename Key>
bool HashMap<Key>::overloaded() {
    return keysCount > bucketsCount;
}


#endif //TASK3_HASHMAP_H
