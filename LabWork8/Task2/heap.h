#include <utility>
#include <queue>

class heapA {
private:
    int *arr;
    int n = 0;

    void shift_up(int);
    void shift_down();
    void push_to_arr(int);
    void pop_arr();

public:
    explicit heapA(int n);
    ~heapA();

    void add(int);
    int pop();
};

class heapB {
private:
    struct node {
        int key;
        node* l;
        node* r;
        node* parent;

        node(int key = 0, node* parent = nullptr, node* l = nullptr, node* r = nullptr): key(key), l(l), r(r), parent(parent) {}
    };

    node* root = nullptr;

    static void shiftUp(node* p);
    static void shiftDown(node* p);
    static node* lastNode(node* p);

public:
    void add(int value);
    void pop();

    int getMin() const;
};