#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &u : a) {
        std::cin >> u;
    }
    std::vector<int> b;
    for (int i = 0; i < (int)a.size(); i += 3) {
        if (i + 2 >= (int)a.size()) {
            b.push_back((a[i] + a[(int)a.size() - 1]) / 2);
        } else {
            std::vector<int> c = {a[i], a[i + 1], a[i + 2]};
            std::sort(begin(c), end(c));
            b.push_back(c[1]);
        }
    }
    for (auto u : b) {
        std::cout << u << ' ';
    }
    std::cout << '\n';
}
