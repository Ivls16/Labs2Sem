#include "SearchTree.h"

int main() {
    Treap treap;
    treap.insert(10, 0);
    treap.insert(20, 1);
    treap.insert(30, 2);
    treap.insert(40, 3);
    treap.insert(25, 2);
    treap.traverse();
    treap.remove(3);
    treap.traverse();
    treap.remove(1, 2);
    treap.traverse();
}
