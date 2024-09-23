#ifndef BITCOIN_H
# define BITCOIN_H

#include <map>
#include <string>

class BitcoinExchange {
  public:
    BitcoinExchange(std::string databaseFilePath);
    BitcoinExchange(BitcoinExchange const& rhs);
    ~BitcoinExchange();

    BitcoinExchange& operator=(BitcoinExchange const& rhs);
    void valueAssets(std::string assetFilePath);
  
  private:
    std::map<std::string, float> _dataBase;
    bool isValidDate(const std::string& date);
    bool isValidValue(const std::string& value);
    void calculateValue(std::string date, float assets);

    BitcoinExchange();
};

#endif
