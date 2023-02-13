#ifndef DATA_STRUCTURES_CPP_VECTOR_H
#define DATA_STRUCTURES_CPP_VECTOR_H

#include <cstddef>

template<typename T>
class Vector {
public:
    Vector();
    ~Vector();
private:
    T* data;
    size_t size;
    size_t capacity;
};



#endif //DATA_STRUCTURES_CPP_VECTOR_H
