#include "vector.h"

template<typename T>
int Vector<T>::size() const {
    return end_ - begin_;
}

template<typename T>
int Vector<T>::capacity() const {
    return capacity_ - begin_;
}

template<typename T>
vector_iterator<T> Vector<T>::begin() {
    return vector_iterator<T>(begin_);
}

template<typename T>
vector_iterator<T> Vector<T>::end() {
    return vector_iterator<T>(end_);
}

template<typename T>
const_iterator<T> Vector<T>::cbegin() {
    return const_iterator<T>(begin_);
}

template<typename T>
const_iterator<T> Vector<T>::cend() {
    return const_iterator<T>(end_);
}

template<typename T>
reverse_iterator<T> Vector<T>::rbegin() {
    return reverse_iterator<T>(--end());
}

template<typename T>
reverse_iterator<T> Vector<T>::rend() {
    return reverse_iterator<T>(--begin());
}

template<typename T>
T &Vector<T>::front() const {
    return *begin();
}

template<typename T>
T &Vector<T>::back() const {
    return *(--end());
}

template<typename T>
bool Vector<T>::empty() const {
    return begin_ == end_;
}

template<typename T>
T *Vector<T>::data() const {
    return begin_;
}

template<typename T>
void Vector<T>::swap(Vector<T> &other) {
    T* temp;
    temp = begin_; begin_ = other.begin_; other.begin_ = temp;
    temp = end_; end_ = other.end_; other.end_ = temp;
    temp = capacity_; capacity_ = other.capacity_; other.capacity_ = temp;
}

template<typename T>
T &Vector<T>::at(int index) const {
    if (index >= size()) {
        return -1;
    }
    return data()[index];
}

template<typename T>
void Vector<T>::reserve(int new_capacity) {
    if (new_capacity <= capacity()) {
        return;
    }
    T* new_data = new T[new_capacity];
    for (int i = 0; i < size(); i++) {
        new_data[i] = data()[i];
    }
    delete[] data();
    end_ = new_data + size();
    capacity_ = new_data + new_capacity;
    begin_ = new_data;
}

template<typename T>
void Vector<T>::push_back(const T &value) {
    if (size() == capacity()) {
        reserve(capacity() == 0 ? 1 : capacity() * 2);
    }
    data()[size()] = value;
    end_++;
}

template<typename T>
void Vector<T>::pop_back() {
    if (empty()) {
        return;
    }
    end_--;
}

template<typename T>
void Vector<T>::resize(int new_size, T  value) {
    if (size() >= new_size) {
        end_ -= size() - new_size;
        return;
    }
    while (size() < new_size) {
        push_back(value);
    }
}

template<typename T>
void Vector<T>::assign(int new_size, T  value) {
    while (new_size > capacity()) {
        reserve(capacity() == 0 ? 1 : capacity() * 2);
    }
    for (int i = 0; i < new_size; i++) {
        data()[i] = value;
    }
    end_ = begin_ + new_size;
}

template<typename T> template<typename... Args>
void Vector<T>::emplace_back(Args &&... args) {
    if (size() == capacity()) {
        reserve(capacity() == 0 ? 1 : capacity() * 2);
    }
    new (&data()[size()]) T(my_forward<Args>(args)...);
    end_++;
}

template<typename T> template<typename... Args>
void Vector<T>::emplace(Args &&... args, vector_iterator<T> pos) {
    if (size() == capacity()) {
        reserve(capacity() == 0 ? 1 : capacity() * 2);
    }
    for (vector_iterator<T> it = --end(); it >= begin(); --it) {
        *(it + 1) = *it;
    }
    end_++;
    new (&data()[pos - begin()]) T(my_forward<Args>(args)...);
}

template<typename T>
void Vector<T>::insert(vector_iterator<T> pos, const T &value) {
    if (size() == capacity()) {
        reserve(capacity() == 0 ? 1 : capacity() * 2);
    }
    for (vector_iterator<T> it = --end(); it >= pos(); --it) {
        *(it + 1) = *it;
    }
    end_++;
    *begin() = value;
}

template<typename T>
void Vector<T>::erase(vector_iterator<T> begin, vector_iterator<T> end) {
    int count = end - begin;
    for (vector_iterator<T> it = end; it < end + count; ++it) {
        *(it - count) = *it;
    }
    end_ -= count;
}

template<typename T>
void Vector<T>::erase(vector_iterator<T> index) {
    erase(index, index + 1);
}

template<typename T>
void Vector<T>::clear() {
    end_ = begin_;
}

template<typename T>
long long Vector<T>::max_size() const {
    return static_cast<long long>(-1) / sizeof(T);
}