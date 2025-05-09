#include "searchtree.h"

template<typename KeyType>
using SetIterator = NodeIterator<KeyType, char>;

template<typename KeyType>
class Set: public Treap<KeyType, char> {
public:
    void insert(KeyType value);
};

template<typename KeyType>
void Set<KeyType>::insert(KeyType value) {
    Treap<KeyType, char>::insert(typename Node<KeyType, char>::NodeType(value, 0));
}
