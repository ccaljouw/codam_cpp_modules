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

    size_t  getSize() const;
    std::chrono::duration<double, std::milli> getParsingTime() const;
    std::chrono::duration<double, std::milli> getSortingTime() const;
  
    
    void    showProcess() const;
    void    sortFordJohnson();

  private:
    std::vector<int>  _numbersToSort;
    std::vector<int>  _mainChain;
    std::vector<int>  _pendElements;
    int               _strangler;

    std::chrono::high_resolution_clock::time_point _begin;
    std::chrono::high_resolution_clock::time_point _inputParsed;
    std::chrono::high_resolution_clock::time_point _sorted;

    void    clearChains();
    void    printVector(std::vector<int> const& vec) const;
    void    printNumbersToSort() const;
    void    printSortedNumbers() const;

    std::vector<size_t>              generateJacobsthalSequence(size_t n);
    std::vector<std::pair<int, int>> createAndComparePairs();
    void                             sortPairsByFirstElement(std::vector<std::pair<int, int>> pairVect);
    void                             insertionSortUsingJacobsthal();
    void                             insertElemetInMainChain(int element);


    PmergeMe();
};

std::ostream& operator<<(std::ostream &out, PmergeMe const &obj);

#endif