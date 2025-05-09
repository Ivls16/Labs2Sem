#ifndef SEARCHTREE_H
#define SEARCHTREE_H

#include <random>
#include <memory>
#include <iostream>

#define NodeTemplate template<typename KeyType, typename ValueType>

NodeTemplate
class Node {
public:
    typedef std::shared_ptr<Node<KeyType, ValueType>> Pointer;
    typedef std::pair<Pointer, Pointer> Pair;

    struct NodeType {
        KeyType key;
        ValueType value;

        NodeType(KeyType key, ValueType value): key(key), value(value) {};
    };

    NodeType value;

    explicit Node<KeyType, ValueType>(NodeType value = NodeType()): value(value) {}

    static Pointer merge(Pointer l, Pointer r);
    static Pair split(Pointer p, KeyType x);
    static int size(Pointer p);
    static void update(Pointer p);
    static bool contains(Pointer p, KeyType x);
    static Pointer find(Pointer p, KeyType x);
    static void traverse(Pointer p);

    static Pointer getMin(Pointer p);
    static Pointer getMax(Pointer p);

    Pointer next = nullptr;
    Pointer prev = nullptr;

private:
    int size_ = 1;
    unsigned int priority = std::mt19937(clock())();
    Pointer l = nullptr;
    Pointer r = nullptr;
};

NodeTemplate
class NodeIterator {
public:
    Node<KeyType, ValueType>::Pointer node;

    explicit NodeIterator<KeyType, ValueType>(Node<KeyType, ValueType>::Pointer node): node(node) {}

    NodeIterator<KeyType, ValueType>& operator++() {
        node = node->next;
        return *this;
    }

    NodeIterator<KeyType, ValueType>& operator--() {
        node = node->prev;
        return *this;
    }

    bool operator == (NodeIterator<KeyType, ValueType> other) {
        return node == other.node;
    }

    bool operator != (NodeIterator<KeyType, ValueType> other) {
        return node != other.node;
    }
};

NodeTemplate
class Treap {
private:
    Node<KeyType, ValueType>::Pointer root = nullptr;
public:
    void insert(Node<KeyType, ValueType>::NodeType x);
    void remove(KeyType x);
    bool contains(KeyType x);
    virtual void traverse();

    virtual NodeIterator<KeyType, ValueType> find(KeyType key);

    virtual NodeIterator<KeyType, ValueType> begin();
    virtual NodeIterator<KeyType, ValueType> end();
};

template<typename KeyType, typename ValueType>
void Node<KeyType, ValueType>::traverse(Pointer p) {
    if (!p) {
        return;
    }
    traverse(p->l);
    std::cout << p->value.key << ' ';
    traverse(p->r);
}

template<typename KeyType, typename ValueType>
Node<KeyType, ValueType>::Pointer Node<KeyType, ValueType>::find(Pointer p, KeyType x) {
    if (!p) {
        return nullptr;
    }
    if (p->value.key == x) {
        return p;
    }
    if (p->value.key > x) {
        return find(p->l, x);
    } else {
        return find(p->r, x);
    }
}

template<typename KeyType, typename ValueType>
NodeIterator<KeyType, ValueType> Treap<KeyType, ValueType>::find(KeyType key) {
    return NodeIterator<KeyType, ValueType>(Node<KeyType, ValueType>::find(root, key));
}

template<typename KeyType, typename ValueType>
NodeIterator<KeyType, ValueType> Treap<KeyType, ValueType>::begin() {
    NodeIterator<KeyType, ValueType> it(root);
    while (it.node->prev) {
        --it;
    }
    return it;
}

template<typename KeyType, typename ValueType>
NodeIterator<KeyType, ValueType> Treap<KeyType, ValueType>::end() {
    NodeIterator<KeyType, ValueType> it(root);
    while (it.node->next) {
        ++it;
    }
    return it;
}

