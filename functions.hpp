#ifndef functions_h
#define functions_h

#include <string>
class Functions {
public:
  static std::string input_string();
  static std::string pad(std::string word);
  static std::string hammit(std::string word);
  static std::string ecc_func(std::string word);
  static std::string bit_flip(std::string word);
};

#endif // !functions_h
