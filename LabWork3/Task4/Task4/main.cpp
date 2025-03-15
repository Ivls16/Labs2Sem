#include <iostream>

int free(int from, int to) {
    for (int i = 1; i <= 3; i++) {
        if (from != i && to != i) {
            return i;
        }
    }
    return 0;
}

int iterations;

void hanoi(int n, int from, int to) {
    if (n == 1) {
        std::cout << from << " --> " << to << '\n';
        ++iterations;
        return;
    }
    hanoi(n - 1, from, free(from, to));
    hanoi(1, from, to);
    hanoi(n - 1, free(from, to), to);
}

int main() {
    int n;
    std::cin >> n;
    hanoi(n, 1, 3);
    std::cout << iterations << " iterations\n";
}
