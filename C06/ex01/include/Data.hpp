#ifndef DATA_H
# define DATA_H

#include <iostream>
#include <string>

struct Data {
  int number;
  std::string text;
};

std::ostream& operator<<(std::ostream& out, const Data& data);

#endif
