#include "searchtree.h"

template<typename KeyType, typename ValueType>
using MapIterator = NodeIterator<KeyType, ValueType>;

template<typename KeyType, typename ValueType>
class Map: public Treap<KeyType, ValueType> {
public:
    using Treap<KeyType, ValueType>::find;

    void insert(KeyType key, ValueType valueType);

    ValueType& operator[](KeyType key);
};

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
void Map<KeyType, ValueType>::insert(KeyType key, ValueType valueType) {
    Treap<KeyType, ValueType>::insert(typename Node<KeyType, ValueType>::NodeType(key, valueType));
}
