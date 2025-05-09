#include "heap.h"

heapA::heapA(int n) {
    arr = new int[n];
}

heapA::~heapA() {
    delete[] arr;
}

void heapA::push_to_arr(int value) {
    arr[n++] = value;
}

void heapA::pop_arr() {
    n--;
}

void heapA::add(int value) {
    push_to_arr(value);
    shift_up(n - 1);
}

int heapA::pop() {
    if (!n) {
        return -1;
    }
    int res = arr[0];
    std::swap(arr[0], arr[n - 1]);
    pop_arr();
    shift_down();
    return res;
}

void heapA::shift_up(int v) {
    while (v > 0 && arr[v] < arr[(v - 1) / 2]) {
        std::swap(arr[v], arr[(v - 1) / 2]);
        v = (v - 1) / 2;
    }
}

void heapA::shift_down() {
    int v = 0;
    while (2 * v + 1 < n) {
        int l = 2 * v + 1, r = 2 * v + 2;
        int u = (r >= n || arr[l] <= arr[r] ? l : r);
        if (arr[v] < arr[u]) {
            break;
        }
        std::swap(arr[v], arr[u]);
        v = u;
    }
}

void heapB::add(int value) {
    node* newNode = new node(value);
    if (!root) {
        root = newNode;
        return;
    }
    std::queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* v = q.front();
        q.pop();
        if (!v->l) {
            v->l = newNode;
            newNode->parent = v;
            shiftUp(newNode);
            return;
        } else {
            q.push(v->l);
        }
        if (!v->r) {
            v->r = newNode;
            newNode->parent = v;
            shiftUp(newNode);
            return;
        } else {
            q.push(v->r);
        }
    }
}

void heapB::pop() {
    if (!root) {
        return;
    }
    node* last = lastNode(root);
    if (last == root) {
        delete root;
        root = nullptr;
        return;
    }
    root->key = last->key;
    node* parent = last->parent;
    if (parent->l == last) {
        parent->l = nullptr;
    } else {
        parent->r = nullptr;
    }
    delete last;
    shiftDown(root);
}

void heapB::shiftUp(heapB::node *p) {
    while (p->parent && p->key < p->parent->key) {
        std::swap(p->key, p->parent->key);
        p = p->parent;
    }
}

void heapB::shiftDown(heapB::node *p) {
    while (p) {
        node* smallest = p;
        if (p->l && p->l->key < smallest->key) {
            smallest = p->l;
        }
        if (p->r && p->r->key < smallest->key) {
            smallest = p->r;
        }
        if (smallest == p) {
            break;
        }
        std::swap(p->key, smallest->key);
        p = smallest;
    }
}

heapB::node *heapB::lastNode(heapB::node *p) {
    if (!p->l && !p->r) {
        return p;
    }
    if (p->r) {
        return lastNode(p->r);
    } else {
        return lastNode(p->l);
    }
}

int heapB::getMin() const {
    if (root) {
        return root->key;
    } else {
        return -1;
    }
}
