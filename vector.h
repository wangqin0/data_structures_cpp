#ifndef DATA_STRUCTURES_CPP_VECTOR_H
#define DATA_STRUCTURES_CPP_VECTOR_H

#include <cstddef>

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
    Vector();
    Vector(size_t n, const T& x);
    ~Vector();

    T& operator[](size_t i);
    const T& operator[](size_t i) const;

    T& at(size_t i);

    // modifiers
    void push_back(const T& x);
    void pop_back();
    void insert(size_t i, const T& x);
    void erase(size_t i);

    // accessors
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;

    size_t size();

    void reserve(size_t n);


private:
    T* m_p_data;
    size_t m_size;
    size_t m_capacity;
};



#endif //DATA_STRUCTURES_CPP_VECTOR_H
