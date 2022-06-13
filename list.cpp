#include <iostream>
#include "list.hpp"

#define print(x) std::cout << x << '\n'

template<class T, int size>
List<T, size>::List() {
    print("SIZE");
    print(this->s);
};

template<class T, int size>
List<T, size>::~List() = default;

template<class T, int size>
List<T, size>::List(List<T, size>& cur) {
    this->array = cur.array;
    this->s = cur.s;
    cur = nullptr;
}

template<class T, int size>
void List<T, size>::push_back(const T& v) {
    if (size == this->s) {
        this->re_alloc(this->s * 2, this->array);
    }
    for (auto i = 0; i < this->s; i++) {
        if (this->array[i] == 0) {
            this->array[i] = v;
            break;
        }
    }
}

template<class T, int size>
void List<T, size>::pop_back(const T& v) {
    for (auto i = 0; i < this->s; i++) {
        if (this->array[i] == v) {
            this->array[i] = 0;
            break;
        }
    }
}

template<class T, int size>
void List<T, size>::pop_back(int& i) {
    if (i < 0 || i > this->s) {
        print("index is out of bounds");
        return;
    }
    this->array[i] = 0;
}

template<class T, int size>
bool List<T, size>::is_empty() {
    return this->array[0] == 0;
}

template<class T, int size>
int List<T, size>::length() {
    return size;
}

template<class T, int size>
T List<T, size>::at(const int& i) {
    if (i < 0 || i > this->s) {
        print("index is out of bounds");
    }
    return this->array[i];
}

template<class T, int size>
T& List<T, size>::operator=(List<T, size>& other) {
    this->array = other.array;
    this->s = other.s;
    other = nullptr;
    return this->array;
}

template<class T, int size>
void List<T, size>::re_alloc(const int& n_size, T buffer[]) {
    T copy_arr[n_size];
    for (auto i = 0; i < n_size; i++) {
        copy_arr[i] = buffer[i];
    }
    //delete buffer;
}