#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>


PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **input) : _strangler(-1) {
 int i = 1;
 _init = std::chrono::high_resolution_clock::now();
 for (i = 1; input[i] ; i++) {
    try {
      int num = std::stoi(input[i]);
      if (num < 0) {
        throw std::invalid_argument("not a positive number (" + std::string(input[i]) + ")");
      }
      _numbersToSort.push_back(num);
      _numbersToSortList.push_back(num);
    } catch (std::out_of_range &e) {
      throw std::out_of_range("int overflow (" + std::string(input[i]) + ")");
    } catch (std::invalid_argument &e) {
      throw std::invalid_argument("invallid argument (" + std::string(input[i]) + ")");
    }
  }
  if (i < 4) {
    throw std::invalid_argument("Not enough input to sort");
  }
  generateJacobsthalSequence(_pendElements.size());
  _inputParsed = std::chrono::high_resolution_clock::now();
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

void PmergeMe::generateJacobsthalSequence(size_t n) {
  if (n < 1) return;
  _jacobsthalSeq.push_back(0);
  if (n < 2) return;
  _jacobsthalSeq.push_back(1);
  if (n < 3) return;
  for (size_t i = 2; i < n; i++) {
    _jacobsthalSeq.push_back(_jacobsthalSeq[i - 1] + 2 * _jacobsthalSeq[i - 2]);
  }
  // return sequence starting from 3rd position as the first element (index 0) of the pend sequence has already been inserted
  // and the second and third element from the sequance are both 1
  _jacobsthalSeq.erase(_jacobsthalSeq.begin());
  _jacobsthalSeq.erase(_jacobsthalSeq.begin());
}

void PmergeMe::sortFordJohnson() {
  _startVectorSort = std::chrono::high_resolution_clock::now();
  std::vector<std::pair<int, int>> pairVect;
  this->createAndComparePairs(pairVect);
  this->sortPairsByFirstElement(pairVect);
  this->insertionSortVector();
  _sortedVector = std::chrono::high_resolution_clock::now();
  _startListSort = std::chrono::high_resolution_clock::now();
  std::list<std::pair<int, int>> pairList;
  this->createAndComparePairs(pairList);
  this->sortPairsByFirstElement(pairList);
  this->insertionSortList();
  _sortedList = std::chrono::high_resolution_clock::now();
}

std::chrono::duration<double, std::milli> PmergeMe::getParsingTime() const {
  return _inputParsed - _init;
}

void  PmergeMe::showProcess() const {
  std::cout << "\n---------------------------------" << std::endl;
  std::cout << "Time to parse input: " << this->getParsingTime().count() << " ms" << std::endl;
  std::cout << "---------------------------------" << std::endl;
  std::cout << "Vector before:\t";
  this->printSequence(_numbersToSort);
  std::cout << "List Before:\t";
  this->printSequence(_numbersToSortList);
  std::cout << "---------------------------------" << std::endl;
  std::cout << "Vector after:\t";
  this->printSequence(_mainChain);
  std::cout << "List After:\t";
  this->printSequence(_mainChainList);
  std::cout << "---------------------------------" << std::endl;
  std::cout << "Time to process a range of " << this->_numbersToSort.size() \
      << " elements with [std::vector] " << this->getSortingTimeVector().count() <<" ms\n";
  std::cout << "Time to process a range of " << this->_numbersToSortList.size() \
      << " elements with [std::list]\t " << this->getSortingTimeList().count() <<" ms\n";
  std::cout << "---------------------------------" << std::endl;
}


// VECTOR
// 1. Create and compair pairs
void  PmergeMe::createAndComparePairs(std::vector<std::pair<int, int>>& pairVect) {
  std::pair<int, int> tempPair;

  for (std::vector<int>::iterator it = _numbersToSort.begin(); it != _numbersToSort.end(); it++) {
    if (it + 1 != _numbersToSort.end()) {
      tempPair = std::make_pair( std::max(*it, *(it + 1)), std::min(*it, *(it + 1)));
      pairVect.push_back(tempPair);
      it++;
    } else {
      this->_strangler = *it;
    }
  }
}

// 2. sort paris by first element and create main chain and pend
// the first element of the second sequence can alreay be inserted at the front of the first sequence
void PmergeMe::sortPairsByFirstElement(std::vector<std::pair<int, int>>& pairVect) {
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

// std::lower_bound is used to find the first position in the sorted vector where the given 
// element can be inserted without violating the sorting order.
void PmergeMe::insertElemetInMainChainVector(int element) {
 auto pos = std::lower_bound(_mainChain.begin(), _mainChain.end(), element);
    _mainChain.insert(pos, element);
}

// 3. Insertion sort using Jacobsthal sequence
void PmergeMe::insertionSortVector() {

    for (size_t index : _jacobsthalSeq) {
      if (index < _pendElements.size()) {
        insertElemetInMainChainVector(_pendElements[index]);
      }
    }
    // Insert remaining elements that were not included in the Jacobsthal sequence
    for (size_t i = 0; i < _pendElements.size(); ++i) {
      if (std::find(_jacobsthalSeq.begin(), _jacobsthalSeq.end(), i) == _jacobsthalSeq.end()) {
        insertElemetInMainChainVector(_pendElements[i]);
      }
    }
}

std::chrono::duration<double, std::milli> PmergeMe::getSortingTimeVector() const {
  return _sortedVector - _startVectorSort;
}

// LIST
// TODO: fix this
void  PmergeMe::createAndComparePairs(std::list<std::pair<int, int>>& pairList) {
  if (_numbersToSortList.empty()) return; 

  auto it = _numbersToSortList.begin();
  auto end = _numbersToSortList.end();
  while (it != end) {
    if (std::next(it) == end) {
      this->_strangler = *it;
      break;
    }
    auto next_it = std::next(it);
    std::pair<int, int> tempPair = std::make_pair(std::max(*it, *next_it), std::min(*it, *next_it));
    pairList.push_back(tempPair);
    if (next_it == end) {
      break;
    }
    std::advance(it, 2);
  }
}

void  PmergeMe::sortPairsByFirstElement(std::list<std::pair<int, int>>& pairList) {
  pairList.sort([](const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.first < b.first;
  });
  _mainChainList.push_back(pairList.front().second);
  _mainChainList.push_back(pairList.front().first);
  for (auto it = std::next(pairList.begin()); it != pairList.end(); ++it) {
    _mainChainList.push_back(it->first);
    _pendElementsList.push_back(it->second);
  }

  if (_strangler != -1) {
      _pendElementsList.push_back(_strangler);
  }
}

void PmergeMe::insertionSortList() {
  auto pendIt = _pendElementsList.begin();
  for (size_t index : _jacobsthalSeq) {
    std::advance(pendIt, index);
    if (pendIt != _pendElementsList.end()) {
        insertElemetInMainChainList(*pendIt);
    }
    pendIt = _pendElementsList.begin();
  }

  for (size_t i = 0; i < _pendElementsList.size(); ++i) {
    if (std::find(_jacobsthalSeq.begin(), _jacobsthalSeq.end(), i) == _jacobsthalSeq.end()) {
        std::advance(pendIt, i);
        insertElemetInMainChainList(*pendIt);
    }
  }
}

void  PmergeMe::insertElemetInMainChainList(int element) {
  auto pos = _mainChainList.begin();
  while (pos != _mainChainList.end() && *pos < element) {
    ++pos;
  }
  _mainChainList.insert(pos, element);
}

std::chrono::duration<double, std::milli> PmergeMe::getSortingTimeList() const {
  return _sortedList - _startListSort;
}
