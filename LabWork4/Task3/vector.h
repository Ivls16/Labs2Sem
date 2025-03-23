#ifndef TASK3_VECTOR_H
#define TASK3_VECTOR_H


#include "vector_iterator.h"

template<typename T>
class Vector {
private:
    T* begin_;
    T* end_;
    T* capacity_;
public:
    int size() const;
    int capacity() const;
    bool empty() const;
    long long max_size() const;

    vector_iterator<T> begin();
    vector_iterator<T> end();
    const_iterator<T> cbegin();
    const_iterator<T> cend();
    reverse_iterator<T> rbegin();
    reverse_iterator<T> rend();

    void reserve(int);
    void resize(int, T = T());
    void assign(int, T = T());

    void push_back(const T&);
    void pop_back();
    void insert(vector_iterator<T>, const T&);
    void erase(vector_iterator<T>);
    void erase(vector_iterator<T>, vector_iterator<T>);
    void clear();

    ////// хзшечки
    template <typename V> struct remove_reference { using type = V; };
    template <typename V> struct remove_reference<V&> { using type = V; };
    template <typename V> struct remove_reference<V&&> { using type = V; };
    template <typename V> using remove_reference_t = typename remove_reference<V>::type;

    T&& my_forward(remove_reference_t<T>& arg) { return static_cast<T&&>(arg); }
    T&& my_forward(remove_reference_t<T>&& arg) { return static_cast<T&&>(arg); }

    template<typename... Args>
    void emplace_back(Args&&... args);

    template<typename... Args>
    void emplace(Args&&... args, vector_iterator<T>);
    ////////

    T& front() const;
    T& back() const;
    T* data() const;
    T& at(int) const;

    void swap(Vector<T>& other);
};


#endif //TASK3_VECTOR_H
