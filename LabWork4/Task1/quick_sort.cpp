#include "sorts.h"

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

int divide(int *a, int l, int r) {
    int v = a[l + rnd() % (r - l)];
    int i = l, j = r;
    while (i <= j) {
        while (a[i] < v) {
            i++;
        }
        while (a[j] > v) {
            j--;
        }
        if (i >= j) {
            break;
        }
        std::swap(a[i++], a[j--]);
    }
    return j;
}

void quick_sort(int *a, int l, int r) {
    if (l >= r) {
        return;
    }
    int md = divide(a, l, r);
    quick_sort(a, l, md);
    quick_sort(a, md + 1, r);
}
