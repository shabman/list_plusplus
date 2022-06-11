#ifndef LIST_IMPL_LIST_HPP
#define LIST_IMPL_LIST_HPP

template<class T, int size>
class List {
public:
    T* array[size];
    int s;
public:
    List() ;
    ~List();
    List(List<T, size>& cur);
    void push_back(const T& v);
    void pop_back(const T& v);
    void pop_back(int& i);
    bool is_empty();
    int length();
    T at(const int& i);
public:
    // other
    List<T, size> operator=(List<T, size>& other);
protected:
    void re_alloc(const int& n_size, T* buffer[]);
};

#endif /* LIST_IMPL_LIST_HPP */