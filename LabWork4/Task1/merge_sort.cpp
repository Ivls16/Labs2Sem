#include "sorts.h"

void merge_sort(int *a, int l, int r) {
    if (r - l == 1) {
        return;
    }
    int md = (l + r) / 2;
    merge_sort(a, l, md);
    merge_sort(a, md, r);
    int *b = new int[r - l];
    {
        int i = l, j = md, k = 0;
        while (i < md || j < r) {
            if (i == md) {
                b[k++] = a[j++];
                continue;
            }
            if (j == r) {
                b[k++] = a[i++];
                continue;
            }
            if (a[i] < a[j]) {
                b[k++] = a[i++];
            }
            else {
                b[k++] = a[j++];
            }
        }
    }
    for (int i = l; i < r; i++) {
        a[i] = b[i - l];
    }
    delete[] b;
}
