#ifndef SPAN_H
# define SPAN_H

#include <vector>
#include <iostream>

class Span {
  public:
    Span(unsigned int N);
    Span(const Span& rhs);
    Span& operator=(const Span& rhs);
    ~Span();

    void addNumber(int number);
    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int shortestSpan() const;
    int longestSpan() const;

    std::vector<int> getElements() const;

  private:
    unsigned int      _maxSize;
    std::vector<int>  _elements;
    Span();
};

std::ostream& operator<<(std::ostream& out, Span const& obj);

#endif
