#include "searchtree.h"

template<typename KeyType, typename ValueType>
using MapIterator = NodeIterator<KeyType, ValueType>;

template<typename KeyType, typename ValueType>
class Map: public Treap<KeyType, ValueType> {
public:
    void insert(KeyType key, ValueType valueType);
    void erase(KeyType value);

    MapIterator<KeyType, ValueType> begin();
    MapIterator<KeyType, ValueType> end();
    MapIterator<KeyType, ValueType> find(KeyType value);

    ValueType& operator[](KeyType key);
    const ValueType& operator[](KeyType key) const;
};

template<typename KeyType, typename ValueType>
const ValueType &Map<KeyType, ValueType>::operator[](KeyType key) const {
    auto node = find(key).node;
    if (!node) {
        insert(key, ValueType());
        node = find(key).node;
    }
    return node->value.value;
}

template<typename KeyType, typename ValueType>
ValueType &Map<KeyType, ValueType>::operator[](KeyType key) {
    auto node = find(key).node;
    if (!node) {
        insert(key, ValueType());
        node = find(key).node;
    }
    return node->value.value;
}

template<typename KeyType, typename ValueType>
MapIterator<KeyType, ValueType> Map<KeyType, ValueType>::find(KeyType value) {
    return Treap<KeyType, ValueType>::find(value);
}

template<typename KeyType, typename ValueType>
MapIterator<KeyType, ValueType> Map<KeyType, ValueType>::end() {
    return Treap<KeyType, ValueType>::end();
}

template<typename KeyType, typename ValueType>
MapIterator<KeyType, ValueType> Map<KeyType, ValueType>::begin() {
    return Treap<KeyType, ValueType>::begin();
}

template<typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::erase(KeyType value) {
    Treap<KeyType, ValueType>::remove(value);
}

template<typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::insert(KeyType key, ValueType valueType) {
    Treap<KeyType, ValueType>::insert(typename Node<KeyType, ValueType>::NodeType(key, valueType));
}
