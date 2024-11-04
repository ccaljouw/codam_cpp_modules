#include <string>

class ScalarConverter {
  public:

    static void convert(const std::string& str);

  private:
    // private methods to check if the string is a literal representation of a type
    static bool isCharacterLiteral(const std::string& str);
    static bool isIntLiteral(const std::string& str);
    static bool isFloatLiteral(const std::string& str);
    static bool isDoubleLiteral(const std::string& str);

    static int  checkPrecision(std::string str);
    
    static void checkChar(char c);
    static void intToFloat(int i, int precision);
    static void doubleToFloat(double d, int precision);
    static void doubleToChar(double d);
    static void doubleToInt(double d);  

    // private functions as the class is not meant to be instantiated
    ScalarConverter();
    ~ScalarConverter();
    ScalarConverter(ScalarConverter const& rhs);
    ScalarConverter& operator=(ScalarConverter const& rhs);
};
