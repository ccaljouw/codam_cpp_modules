#include <iostream>

template <typename T>
Array<T>::Array() : _size(0) {
  this->_elements = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int size) : _size(size) {
  this->_elements = new T[_size];
}

template <typename T>
Array<T>::~Array() {
  delete[] this->_elements;
}

template <typename T>
Array<T>::Array(Array const& rhs) {
  *this = rhs;
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T> const& rhs) {
  if (this != &rhs) {
    this->_size = rhs.size();
    this->_elements = new T[this->_size];
    for (unsigned int i = 0; i < this->_size; i++) {
      this->_elements[i] =  rhs._elements[i];
    } 
  }
  return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int i) {
  if (i >= this->_size) {
    throw std::out_of_range("Index out of range");
  }
  return this->_elements[i];
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const {
  if (i >= this->_size) {
    throw std::out_of_range("Index out of range");
  }
  return this->_elements[i];
}

template <typename T>
unsigned int Array<T>::size() const {
  return this->_size;
}

template <typename T>
void Array<T>::printElements() const {
  std::cout << "[";
  for (std::size_t i = 0; i < this->_size; ++i) {
      std::cout << this->_elements[i];
      if (i < this->_size - 1) {
          std::cout << ", ";
      }
  }
  std::cout << "]" << std::endl;
}
