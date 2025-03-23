#include "sorts.h"

void interpolation_sort(int *a, int n) {
    int **b = new int*[n];
    int *sz = new int[n], *pos = new int[n];
    int mn = a[0], mx = a[0];
    for (int i = 0; i < n; i++) {
        sz[i] = pos[i] = 0;
    }
    for (int i = 1; i < n; i++) {
        mn = std::min(mn, a[i]);
        mx = std::max(mx, a[i]);
    }
    for (int i = 0; i < n; i++) {
        int block = (int)((double)(a[i] - mn) / (mx - mn) * (n - 1));
        sz[block]++;
    }
    for (int i = 0; i < n; i++) {
        b[i] = new int[sz[i]];
    }
    for (int i = 0; i < n; i++) {
        int block = (int)((double)(a[i] - mn) / (mx - mn) * (n - 1));
        b[block][pos[block]++] = a[i];
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        quick_sort(b[i], 0, sz[i] - 1);
        for (int j = 0; j < sz[i]; j++) {
            a[k++] = b[i][j];
        }
        delete[] b[i];
    }
    delete[] b;
    delete[] sz;
    delete[] pos;
}
