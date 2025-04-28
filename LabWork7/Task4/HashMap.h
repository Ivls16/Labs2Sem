#ifndef TASK4_HASHMAP_H
#define TASK4_HASHMAP_H


#include <vector>

template <typename Key>
class HashMap {
public:
    void insert(const Key& key);
    void remove(const Key& key);
    bool hasKey(const Key& key);

private:
    size_t bucketsCount = 1, keysCount = 0;
    std::vector<short> state = std::vector<short>(1);
    std::vector<Key> table = std::vector<Key>(1);

    size_t hash(const Key& key);
    bool overloaded();
    void rebuild();
};

template<typename Key>
void HashMap<Key>::rebuild() {
    std::vector<Key> temp;
    for (size_t i = 0; i < bucketsCount; i++) {
        if (state[i] == 1) {
            temp.push_back(table[i]);
        }
    }
    bucketsCount *= 2;
    keysCount = 0;
    table.resize(bucketsCount);
    state.assign(bucketsCount, 0);
    for (auto &u : temp) {
        insert(u);
    }
}

template<typename Key>
void HashMap<Key>::insert(const Key &key) {
    if (hasKey(key)) {
        return;
    }
    size_t bucketIndex = hash(key);
    int it = 1;
    while (state[bucketIndex] == 1) {
        bucketIndex = (bucketIndex + it + it * it) % bucketsCount;
        it++;
    }
    table[bucketIndex] = key;
    state[bucketIndex] = 1;
    keysCount++;
    if (overloaded()) {
        rebuild();
    }
}

template<typename Key>
void HashMap<Key>::remove(const Key &key) {
    if (!hasKey(key)) {
        return;
    }
    size_t bucketIndex = hash(key);
    int it = 1;
    while (table[bucketIndex] != key) {
        bucketIndex = (bucketIndex + it + it * it) % bucketsCount;
        it++;
    }
    keysCount--;
    state[bucketIndex] = 2;
}

template<typename Key>
bool HashMap<Key>::hasKey(const Key &key) {
    size_t bucketIndex = hash(key);
    int it = 1;
    while (state[bucketIndex] != 0 && (table[bucketIndex] != key || state[bucketIndex] == 2)) {
        bucketIndex = (bucketIndex + it + it * it) % bucketsCount;
        it++;
    }
    return state[bucketIndex] != 0;
}

template<typename Key>
size_t HashMap<Key>::hash(const Key &key) {
    return std::hash<Key>{}(key) % bucketsCount;
}

template<typename Key>
bool HashMap<Key>::overloaded() {
    return 4 * keysCount > 3 * bucketsCount;
}


#endif //TASK4_HASHMAP_H
