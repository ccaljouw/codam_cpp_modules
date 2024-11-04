#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
  if (argc == 1) {
    std::cerr << "Please provide a filename" << std::endl;
    return 1;
  }
  BitcoinExchange btc("data.csv");
  btc.valueAssets(argv[1]);
  return 0;
}