NodeTemplate
Node<KeyType, ValueType>::Pointer Node<KeyType, ValueType>::merge(Node<KeyType, ValueType>::Pointer l, Node<KeyType, ValueType>::Pointer r) {
    if (!l) {
        return r;
    }
    if (!r) {
        return l;
    }
    if (l->priority > r->priority) {
        l->r = merge(l->r, r);
        update(l);
        return l;
    } else {
        r->l = merge(l, r->l);
        update(r);
        return r;
    }
}

NodeTemplate
Node<KeyType, ValueType>::Pair Node<KeyType, ValueType>::split(Node<KeyType, ValueType>::Pointer p, KeyType x) {
    if (!p) {
        return {nullptr, nullptr};
    }
    if (p->value.key <= x) {
        auto q = split(p->r, x);
        p->r = q.first;
        update(p);
        return {p, q.second};
    } else {
        auto q = split(p->l, x);
        p->l = q.second;
        update(p);
        return {q.first, p};
    }
}

NodeTemplate
int Node<KeyType, ValueType>::size(Node<KeyType, ValueType>::Pointer p) {
    return p ? p->size_ : 0;
}

NodeTemplate
void Node<KeyType, ValueType>::update(Node<KeyType, ValueType>::Pointer p) {
    p->size_ = 1 + size(p->l) + size(p->r);
}

NodeTemplate
bool Node<KeyType, ValueType>::contains(Node<KeyType, ValueType>::Pointer p, KeyType x) {
    if (!p) {
        return false;
    }
    if (p->value.key == x) {
        return true;
    }
    if (p->value.key > x) {
        return contains(p->l, x);
    } else {
        return contains(p->r, x);
    }
}

template<typename KeyType, typename ValueType>
Node<KeyType, ValueType>::Pointer Node<KeyType, ValueType>::getMin(Node::Pointer p) {
    if (!p) {
        return nullptr;
    }
    if (!p->l) {
        return p;
    } else {
        return getMin(p->l);
    }
}

template<typename KeyType, typename ValueType>
Node<KeyType, ValueType>::Pointer Node<KeyType, ValueType>::getMax(Node::Pointer p) {
    if (!p) {
        return nullptr;
    }
    if (!p->r) {
        return p;
    } else {
        return getMax(p->r);
    }
}

NodeTemplate
void Treap<KeyType, ValueType>::insert(Node<KeyType, ValueType>::NodeType x) {
    if (contains(x.key)) {
        return;
    }
    auto p = Node<KeyType, ValueType>::split(root, x.key);
    auto nw = std::make_shared<Node<KeyType, ValueType>>(Node<KeyType, ValueType>(x));
    if (p.first) {
        auto l = Node<KeyType, ValueType>::getMax(p.first);
        l->next = nw;
        nw->prev = l;
    }
    if (p.second) {
        auto r = Node<KeyType, ValueType>::getMin(p.second);
        r->prev = nw;
        nw->next = r;
    }
    root = Node<KeyType, ValueType>::merge(Node<KeyType, ValueType>::merge(p.first, nw), p.second);
}

NodeTemplate
void Treap<KeyType, ValueType>::remove(KeyType x) {
    auto [l, r] = Node<KeyType, ValueType>::split(root, x);
    auto [l1, l2] = Node<KeyType, ValueType>::split(l, x - 1);
    auto mx1 = Node<KeyType, ValueType>::getMax(l1);
    auto mn2 = Node<KeyType, ValueType>::getMin(r);
    if (mx1) {
        if (mn2) {
            mx1->next = mn2;
        } else {
            mx1->next = nullptr;
        }
    }
    if (mn2) {
        if (mx1) {
            mn2->prev = mx1;
        } else {
            mn2->prev = nullptr;
        }
    }
    root = Node<KeyType, ValueType>::merge(l1, r);
}

NodeTemplate
bool Treap<KeyType, ValueType>::contains(KeyType x) {
    return Node<KeyType, ValueType>::contains(root, x);
}

NodeTemplate
void Treap<KeyType, ValueType>::traverse() {
    Node<KeyType, ValueType>::traverse(root);
    std::cout << '\n';
}


#endif // SEARCHTREE_H