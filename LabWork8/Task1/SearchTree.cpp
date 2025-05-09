#include "SearchTree.h"

Node* Node::merge(Node *l, Node *r) {
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

Node::Pair Node::split(Node *p, int x) {
    if (!p) {
        return {nullptr, nullptr};
    }
    if (size(p->l) + 1 <= x) {
        Pair q = split(p->r, x - size(p->l) - 1);
        p->r = q.first;
        update(p);
        return {p, q.second};
    } else {
        Pair q = split(p->l, x);
        p->l = q.second;
        update(p);
        return {q.first, p};
    }
}

int Node::size(Node *p) {
    return p ? p->size_ : 0;
}

void Node::update(Node *p) {
    p->size_ = 1 + size(p->l) + size(p->r);
}

void Node::traverse(Node *p) {
    if (!p) {
        return;
    }
    traverse(p->l);
    std::cout << p->key << ' ';
    traverse(p->r);
}

void Treap::traverse() {
    Node::traverse(root);
    std::cout << '\n';
}

void Treap::insert(int x, int index) {
    Node::Pair p = Node::split(root, index);
    root = Node::merge(Node::merge(p.first, new Node(x)), p.second);
}

void Treap::remove(int index) {
    remove(index, index);
}

void Treap::remove(int l, int r) {
    Node::Pair p = Node::split(root, l);
    Node::Pair q = Node::split(p.second, r - l + 1);
    root = Node::merge(p.first, q.second);
    delete[] q.first;
}

int Treap::get(int index) {
    Node::Pair p = Node::split(root, index);
    Node::Pair q = Node::split(p.second, 1);
    return q.first->key;
}
