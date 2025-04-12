#include <cstddef>
#include <string>
#include <stdexcept>
#include <iostream>

const size_t WORD_SIZE = 64;

class reference {
private:
    unsigned long long& word;
    size_t bit_index;
public:
    reference(unsigned long long& word, size_t bit_index): word(word), bit_index(bit_index) {}

    reference& operator=(bool value) {
        if (value) {
            word |= (1ULL << bit_index);
        }
        else {
            word &= ~(1ULL << bit_index);
        }
        return *this;
    }

    reference& operator=(const reference& other) {
        return *this = static_cast<bool>(other);
    }

    explicit operator bool() const {
        return (word >> bit_index) & 1ULL;
    }

    reference& flip() {
        word ^= (1ULL << bit_index);
        return *this;
    }
};

template <size_t N>
class Bitset {
public:
    Bitset();
    explicit Bitset(unsigned long long val);

    bool operator == (const Bitset<N>& other) const;
    bool operator != (const Bitset<N>& other) const;

    Bitset<N>& operator &= (const Bitset<N>& other);
    Bitset<N>& operator ^= (const Bitset<N>& other);
    Bitset<N>& operator |= (const Bitset<N>& other);
    Bitset<N> operator~() const;

    bool operator[](size_t pos) const;
    reference operator[](size_t pos);

    bool all() const;
    bool any() const;
    bool none() const;

    size_t size() const;
    int count() const;

    Bitset<N>& flip();
    Bitset<N>& flip(size_t pos);
    Bitset<N>& reset();
    Bitset<N>& reset(size_t pos);
    Bitset<N>& set();
    Bitset<N>& set(size_t pos);

    bool test(size_t pos) const;

    std::string to_string(char zero = '0', char one = '1');
private:
    static const size_t asize = (N + WORD_SIZE - 1) / WORD_SIZE;
    unsigned long long arr[asize] = {};
};

template<size_t N>
Bitset<N>::Bitset() {};

template<size_t N>
bool Bitset<N>::all() const {
    size_t rem = N;
    for (int i = 0; i < asize; i++) {
        unsigned long long cur = arr[i];
        if (rem <= WORD_SIZE) {
            cur <<= (WORD_SIZE - rem);
            cur |= (1ULL << (WORD_SIZE - rem + 1)) - 1;
        }
        if (__builtin_popcountll(cur) != WORD_SIZE) {
            return false;
        }
    }
    return true;
}

template<size_t N>
bool Bitset<N>::any() const {
    size_t rem = N;
    for (int i = 0; i < asize; i++) {
        unsigned long long cur = arr[i];
        if (rem <= WORD_SIZE) {
            cur <<= (WORD_SIZE - rem);
        }
        if (cur != 0) {
            return true;
        }
    }
    return false;
}

template<size_t N>
bool Bitset<N>::none() const {
    return !any();
}

template<size_t N>
size_t Bitset<N>::size() const {
    return N;
}

template<size_t N>
int Bitset<N>::count() const {
    size_t rem = N;
    int ones = 0;
    for (int i = 0; i < asize; i++) {
        unsigned long long cur = arr[i];
        if (rem <= WORD_SIZE) {
            cur <<= (WORD_SIZE - rem);
        }
        ones += __builtin_popcountll(cur);
    }
    return ones;
}

template<size_t N>
reference Bitset<N>::operator[](size_t pos) {
    if (pos >= N) {
        throw std::out_of_range("");
    }
    return reference(arr[pos / WORD_SIZE], pos % WORD_SIZE);
}

template<size_t N>
bool Bitset<N>::operator[](size_t pos) const {
    if (pos >= N) {
        throw std::out_of_range("");
    }
    return (bool)reference(arr[pos / WORD_SIZE], pos % WORD_SIZE);
}

template<size_t N>
bool Bitset<N>::operator==(const Bitset<N> &other) const {
    size_t rem = N;
    for (int i = 0; ; i++) {
        if (rem > WORD_SIZE) {
            if (arr[i] != other.arr[i]) {
                return false;
            }
            rem -= WORD_SIZE;
        }
        else {
            if ((arr[i] << (WORD_SIZE - rem)) != (other.arr[i] << (WORD_SIZE - rem))) {
                return false;
            }
            break;
        }
    }
    return true;
}

template<size_t N>
bool Bitset<N>::operator!=(const Bitset<N> &other) const {
    return *this != other;
}

template<size_t N>
Bitset<N> &Bitset<N>::operator&=(const Bitset<N> &other) {
    for (int i = 0; i < asize; i++) {
        arr[i] &= other.arr[i];
    }
}

template<size_t N>
Bitset<N> &Bitset<N>::operator^=(const Bitset<N> &other) {
    for (int i = 0; i < asize; i++) {
        arr[i] ^= other.arr[i];
    }
}

template<size_t N>
Bitset<N> &Bitset<N>::operator|=(const Bitset<N> &other) {
    for (int i = 0; i < asize; i++) {
        arr[i] |= other.arr[i];
    }
}

template<size_t N>
Bitset<N> Bitset<N>::operator~() const {
    Bitset<N> res;
    for (int i = 0; i < asize; i++) {
        res.arr[i] = ~arr[i];
    }
    return res;
}

template<size_t N>
bool Bitset<N>::test(size_t pos) const {
    return (bool)reference(arr[pos / WORD_SIZE], pos % WORD_SIZE);
}

template<size_t N>
Bitset<N>& Bitset<N>::flip() {
    for (int i = 0; i < asize; i++) {
        arr[i] = ~arr[i];
    }
    return *this;
}

template<size_t N>
Bitset<N>& Bitset<N>::flip(size_t pos) {
    if (pos >= N) {
        throw std::out_of_range("");
    }
    this[pos].flip();
}

template<size_t N>
std::string Bitset<N>::to_string(char zero, char one) {
    std::string str;
    int rem = N;
    for (int i = 0; i < asize; i++) {
        int rei = std::min(rem, (int)WORD_SIZE);
        unsigned long long cur = arr[i];
        rem -= rei;
        while (rei--) {
            if (cur & 1) {
                str += std::string(1, one);
            }
            else {
                str += std::string(1, zero);
            }
            cur >>= 1ull;
        }
    }
    reverse(begin(str), end(str));
    return str;
}

template<size_t N>
Bitset<N> &Bitset<N>::reset() {
    for (int i = 0; i < asize; i++) {
        arr[i] = 0;
    }
    return this;
}

template<size_t N>
Bitset<N> &Bitset<N>::reset(size_t pos) {
    if (pos >= N) {
        throw std::out_of_range("");
    }
    this[pos] = false;
}

template<size_t N>
Bitset<N> &Bitset<N>::set() {
    for (int i = 0; i < asize; i++) {
        arr[i] = (1ull << (WORD_SIZE - 1)) + ((1ull << (WORD_SIZE - 1)) - 1);
    }
    return this;
}

template<size_t N>
Bitset<N> &Bitset<N>::set(size_t pos) {
    if (pos >= N) {
        throw std::out_of_range("");
    }
    this[pos] = true;
}

template<size_t N>
Bitset<N>::Bitset(unsigned long long val) {
    arr[0] = val;
}