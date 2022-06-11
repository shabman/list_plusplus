#include <iostream>
#include "list.hpp"

template<class T, int size>
List<T, size>::List() { }

template<class T, int size>
List<T, size>::~List() {}

template<class T, int size>
List<T, size>::List(List<T, size>& cur) {
    this->array = cur.array;
    this->s = cur.s;
    cur = nullptr;
}

template<class T, int size>
void List<T, size>::push_back(const T& v) {
    if (this->array == nullptr)
       throw "Array is not initialised";
    if (size == this->s)
        this->re_alloc(size * 2, v);
    for (auto i = 0; i < this->s; i++) {
        if (this->array[i] == NULL) {
            this->array[i] = v;
            break;
        }
    }
}

template<class T, int size>
void List<T, size>::pop_back(int& i) {
    if (i > 0 || i > this->s)
        throw "Index is out of bounds";
    this->array[i] = NULL;
}

template<class T, int size>
void List<T, size>::pop_back(const T& v) {
    for (auto i = 0; i < size; i++) {
        if (this->array[i] == v) {
            this->array[i] = NULL;
            break;
        }
    }
}

template<class T, int size>
bool List<T, size>::is_empty() {
    return this->array[0] == NULL;
}

template<class T, int size>
int List<T, size>::length() {
    return size;
}

template<class T, int size>
T List<T, size>::at(const int& i) {
    if (i < 0 || i > size)
        throw "Index is out of bounds";
    return this->array[i];
}

template<class T, int size>
void List<T, size>::re_alloc(const int& n_size, T* buffer[]) {
    T n_temp_buf[n_size];
    for (auto i = 0; i < n_size; i++) {
        n_temp_buf[i] = this->array[i];
    }
    this->array = n_temp_buf;
    this->s = n_size;
    buffer = nullptr;
}

template<class T, int size>
List<T, size> List<T, size>::operator=(List<T, size> &other) {
    this->array = other.array;
    this->s = other.s;
    other = nullptr;
}