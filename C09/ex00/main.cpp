#include "BitcoinExchange.hpp"
#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


void leaks(void) {
	std::cout << "*********************************" << std::endl;
	system("leaks btc -q");
	std::cout << "*********************************" << std::endl;
}

int main(int argc, char **argv)
{
  atexit(leaks);
  if (argc == 1) {
    std::cerr << "Please provide a filename" << std::endl;
    return 1;
  }
  BitcoinExchange btc("data.csv");
  btc.valueAssets(argv[1]);
  return 0;
}