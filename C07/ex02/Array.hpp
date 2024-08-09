#ifndef ARRAY_H
# define ARRAY_H

template<class T>
class Array {
  public:
    Array();
    Array(unsigned int size);
    ~Array();
    Array(const Array<T>& rhs);
    Array<T>& operator=(const Array<T>& rhs);

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    unsigned int size() const;
    void printElements() const;

  private:
    unsigned int _size;
    T* _elements;
};

#include "Array.tpp"

#endif