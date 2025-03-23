#include "heap.h"

void heap_sort(int *a, int n) {
    heap h(n);
    for (int i = 0; i < n; i++) {
        h.add(a[i]);
    }
    for (int i = 0; i < n; i++) {
        a[i] = h.pop();
    }
}
