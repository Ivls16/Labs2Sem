#ifndef TASK3_VECTOR_ITERATOR_H
#define TASK3_VECTOR_ITERATOR_H


template<typename T>
class vector_iterator {
private:
    T* ptr;
public:
    explicit vector_iterator(T* p): ptr(p) {};

    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    vector_iterator& operator++() { ++ptr; return *this; }
    vector_iterator operator++(int) { vector_iterator tmp = *this; ++ptr; return tmp; }
    vector_iterator& operator--() { --ptr; return *this; }
    bool operator==(const vector_iterator& other) const { return ptr == other.ptr; }
    bool operator!=(const vector_iterator& other) const { return ptr != other.ptr; }
};

template<typename T>
class reverse_iterator {
private:
    vector_iterator<T> iterator;
public:
    explicit reverse_iterator(T* p): iterator(p) {};

    T& operator*() const { return *iterator; }
    T* operator->() const { return iterator; }
    reverse_iterator& operator++() { iterator--; return *this; }
    reverse_iterator operator++(int) { reverse_iterator tmp = *this; iterator--; return tmp; }
    reverse_iterator& operator--() { iterator++; return *this; }
    bool operator==(const reverse_iterator& other) const { return iterator == other.iterator; }
    bool operator!=(const reverse_iterator& other) const { return iterator != other.iterator; }
};

template<typename T>
class const_iterator {
private:
    const T* ptr;
public:
    explicit const_iterator(const T* p): ptr(p) {};

    const T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    const_iterator& operator++() { ++ptr; return *this; }
    const_iterator operator++(int) { const_iterator tmp = *this; ++ptr; return tmp; }
    const_iterator& operator--() { --ptr; return *this; }
    bool operator==(const const_iterator& other) const { return ptr == other.ptr; }
    bool operator!=(const const_iterator& other) const { return ptr != other.ptr; }
};


#endif //TASK3_VECTOR_ITERATOR_H
