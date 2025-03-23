#include "heap.h"

heap::heap(int n) {
    arr = new int[n];
}

heap::~heap() {
    delete[] arr;
}

void heap::push_to_arr(int value) {
    arr[n++] = value;
}

void heap::pop_arr() {
    n--;
}

void heap::add(int value) {
    push_to_arr(value);
    shift_up(n - 1);
}

int heap::pop() {
    if (!n) {
        return -1;
    }
    int res = arr[0];
    std::swap(arr[0], arr[n - 1]);
    pop_arr();
    shift_down();
    return res;
}

void heap::shift_up(int v) {
    while (v > 0 && arr[v] < arr[(v - 1) / 2]) {
        std::swap(arr[v], arr[(v - 1) / 2]);
        v = (v - 1) / 2;
    }
}

void heap::shift_down() {
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
