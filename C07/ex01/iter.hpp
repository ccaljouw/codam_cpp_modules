#ifndef ITER_H
# define ITER_H

template <typename T>
void iter(T* array, int length, void (*f)(T const&)) {
  for (int i = 0; i < length; i++) {
    f(array[i]);
  }
}

#endif