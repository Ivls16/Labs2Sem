#include <utility>

class heap {
private:
    int *arr;
    int n = 0;

    void shift_up(int);
    void shift_down();
    void push_to_arr(int);
    void pop_arr();

public:
    explicit heap(int n);
    ~heap();

    void add(int);
    int pop();
};