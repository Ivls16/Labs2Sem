#include <iostream>
#include "vector.h"
#include <string>

template<typename T>
void display(Vector<T>& vec) {
    for (vector_iterator<T> it = vec.begin(); it != vec.end(); ++it) {
        std::cout << (*it) << ' ';
    }
    std::cout << "[siz:" << vec.size() << " cap:" << vec.capacity() << "]";
    std::cout << '\n';
}

template<typename T>
void rdisplay(Vector<T>& vec) {
    for (reverse_iterator<T> it = vec.rbegin(); it != vec.rend(); ++it) {
        std::cout << (*it) << ' ';
    }
    std::cout << '\n';
}

int main() {
    Vector<int> vec;
    std::cout << vec.empty() << '\n';
    vec.pop_back();
    vec.assign(5, 3);
    display(vec);
    vec.push_back(10);
    vec.push_back(15);
    std::cout << vec.front() << ' ' << vec.back() << '\n';
    display(vec);
    vec.pop_back();
    vec.push_back(11);
    display(vec);
    vec.resize(10, 25);
    vec.insert(vec.begin() + 3, 44);
    display(vec);
    vec.erase(vec.begin() + 5, vec.begin() + 8);
    rdisplay(vec);
    std::cout << vec.back() << '\n';
    std::cout << vec.at(5) << ' ' << vec.at(100) << '\n';
    std::cout << vec.empty() << '\n';
    vec.clear();
    std::cout << vec.empty() << '\n';
    display(vec);
    std::cout << vec.max_size() << '\n';
    vec.push_back(1);
    vec.push_back(2);
    Vector<int> b;
    b.push_back(2);
    b.push_back(1);
    display(vec);
    display(b);
    vec.swap(b);
    display(vec);
    display(b);
    Vector<std::string> vs;
    vs.push_back("abc");
    vs.push_back("def");
    display(vs);
    vs.push_back(std::string(5, 'd'));
    vs.emplace_back(5, 'e');
    display(vs);
}