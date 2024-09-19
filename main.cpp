/* this hamming code uses 32-bit data words */
#include "functions.hpp"
#include <iostream>
#include <string>

int main() {
  std::string word = Functions::input_string();
  std::string padded_word = Functions::pad(word);

  std::string codeword = "";
  int i;
  for (i = 0; i < padded_word.size(); i += 56) {
    std::string substring = padded_word.substr(i, 56);
    // std::cout << " this is the substr : " << substring
    //           << " and this is its size " << substring.size();
    codeword += Functions::hammit(substring);
  }
  // for (int i = 0; i < codeword.size(); i++) {
  //   std::cout << (i + 1) % 64 << ": " << codeword[i] << "\n";
  // }
  // if (i + 56 < bit_count) {
  //   codeword += Functions::hammit(word.substr(i, bit_count - 1));
  // }
  // std::cout << codeword.size() << "\n";
}
