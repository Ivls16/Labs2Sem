#include <vector>
#include <string>
#include <forward_list>

#define HashMapTemplate template<typename Key, typename Value, typename Hash>

struct Hasher {
    size_t operator()(const std::string &s) const noexcept {
        size_t hash = 0;
        for (auto u : s) {
            hash = hash * 37 + (u - 'a' + 1);
        }
        return hash;
    }
};

template<typename Key, typename Value, typename Hash = std::hash<Key>>
class HashMap {
public:
    void insert(const Key& key, const Value& value);
    void erase(const Key& key);
    bool contains(const Key& key);
    void clear();

    Value &operator[](const Key& key);
    const Value &operator[](const Key& key) const;

private:
    size_t bucketsCount = 1, keysCount = 0;
    std::vector<std::forward_list<std::pair<Key, Value>>> table = std::vector<std::forward_list<std::pair<Key, Value>>>(1);

    Hash hasher;

    size_t hash(const Key&);
    bool overloaded();
    void rehash();
};

template<typename Key, typename Value, typename Hash>
const Value &HashMap<Key, Value, Hash>::operator[](const Key &key) const {
    size_t bucketIndex = hash(key);
    for (auto &u : table[bucketIndex]) {
        if (u.first == key) {
            return u.second;
        }
    }
    return *(new Value());
}

template<typename Key, typename Value, typename Hash>
Value &HashMap<Key, Value, Hash>::operator[](const Key &key) {
    if (!contains(key)) {
        insert(key, Value());
    }
    size_t bucketIndex = hash(key);
    for (auto &u : table[bucketIndex]) {
        if (u.first == key) {
            return u.second;
        }
    }
    return *(new Value());
}

HashMapTemplate
void HashMap<Key, Value, Hash>::clear() {
    bucketsCount = 1;
    keysCount = 0;
    table.clear();
    table.resize(bucketsCount);
}

HashMapTemplate
void HashMap<Key, Value, Hash>::rehash() {
    std::vector<std::pair<Key, Value>> temp;
    temp.reserve(keysCount);
    for (auto &chain : table) {
        for (auto &p : chain) {
            temp.push_back(p);
        }
        chain.clear();
    }
    bucketsCount *= 2;
    keysCount = 0;
    table.clear();
    table.resize(bucketsCount);
    for (auto &p : temp) {
        insert(p.first, p.second);
    }
}

HashMapTemplate
void HashMap<Key, Value, Hash>::insert(const Key &key, const Value &value) {
    size_t bucketIndex = hash(key);
    auto &chain = table[bucketIndex];
    auto it = std::find_if(chain.begin(), chain.end(),[&](auto &p) { return p.first == key; });
    if (it == chain.end()) {
        chain.push_front({key, value});
        ++keysCount;
        if (overloaded()) {
            rehash();
        }
    }
}

HashMapTemplate
void HashMap<Key, Value, Hash>::erase(const Key &key) {
    size_t bucketIndex = hash(key);
    auto &chain = table[bucketIndex];
    auto prev = chain.before_begin();
    for (auto cur = chain.begin(); cur != chain.end(); ++cur) {
        if (cur->first == key) {
            chain.erase_after(prev);
            --keysCount;
            return;
        }
        prev = cur;
    }
}

HashMapTemplate
bool HashMap<Key, Value, Hash>::contains(const Key &key) {
    size_t bucketIndex = hash(key);
    auto &chain = table[bucketIndex];
    return std::any_of(chain.begin(), chain.end(),[&](auto &p) { return p.first == key; });
}

HashMapTemplate
size_t HashMap<Key, Value, Hash>::hash(const Key &key) {
    return hasher(key) % bucketsCount;
}

HashMapTemplate
bool HashMap<Key, Value, Hash>::overloaded() {
    return keysCount * 4 > bucketsCount * 3;
}
