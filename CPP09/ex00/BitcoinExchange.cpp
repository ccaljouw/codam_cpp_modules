#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <regex>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string databaseFilePath) {
  std::ifstream file(databaseFilePath);
  std::string line;
  if (!file.is_open()) {
    std::cerr << "Could not open database file" << std::endl;
  }
  std::getline(file, line); //skip first line
  while (std::getline(file, line)) {
    std::istringstream lineStream(line);
    std::string date;
    std::string value;
    std::getline(lineStream, date, ',');
    std::getline(lineStream, value);
    if (!isValidDate(date) || !isValidValue(value)) {
      std::cerr << "Skipping database line: " << line << std::endl;
      std::cout << "*" << date << "* *" << value << "*" << std::endl;
      continue;
    }
    _dataBase.insert({date, std::stof(value)});
  }


}


BitcoinExchange::BitcoinExchange(BitcoinExchange const& rhs) {
  *this = rhs;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& rhs) {
  if (this != &rhs) {
    _dataBase = rhs._dataBase;
  }
  return *this;
}

bool BitcoinExchange::isValidDate(const std::string &date) {
  std::regex datePattern("^(\\d{4}-\\d{2}-\\d{2})$");
  bool valid = std::regex_match(date, datePattern);
  if (!valid) {
    std::cerr << "Error: invalid date (" << date << ")" << std::endl;
    return false;
  }
  std::istringstream lineStream(date);
  std::string year;
  std::string month;
  std::string day;
  std::getline(lineStream, year, '-');
  std::getline(lineStream, month, '-');
  std::getline(lineStream, day);
  if (std::stoi(month) < 1 || std::stoi(month) > 12) {
    std::cerr << "Error: invalid date (" << date << ")" << std::endl;
    return false;
  }
  if (std::stoi(day) < 1 || std::stoi(day) > 31) {
    std::cerr << "Error: invalid date (" << date << ")" << std::endl;
    return false;
  }
  return true;
}

bool BitcoinExchange::isValidValue(const std::string& valueStr) {
  try {
    float value = std::stof(valueStr);
    if (value < 0) {
      std::cerr << "Error: negative value (" << valueStr << ")" << std::endl;
      return false;
    }
    return true;
  } catch (const std::invalid_argument&) {
    std::cerr << "Error: invalid value (" << valueStr << ")" << std::endl;
    return false;
  } catch (const std::out_of_range&) {
    std::cerr << "Error: value out of range (" << valueStr << ")" << std::endl;
    return false;
  }
}

void BitcoinExchange::valueAssets(std::string assetFilePath) {
  std::ifstream file(assetFilePath);
  std::string line;
  if (!file.is_open()) {
    std::cerr << "Error: could not open assets file" << std::endl;
  }
  while (std::getline(file, line)) {
    std::istringstream lineStream(line);
    std::string date;
    std::string value;
    std::getline(lineStream, date, '|');
    std::getline(lineStream, value);
    date.erase(date.find_last_not_of(" \n\r\t") + 1);
    value.erase(0, value.find_first_not_of(" \n\r\t"));
    if (date == "date")
      continue;
    if (!isValidDate(date) || !isValidValue(value)) {
      continue;
    }
    if (std::stof(value) > 1000) {
      std::cerr << "Error: value to big (" << value << ")" << std::endl;
      continue;
    }
    this->calculateValue(date, std::stof(value));
  }
}

void  BitcoinExchange::calculateValue(std::string date, float assets) {
  if (_dataBase.empty()) {
    return;
  }
  //find the first element in the map that has a key greater than the specified key
  auto itterator = _dataBase.upper_bound(date);
  if (itterator == _dataBase.begin()) {
    std::cout << "No data for this date" << std::endl;
    return;
  }
  itterator--;
  std::cout << date << " => " << assets << " = " << itterator->second * assets << std::endl;
}
