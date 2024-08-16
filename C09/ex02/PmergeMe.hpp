#ifndef PMERGEME_H
# define PMERGEME_H

#include <iostream>
#include <string>
#include <vector>
#include <list>

class PmergeMe {

  public:

    PmergeMe(char **input);
    PmergeMe(PmergeMe const& rhs);
    virtual ~PmergeMe();

    PmergeMe& operator=(PmergeMe const& rhs);

    void    showProcess() const;
    void    sortFordJohnson();

  private:

    int                                            _strangler;
    std::vector<size_t>                            _jacobsthalSeq;
    std::chrono::high_resolution_clock::time_point _startListSort;
    std::chrono::high_resolution_clock::time_point _sortedList;    

    std::chrono::duration<double, std::milli> getParsingTime() const;
    void                                      generateJacobsthalSequence(size_t n);
  
    template <typename T>
    void  printSequence(T const& seq) const {
      for (const auto& element : seq) {
          std::cout << element << " ";
      }
      std::cout << std::endl;
    }

  // vector
    std::vector<int>                               _numbersToSort;
    std::vector<int>                               _mainChain;
    std::vector<int>                               _pendElements;
    std::chrono::high_resolution_clock::time_point _startVectorSort;
    std::chrono::high_resolution_clock::time_point _sortedVector;

    std::chrono::duration<double, std::milli>      getSortingTimeList() const;

    void  createAndComparePairs(std::vector<std::pair<int, int>>& pairVect);
    void  sortPairsByFirstElement(std::vector<std::pair<int, int>>& pairVect);
    void  insertionSortVector();
    void  insertElemetInMainChainVector(int element);

  
  // list
    std::list<int>                                 _numbersToSortList;
    std::list<int>                                 _mainChainList;
    std::list<int>                                 _pendElementsList;
    std::chrono::high_resolution_clock::time_point _init;
    std::chrono::high_resolution_clock::time_point _inputParsed;

    std::chrono::duration<double, std::milli>      getSortingTimeVector() const;

    void  createAndComparePairs(std::list<std::pair<int, int>>& pairList);
    void  sortPairsByFirstElement(std::list<std::pair<int, int>>& pairList);
    void  insertionSortList();
    void  insertElemetInMainChainList(int element);

    PmergeMe();
};

#endif