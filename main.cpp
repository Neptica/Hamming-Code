/* this hamming code uses 32-bit data words */
#include "functions.hpp"
#include <iostream>
#include <string>

int main() {
  std::string word = Functions::input_string();
  std::cout << word << "\n";

  int bit_count =
      word.size(); // 56 bits, plus 6 hamming, one parity and one extra bit

  // TODO: have to move the preamble after the hamming code
  // preamble/pad are ones followed by a NULL byte
  std::string padded_word = Functions::pad(word);
  std::cout << padded_word << " with a size of : " << padded_word.size()
            << "\n";

  std::cout << bit_count << "\n";
  std::string codeword = "";
  int i;
  for (i = 0; i < bit_count; i += 56) {
    std::cout << " this is i : " << i << "\n";
    codeword += Functions::hammit(word.substr(i, i + 56));
  }
  if (i + 56 < bit_count) {
    codeword += Functions::hammit(word.substr(i, bit_count - 1));
  }
  std::cout << codeword << "\n";
}
