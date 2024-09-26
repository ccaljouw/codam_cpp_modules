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
  // store sequence starting from 3rd position as the first element (index 0) of the pend sequence has already been inserted
  // and the second and third element from the sequance are both 1
  _jacobsthalSeq.erase(_jacobsthalSeq.begin());
  _jacobsthalSeq.erase(_jacobsthalSeq.begin());
}

void PmergeMe::sortFordJohnson() {
  _startVectorSort = std::chrono::high_resolution_clock::now();
  std::vector<std::pair<int, int>> pairVect;
  this->createAndComparePairs(pairVect);
  this->mergeSortVector(pairVect, 0, pairVect.size() - 1);
  this->createTwoChainsVector(pairVect);
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
  if (!std::is_sorted(_mainChain.begin(), _mainChain.end()) || !std::is_sorted(_mainChainList.begin(), _mainChainList.end()))
    std::cout << "Sorting Error!" << std::endl;
  else {
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
    std::cout << "Time to process " << this->_numbersToSort.size() \
        << " elements\nwith [std::vector]\t" << this->getSortingTimeVector().count() <<" ms\n";
    std::cout << "with [std::list]\t" << this->getSortingTimeList().count() <<" ms\n";
    std::cout << "---------------------------------" << std::endl;
  }
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
void PmergeMe::mergeVector(std::vector<std::pair<int, int>>& pairVect, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<std::pair<int, int>> leftArr(n1);
    std::vector<std::pair<int, int>> rightArr(n2);

    // Copy data to temporary vectors
    for (int i = 0; i < n1; i++) {
        leftArr[i] = pairVect[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = pairVect[mid + 1 + i];
    }

    // Merge the temporary arrays back into the main array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i].first <= rightArr[j].first) {
            pairVect[k] = leftArr[i];
            i++;
        } else {
            pairVect[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of leftArr
    while (i < n1) {
        pairVect[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy any remaining elements of rightArr
    while (j < n2) {
        pairVect[k] = rightArr[j];
        j++;
        k++;
    }
}

void PmergeMe::mergeSortVector(std::vector<std::pair<int, int>>& pairVect, int left, int right) {
  if (left < right) {
      int mid = left + (right - left) / 2;

      mergeSortVector(pairVect, left, mid);
      mergeSortVector(pairVect, mid + 1, right);

      mergeVector(pairVect, left, mid, right);
  }
}

// the first element of the second sequence can alreay be inserted at the front of the first sequence
void PmergeMe::createTwoChainsVector(std::vector<std::pair<int, int>>& pairVect) {
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
void PmergeMe::insertionSortVector() {
  long lastIndex = - 1;
  generateJacobsthalSequence(_pendElements.size());
  
  for (long index : _jacobsthalSeq) {
    long prevIndex = lastIndex;
    if (lastIndex >= (long)_pendElements.size())
      break;
    if (index > prevIndex) {
      lastIndex = index;
      while (index > prevIndex) {
        if (index < (long)_pendElements.size())
          // insertElemetInMainChainVector(_pendElements[index]);
          binaryInsertVector(_pendElements[index]);
        index--;
      }
    }
  }
}

void PmergeMe::binaryInsertVector(int element) {
    int size = _mainChain.size();
    int low = 0, high = size - 1;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (_mainChain[mid] == element) {
            low = mid;
            break;
        } else if (_mainChain[mid] < element) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    _mainChain.insert(_mainChain.begin() + low, element);
}


// 4. get time sorting vector
std::chrono::duration<double, std::milli> PmergeMe::getSortingTimeVector() const {
  return _sortedVector - _startVectorSort;
}


// LIST
// 1. Create and compair pairs
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

// 2. sort paris by first element and create main chain and pend
// the first element of the second sequence can alreay be inserted at the front of the first sequence
std::list<std::pair<int, int>> PmergeMe::mergeList(const std::list<std::pair<int, int>>& left, const std::list<std::pair<int, int>>& right) {
    std::list<std::pair<int, int>> result;
    auto it1 = left.begin();
    auto it2 = right.begin();

    // Merge the two lists based on the first element of the pairs
    while (it1 != left.end() && it2 != right.end()) {
        if (it1->first <= it2->first) {
            result.push_back(*it1);
            ++it1;
        } else {
            result.push_back(*it2);
            ++it2;
        }
    }

    // Append any remaining elements from the left list
    while (it1 != left.end()) {
        result.push_back(*it1);
        ++it1;
    }

    // Append any remaining elements from the right list
    while (it2 != right.end()) {
        result.push_back(*it2);
        ++it2;
    }

    return result;
}

// Function to perform merge sort on a list of pairs
std::list<std::pair<int, int>> PmergeMe::mergeSortList(std::list<std::pair<int, int>>& pairList) {
    if (pairList.size() <= 1) {
        return pairList;
    }

    // Split the list into two halves
    auto mid = pairList.begin();
    std::advance(mid, pairList.size() / 2);

    std::list<std::pair<int, int>> left(pairList.begin(), mid);
    std::list<std::pair<int, int>> right(mid, pairList.end());

    // Recursively sort both halves
    left = mergeSortList(left);
    right = mergeSortList(right);

    // Merge the two sorted halves
    return mergeList(left, right);
}

void PmergeMe::createTwoChainsList(std::list<std::pair<int, int>>& pairList) {
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

// 3. Insertion sort using Jacobsthal sequence
void PmergeMe::insertionSortList() {
  std::list<int>::iterator start = _pendElementsList.begin();
  std::list<int>::iterator pendIt = start;
  long prevIndex = -1;
  long k;

  for (long i = 0; i < (long)_jacobsthalSeq.size(); ++i) {
    if (prevIndex >= (long)_pendElementsList.size())
      break;
    k = _jacobsthalSeq[i];
    if (k < (long)_pendElementsList.size()) {
      std::advance(pendIt, k);
    } else {
      std::advance(pendIt, _pendElementsList.size() - 1);
    }
    while (k > prevIndex) {
      if (k < (long)_pendElementsList.size()) {
        // insertElemetInMainChainList(*pendIt);
        binaryInsertList(*pendIt);
        pendIt--;
      }
      k--;
    }
    pendIt = start;
    prevIndex = _jacobsthalSeq[i];
  }
}

void PmergeMe::binaryInsertList(int element) {
    auto low = _mainChainList.begin();
    auto high = _mainChainList.end();
    auto mid = low;
    
    while (std::distance(low, high) > 0) {
        mid = low;
        std::advance(mid, std::distance(low, high) / 2);
        
        if (*mid == element) {
            low = mid;
            break;
        } else if (*mid < element) {
            low = ++mid;
        } else {
            high = mid;
        }
    }
    _mainChainList.insert(low, element);
}

// 4. get time sorting list
std::chrono::duration<double, std::milli> PmergeMe::getSortingTimeList() const {
  return _sortedList - _startListSort;
}
