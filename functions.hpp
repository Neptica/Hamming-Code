#ifndef functions_h
#define functions_h

#include <string>
class Functions {
public:
  static std::string input_string();
  static std::string pad(std::string word);
  static std::string hammit(std::string word);
};

#endif // !functions_h