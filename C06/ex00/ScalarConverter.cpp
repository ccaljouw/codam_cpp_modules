#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

ScalarConverter::ScalarConverter() {
  return;
}

ScalarConverter::ScalarConverter(ScalarConverter const& rhs) {
  *this = rhs;
  return;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& rhs) {
  (void)rhs;
  return *this;
}

ScalarConverter::~ScalarConverter() {
  return;
}

void ScalarConverter::convert(const std::string& str) {
  std::cout << "---------------------------------" << std::endl;
  if (isCharacterLiteral(str))
    return;
  if (isIntLiteral(str))
    return;
  if (isFloatLiteral(str))
    return;
  if (isDoubleLiteral(str))
    return;
  std::cout << "Not a valid literal" << std::endl;
  return;
}

// only chars surrounded by single quotes are considered character literals as this is
// the definition of a character literal in c++
bool ScalarConverter::isCharacterLiteral(const std::string& str) {
  if (str.length() == 3 && str[0] == '\'' && str[2] == '\'') {
    std::cout << "Char literal" << std::endl;
    checkChar(str[1]);
    std::cout << "Int: " << static_cast<int>(str[1]) << std::endl;
    std::cout << "Float: " << static_cast<float>(str[1]) << ".0f" << std::endl;
    std::cout << "Double: " << static_cast<double>(str[1]) << ".0" << std::endl;
    return true;
  }
  return false;
}

bool ScalarConverter::isIntLiteral(const std::string& str) {
  try {
    for (size_t i = 0; i < str.length(); i++) {
      if (!isdigit(str[i]) && (i != 0 || (str[i] != '+' && str[i] != '-')))
        return false;
    }
    int i = std::stoi(str);
    if (i != std::stod(str))
      return false;
    std::cout << "Int literal" << std::endl;

    doubleToChar(static_cast<double>(i));
    std::cout << "Int: " << i << std::endl;
    intToFloat(i, 1);
    std::cout << "Double: " << static_cast<double>(i) << std::endl;

    return true; 
  } catch (std::exception& e) {
    return false;
  }
}

bool ScalarConverter::isFloatLiteral(const std::string& str) {
  int precision = 0;
  try {
    if (str.back() != 'f' && str.back() != 'F') {
      return false;
    }
    float f = std::stof(str);
    if (isdigit(str[0]) || ((str[0] == '+' || str[0] == '-' || '.') && isdigit(str[1]))) {
      precision = checkPrecision(str);
      if (precision == -1) {
        return false;
      }
      if (precision > (std::numeric_limits<float>::digits10)) {
        std::cout << "Float error: decimal limit float is " << static_cast<int>(std::numeric_limits<float>::digits10) << std::endl;
        return false;
      }
    }
    std::cout << "Float literal" << std::endl;
    doubleToChar(static_cast<double>(f));
    doubleToInt(static_cast<double>(f));
    //TODO: print . when precision is 0
    std::cout << std::fixed << std::setprecision(precision) << "Float: " << f << "f" << std::endl;
    std::cout << std::fixed << std::setprecision(precision) << "Double: " << static_cast<double>(f) << std::endl;
    return true; 
  } catch (std::exception& e) {
    std::cout << "Float error" << std::endl;
    return false;
  }
}

bool ScalarConverter::isDoubleLiteral(const std::string& str) {
  int precision = 0;
  try {
    if (str.back() == 'f' || str.back() == 'F') {
      return false;
    }

    double d = std::stod(str);
    
    if (isdigit(str[0]) || ((str[0] == '+' || str[0] == '-' || str[0] == '.') && isdigit(str[1]))) {
      precision = checkPrecision(str);
      if (precision == -1)
        return false;
      if (precision > (std::numeric_limits<double>::digits10)) {
        std::cout << "Double error: decimal limit double is " << static_cast<int>(std::numeric_limits<double>::digits10) << std::endl;
        return false;
      }
    }
    std::cout << "Double literal" << std::endl;
    doubleToChar(d);
    doubleToInt(d);
    doubleToFloat(d, precision);
    //TODO: print . when precision is 0
    std::cout << std::fixed << std::setprecision(precision) << "Double: " << d << std::endl;
    return true; 
  } catch (std::exception& e) {
    return false;
  }
}

void ScalarConverter::checkChar(char c) {
  if (c < 32 || c > 126) {
      std::cout << "Char: Non displayable" << std::endl;
  }
  else {
    std::cout << "Char: " << c << std::endl;
  }
  return;
}

void ScalarConverter::doubleToChar(double d) {
  if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min()) {
    std::cout << "Char: impossible" << std::endl;
  }
  else {
    checkChar(static_cast<char>(d));
  }
  return;
}

void ScalarConverter::doubleToInt(double d) {
  if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()) {
    std::cout << "Int: impossible, out of range" << std::endl;
  }
  else {
    if (static_cast<int>(d) == d) {
      std::cout << "Int: " << static_cast<int>(d) << std::endl;
    }
    else {
      std::cout << "Int: " << static_cast<int>(d) << " (precision loss)" << std::endl;
    }
  }
  return;
}

void ScalarConverter::doubleToFloat(double d, int precision) {
  if (d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min()) {
    std::cout << "Float: impossible, out of range" << std::endl;
  }
  else {
    float f = static_cast<float>(d);
    if (static_cast<double>(f) == d) {
      std::cout << std::fixed << std::setprecision(precision) << "Float: " << f << "f" << std::endl;
    }
    else {
      std::cout << std::fixed << std::setprecision(precision) << "Float: " << f << "f (precision loss)" << std::endl;
    }
  }
  return;
}

void ScalarConverter::intToFloat(int i, int precision) {
  float f = static_cast<float>(i);
  if (static_cast<int>(f) != i) {
    std::cout << std::fixed << std::setprecision(precision) << "Float: " << f << "f (precision loss)" << std::endl;
  }
  else {
    std::cout << std::fixed << std::setprecision(precision) << "Float: " << f << "f" << std::endl;
  }
  return;
}

int ScalarConverter::checkPrecision(std::string str) {
  int count = 0;
  bool decimal = false;
  try {
    for (size_t i = 0; i < str.length(); i++) {
      if (!isdigit(str[i])) {
        if (((str[i] == '+' ||  str[i] == '-') && i != 0)) {
          throw std::runtime_error("+ or - in wrong place");
        }
        if ((str[i] == 'f'  || str[i] == 'F') && i != str.length() - 1) {
          throw std::runtime_error("f/F in wrong place");
        }
        if (str[i] == '.') {
          if (decimal) {
            throw std::runtime_error("multiple decimal points");
          } else {
            decimal = true;
          }
        }
      } else if (decimal) {
        count++;
      }
    }
    if (!decimal) {
      throw std::runtime_error("no decimal point");
    }
    return count;
  } catch (const std::runtime_error& error) {
    std::cout << "Format error float/double: " << error.what() << std::endl;
    return -1;
  }
}



