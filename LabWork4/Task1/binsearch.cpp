#include "binsearch.h"

int binsearch(const int *a, int n, int v) {
    int l = 0, r = n - 1;
    while (l < r) {
        int md = (l + r) / 2;
        if (a[md] < v) {
            l = md + 1;
        }
        else {
            r = md;
        }
    }
    return a[l] == v ? l : -1;
}
