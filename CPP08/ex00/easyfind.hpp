#ifndef EASYFIND_H
# define EASYFIND_H

#include <algorithm>

template<typename T>
typename T::iterator easyfind(T& container, int value) {
  typename T::iterator it = std::find(container.begin(), container.end(), value);
  if (it == container.end()) {
    throw std::runtime_error("Value not found");
  }
  return it;
}

#endif