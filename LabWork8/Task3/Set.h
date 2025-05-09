#include "searchtree.h"

template<typename KeyType>
using SetIterator = NodeIterator<KeyType, char>;

template<typename KeyType>
class Set: public Treap<KeyType, char> {
public:
    void insert(KeyType value);
    void erase(KeyType value);

    void traverse();

    SetIterator<KeyType> begin();
    SetIterator<KeyType> end();
    SetIterator<KeyType> find(KeyType value);
};

template<typename KeyType>
SetIterator<KeyType> Set<KeyType>::find(KeyType value) {
    return Treap<KeyType, char>::find(value);
}

template<typename KeyType>
void Set<KeyType>::traverse() {
    Treap<KeyType, char>::traverse();
}

template<typename KeyType>
SetIterator<KeyType> Set<KeyType>::begin() {
    return Treap<KeyType, char>::begin();
}

template<typename KeyType>
SetIterator<KeyType> Set<KeyType>::end() {
    return Treap<KeyType, char>::end();
}

template<typename KeyType>
void Set<KeyType>::erase(KeyType value) {
    Treap<KeyType, char>::remove(value);
}

template<typename KeyType>
void Set<KeyType>::insert(KeyType value) {
    Treap<KeyType, char>::insert(typename Node<KeyType, char>::NodeType(value, 0));
}
