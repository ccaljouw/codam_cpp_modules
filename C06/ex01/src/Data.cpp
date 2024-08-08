#include "Data.hpp"

std::ostream& operator<<(std::ostream& out, const Data& data) {
  out << "Data { number: " << data.number << ", text: " << data.text << " }";
  return out;
}