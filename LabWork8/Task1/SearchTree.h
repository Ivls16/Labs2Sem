#include <random>
#include <iostream>

class Node {
private:
    int size_ = 1;
    unsigned int priority = std::mt19937(clock())();
    Node *l = nullptr;
    Node *r = nullptr;

public:
    int key;

    typedef std::pair<Node*, Node*> Pair;

    Node(int key = 0): key(key) {}

    static Node* merge(Node* l, Node* r);
    static Pair split(Node* p, int x);
    static int size(Node* p);
    static void update(Node* p);
    static void traverse(Node* p);
};

class Treap {
private:
    Node* root = nullptr;
public:
    void insert(int x, int index);
    int get(int index);
    void remove(int l, int r);
    void remove(int index);
    void traverse();
};
