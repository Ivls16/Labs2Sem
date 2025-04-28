#include <iostream>
#include "Deque.h"

void display(Deque<int> &deque) {
    for (size_t i = 0; i < deque.size(); i++) {
        std::cout << deque[i] << ' ';
    }
    std::cout << '\n';
}

int main() {
    Deque<int> deq;
    deq.push_back(1);
    display(deq);
    deq.push_back(2);
    display(deq);
    deq.push_front(0);
    display(deq);
    deq.push_front(-1);
    display(deq);
    deq.push_back(3);
    display(deq);
    deq.pop_front();
    display(deq);
    deq.pop_back();
    display(deq);
    deq.pop_back();
    display(deq);
}
