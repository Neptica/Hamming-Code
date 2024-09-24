/* this hamming code uses 32-bit data words */
#include "functions.hpp"
#include <iostream>
#include <string>

int main() {
  std::string word = Functions::input_string();
  std::string padded_word = Functions::pad(word);

  std::string codeword = "";
  for (int i = 0; i < padded_word.size(); i += 64) {
    std::string substring = padded_word.substr(i, 64);
    codeword += Functions::hammit(substring);
  }
  std::cout << "word after hamming  : " << codeword << "\n";
}
