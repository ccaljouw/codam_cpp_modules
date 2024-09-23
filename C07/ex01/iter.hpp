#ifndef ITER_H
# define ITER_H

template <typename T, typename Func>
void iter(T* array, int length, void (*f)(Func)) {
  for (int i = 0; i < length; i++) {
    f(array[i]);
  }
}

#endif