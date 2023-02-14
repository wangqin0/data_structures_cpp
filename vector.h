#ifndef DATA_STRUCTURES_CPP_VECTOR_H
#define DATA_STRUCTURES_CPP_VECTOR_H

#include <cstddef>

#include <cstring>
#include <cassert>
#include <stdexcept>

/*
 * Performance requirements:
 *   vector()       O(1)
 *   vector(n, x)   O(n)
 *   size()         O(1)
 *   v[i]           O(1)
 *   push_back(x)   O(1)
 *   pop_back       O(1)
 *   insert         O(size())
 *   erase          O(size())
 *   front, back    O(1)
 */

template<typename T>
class Vector {
public:
    explicit Vector(size_t n = 0);

    Vector(size_t n, const T &x);

    Vector(const Vector<T> &other);

    ~Vector();

    // modifiers
    void push_back(const T &x);

    void pop_back();

    void insert(size_t index, const T &x);

    void erase(size_t i);

    void reserve(size_t n);

    // =========
    // accessors
    // =========

    // no bound checking
    T &operator[](size_t i);

    const T &operator[](size_t i) const;

    // bound checking
    const T &at(size_t index) const;

    T &front();

    const T &front() const;

    T &back();

    const T &back() const;

    size_t capacity();

    size_t size();

    bool empty();


private:
    T *m_p_data;
    size_t m_size;
    size_t m_capacity;
};

template<typename T>
Vector<T>::Vector(size_t n) : m_p_data(n == 0 ? nullptr : new T[n]), m_size(n), m_capacity(n << 1) {
    assert(n == 0 || n << 1 > n);

    for (int i = 0; i < m_size; i++) {
        m_p_data[i] = T();
    }
}

template<typename T>
Vector<T>::Vector(size_t n, const T &x) : m_p_data(n == 0 ? nullptr : new T[n]), m_size(n), m_capacity(n << 1) {
    assert(n == 0 || n << 1 > n);

    for (int i = 0; i < m_size; i++) {
        m_p_data[i] = x;
    }
}

template<typename T>
Vector<T>::Vector(const Vector<T> &other) : m_p_data(new T[other.m_capacity]), m_size(other.m_size), m_capacity(other.m_capacity) {
    memcpy(m_p_data, other.m_p_data, m_size * sizeof(T));
}

template<typename T>
Vector<T>::~Vector() {
    delete[] m_p_data;
}

template<typename T>
void
Vector<T>::push_back(const T &x) {
    if (m_size == m_capacity) {
        m_capacity = (m_capacity << 1) + 8;
        reserve(m_capacity);
    }
    m_p_data[m_size++] = x;
}

template<typename T>
void
Vector<T>::pop_back() {
    if (empty()) {
        throw std::out_of_range("Vector is empty while calling pop_back");
    }
    m_size--;
}

template<typename T>
void
Vector<T>::insert(size_t index, const T &x) {
    if (index >= m_size) {
        index = m_size;
    }
    if (m_size == m_capacity) {
        m_capacity = (m_capacity << 1) + 8;
        reserve(m_capacity);
    }
    for (size_t i = m_size; i >= index; i--) {
        m_p_data[i + 1] = m_p_data[i];
    }
    m_p_data[index] = x;
    m_size++;
}

template<typename T>
void
Vector<T>::erase(size_t index) {
    if (index >= m_size) {
        throw std::out_of_range("index out of range");
    }
    for (size_t i = index + 1; i < m_size; i++) {
        m_p_data[i - 1] = m_p_data[i];
    }
    m_size--;
}

template<typename T>
void
Vector<T>::reserve(size_t n) {
    T *new_p_data;
    if (n == 0) {
        new_p_data = nullptr;
    } else {
        new_p_data = new T[n];
    }
    memcpy(new_p_data, m_p_data, m_size * sizeof(T));

    delete[] m_p_data;

    m_p_data = new_p_data;
    m_capacity = n;
}

template<typename T>
T &
Vector<T>::operator[](size_t i) {
    return m_p_data[i];
}

template<typename T>
const T &
Vector<T>::operator[](size_t i) const {
    return m_p_data[i];
}

template<typename T>
const T &
Vector<T>::at(size_t index) const {
    if (index >= m_size) {
        throw std::out_of_range("index out of range");
    }
    return m_p_data[index];
}

template<typename T>
T &
Vector<T>::front() {
    return m_p_data[0];
}

template<typename T>
const T &
Vector<T>::front() const {
    return m_p_data[0];
}

template<typename T>
T &
Vector<T>::back() {
    return m_p_data[m_size - 1];
}

template<typename T>
const T &
Vector<T>::back() const {
    return m_p_data[m_size - 1];
}

template<typename T>
size_t
Vector<T>::capacity() {
    return m_capacity;
}

template<typename T>
size_t
Vector<T>::size() {
    return m_size;
}

template<typename T>
bool
Vector<T>::empty() {
    return m_size == 0;
}


#endif //DATA_STRUCTURES_CPP_VECTOR_H
