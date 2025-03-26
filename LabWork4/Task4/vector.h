template<typename U>
class vector_iterator {
private:
    U* ptr;
public:
    explicit vector_iterator(U* p): ptr(p) {};

    U& operator*() const { return *ptr; }
    U* operator->() const { return ptr; }
    vector_iterator& operator++() { ++ptr; return *this; }
    vector_iterator operator+(int value) { vector_iterator tmp = *this; tmp.ptr += value; return tmp; }
    vector_iterator& operator--() { --ptr; return *this; }
    bool operator==(const vector_iterator& other) const { return ptr == other.ptr; }
    bool operator!=(const vector_iterator& other) const { return ptr != other.ptr; }
    int operator -(vector_iterator a) { return ptr - a.ptr; }
};

template<typename U>
class reverse_iterator {
private:
    vector_iterator<U> iterator;
public:
    explicit reverse_iterator(vector_iterator<U> p): iterator(p) {};

    U& operator*() const { return *iterator; }
    U* operator->() const { return iterator; }
    reverse_iterator& operator++() { --iterator; return *this; }
    reverse_iterator operator+(int value) { reverse_iterator tmp = *this; tmp.iterator -= value; return tmp; }
    reverse_iterator& operator--() { ++iterator; return *this; }
    bool operator==(const reverse_iterator& other) const { return iterator == other.iterator; }
    bool operator!=(const reverse_iterator& other) const { return iterator != other.iterator; }
};

template<typename U>
class const_iterator {
private:
    const U* ptr;
public:
    explicit const_iterator(const U* p): ptr(p) {};

    const U& operator*() const { return *ptr; }
    U* operator->() const { return ptr; }
    const_iterator& operator++() { ++ptr; return *this; }
    const_iterator operator+(int value) { const_iterator tmp = *this; tmp.ptr += value; return tmp; }
    const_iterator& operator--() { --ptr; return *this; }
    bool operator==(const const_iterator& other) const { return ptr == other.ptr; }
    bool operator!=(const const_iterator& other) const { return ptr != other.ptr; }
};

template<typename T>
class Vector {
private:
    T* begin_;
    T* end_;
    T* capacity_;
public:
    Vector(): begin_(nullptr), end_(nullptr), capacity_(nullptr) {}

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

    template<typename U>
    constexpr U&& my_forward(std::remove_reference_t<U>& t) noexcept {
        return static_cast<U&&>(t);
    }

    template<typename... Args>
    void emplace_back(Args&&... args);

    ////////

    T& front();
    T& back();
    T* data() const;
    T& at(int);

    T& operator[](int);

    void swap(Vector<T>& other);
};

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
T &Vector<T>::front() {
    return *begin();
}

template<typename T>
T &Vector<T>::back() {
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
T &Vector<T>::at(int index) {
    if (index >= size()) {
        return back();
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

template<typename T>
void Vector<T>::insert(vector_iterator<T> pos, const T &value) {
    if (size() == capacity()) {
        reserve(capacity() == 0 ? 1 : capacity() * 2);
    }
    for (vector_iterator<T> it = --end(); it != pos + (-1); --it) {
        *(it + 1) = *it;
    }
    end_++;
    *pos = value;
}

template<typename T>
void Vector<T>::erase(vector_iterator<T> begin, vector_iterator<T> end) {
    int count = end - begin;
    for (vector_iterator<T> it = end; it != end + count; ++it) {
        *(it + (-count)) = *it;
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

template<typename T>
T &Vector<T>::operator[](int index) {
    return at(index);
}