#include <iostream>
#include "sorts.h"
#include "binsearch.h"
#include "binpow.h"

void run();
void test();

int main() {
    test();
}

void run() {
    int n;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    //merge_sort(a, 0, n);
    //quick_sort(a, 0, n - 1);
    //heap_sort(a, n);
    //interpolation_sort(a, n);
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
    int v;
    std::cin >> v;
    std::cout << binsearch(a, n, v) << '\n';
}

const int n = 1000000;
int a[n], b[n], c[n], d[n], e[n];

void test() {
    std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 0; i < n; i++) {
        a[i] = b[i] = c[i] = d[i] = abs((int)rnd());
    }
    {
        auto start = std::chrono::high_resolution_clock::now();
        merge_sort(a, 0, n);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "merge sort ended in " << duration.count() << '\n';
    }
    {
        auto start = std::chrono::high_resolution_clock::now();
        quick_sort(b, 0, n - 1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "quick sort ended in " << duration.count() << '\n';
    }
    {
        auto start = std::chrono::high_resolution_clock::now();
        heap_sort(c, n);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "heap sort ended in " << duration.count() << '\n';
    }
    {
        auto start = std::chrono::high_resolution_clock::now();
        interpolation_sort(d, n);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "interpolation sort ended in " << duration.count() << '\n';
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i] || a[i] != c[i] || a[i] != d[i]) {
            std::cout << i << " is incorrect\n";
        }
    }
}