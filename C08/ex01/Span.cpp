#include "Span.hpp"
#include <iterator>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& rhs) {
  *this = rhs;
}

Span& Span::operator=(const Span& rhs) {
  if (this != &rhs) {
    _maxSize = rhs._maxSize;
    _elements = rhs._elements;
  }
  return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
  if (_elements.size() >= _maxSize) {
    throw std::out_of_range("Span is full");
  }
  _elements.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end) {
  if ((_elements.size() + static_cast<size_t>(std::distance(start, end))) > _maxSize) {
    throw std::out_of_range("Span is full");
  }
  _elements.insert(_elements.end(), start, end);
}

int Span::shortestSpan() const {
  if (_elements.size() <= 1) {
    throw std::out_of_range("Not enough elements to calculate span");
  }
  std::vector<int> sortedVector = _elements;
  std::sort(sortedVector.begin(), sortedVector.end());
  int min = INT_MAX;
  for (std::size_t i = 1; i < sortedVector.size(); ++i) {
    if (sortedVector[i] - sortedVector[i - 1] < min) {
      min = sortedVector[i] - sortedVector[i - 1];
    }
  }
  return min;
}

int Span::longestSpan() const {
  if (_elements.size() <= 1) {
    throw std::out_of_range("Not enough elements to calculate span");
  }
  std::vector<int> sortedVector = _elements;
  std::sort(sortedVector.begin(), sortedVector.end());
  return sortedVector.back() - sortedVector.front();
}

std::vector<int> Span::getElements() const {
  return _elements;
}

std::ostream& operator<<(std::ostream& out, Span const& obj) {
  std::vector<int> elements = obj.getElements();
  out << "[";
  for (std::vector<int>::const_iterator it = elements.begin(); it != elements.end(); it++) {
    out << *it;
    if (it != elements.end() - 1) {
      out << ", ";
    }
  }
  out << "]";
  return out;
}