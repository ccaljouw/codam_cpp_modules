#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>


PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **input) : _strangler(-1) {
 int i = 1;
 _begin = std::chrono::high_resolution_clock::now();
 for (i = 1; input[i] ; i++) {
    try {
      int num = std::stoi(input[i]);
      if (num < 0) {
        throw std::invalid_argument("not a positive number (" + std::string(input[i]) + ")");
      }
      _numbersToSort.push_back(num);
    } catch (std::out_of_range &e) {
      throw std::out_of_range("int overflow (" + std::string(input[i]) + ")");
    } catch (std::invalid_argument &e) {
      throw std::invalid_argument("invallid argument (" + std::string(input[i]) + ")");
    }
  }
  if (i < 4) {
    throw std::invalid_argument("Not enough input to sort");
  }
}

PmergeMe::PmergeMe(PmergeMe const& rhs) {
  *this = rhs;
}

PmergeMe::~PmergeMe() {}

//TODO: implement with final class
PmergeMe& PmergeMe::operator=(PmergeMe const& rhs) {
  if (this != &rhs) {
    _numbersToSort = rhs._numbersToSort;
  }
  return *this;
}

size_t PmergeMe::getSize() const {
  return _numbersToSort.size();
}

void PmergeMe::printNumbersToSort() const {
  std::cout << "Before: ";
  this->printVector(_numbersToSort);
}

void PmergeMe::clearChains() {
  this->_mainChain.clear();
  this->_pendElements.clear();
}

void PmergeMe::printSortedNumbers() const {
  std::cout << "After: ";
  this->printVector(_mainChain);
}

void PmergeMe::printVector(std::vector<int> const& vec) const {
  for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++) {
    std::cout << *it;
    if (it != vec.end() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << std::endl;
}

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n) {
  std::vector<size_t> jacobsthalSeq;
  if (n < 1) return jacobsthalSeq;
  jacobsthalSeq.push_back(0);
  if (n < 2) return jacobsthalSeq;
  jacobsthalSeq.push_back(1);
  if (n < 3) return jacobsthalSeq;
  for (size_t i = 2; i < n; i++) {
    jacobsthalSeq.push_back(jacobsthalSeq[i - 1] + 2 * jacobsthalSeq[i - 2]);
  }
  // return sequence starting from 3rd position as the first element (index 0) of the pend sequence has already been inserted
  // and the second and third element from the sequance are both 1
  std::vector<size_t> result(jacobsthalSeq.begin() + 2, jacobsthalSeq.end());
  return result;
}

// std::lower_bound is used to find the first position in the sorted vector where the given 
// element can be inserted without violating the sorting order.
void PmergeMe::insertElemetInMainChain(int element) {
 auto pos = std::lower_bound(_mainChain.begin(), _mainChain.end(), element);
    _mainChain.insert(pos, element);
}

// 1. Create and compair pairs
std::vector<std::pair<int, int>> PmergeMe::createAndComparePairs() {
  std::vector<std::pair<int, int>> pairVect;
  std::pair<int, int> tempPair;

  for (std::vector<int>::iterator it = _numbersToSort.begin(); it != _numbersToSort.end(); it++) {
    if (it + 1 != _numbersToSort.end()) {
      tempPair = std::make_pair(std::max(*it, *(it + 1)), std::min(*it, *(it + 1)));
      pairVect.push_back(tempPair);
      it++;
    } else {
      this->_strangler = *it;
    }
  }
  return pairVect;
}

// 2. sort paris by first element and create main chain and pend
// the first element of the second sequence can alreay be inserted at the front of the first sequence
void PmergeMe::sortPairsByFirstElement(std::vector<std::pair<int, int>> pairVect) {
  if (pairVect.empty()) return;

  auto compare = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.first < b.first;
  };
  std::sort(pairVect.begin(), pairVect.end(), compare);

  // chreate seperate chains from pairs
  // the first element of the second sequence can alreay be inserted at the front of the first sequence
  _mainChain.reserve(_mainChain.size() + pairVect.size() + 1);
  _pendElements.reserve(_pendElements.size() + pairVect.size());

  _mainChain.push_back(pairVect.front().second);
  _mainChain.push_back(pairVect.front().first);
  for (auto it = pairVect.begin() + 1; it != pairVect.end(); ++it) {
      _mainChain.push_back(it->first);
      _pendElements.push_back(it->second);
  }

  // Handle the strangler, if present
  if (_strangler != -1) {
      _pendElements.push_back(_strangler);
  }
}

// 3. Insertion sort using Jacobsthal sequence
void PmergeMe::insertionSortUsingJacobsthal() {
  std::vector<size_t> jacobsthal = generateJacobsthalSequence(_pendElements.size());

    for (size_t index : jacobsthal) {
      if (index < _pendElements.size()) {
        insertElemetInMainChain(_pendElements[index]);
      }
    }
    // Insert remaining elements that were not included in the Jacobsthal sequence
    for (size_t i = 0; i < _pendElements.size(); ++i) {
      if (std::find(jacobsthal.begin(), jacobsthal.end(), i) == jacobsthal.end()) {
        insertElemetInMainChain(_pendElements[i]);
      }
    }
}

void PmergeMe::sortFordJohnson() {
  this->clearChains();
  _inputParsed = std::chrono::high_resolution_clock::now();
  // 1. generate pairs and put largest number first
  std::vector<std::pair<int, int>> tempVect = this->createAndComparePairs();

  // 2. sort pairs by first element and create 2 seperate sequences
  this->sortPairsByFirstElement(tempVect);

  // 3. perform insertion sort based on Jacobsthal sequence
  this->insertionSortUsingJacobsthal();
  _sorted = std::chrono::high_resolution_clock::now();
}

std::chrono::duration<double, std::milli> PmergeMe::getParsingTime() const {
  return _inputParsed - _begin;
}

std::chrono::duration<double, std::milli> PmergeMe::getSortingTime() const {
  return _sorted - _inputParsed;
}

void  PmergeMe::showProcess() const {
  this->printNumbersToSort();
  this->printSortedNumbers();
  std::cout << "Time to parse input: " << this->getParsingTime().count() << " ms" << std::endl;
  std::cout << "Time to process a range of " << this->getSize() \
      << " elements with std::vector : " << this->getSortingTime().count() <<" ms" << std::endl;
}

