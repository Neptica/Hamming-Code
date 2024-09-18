#include "functions.hpp"

#include <bitset>
#include <cmath>
#include <iostream>
#include <string>

std::string Functions::input_string() {
  std::cout << "input string to encode: ";
  std::string input;
  getline(std::cin, input);
  std::string word = "";
  for (int i = 0; i < input.size(); i++) {
    word += std::bitset<8>(input[i]).to_string();
  }
  return word;
}

std::string Functions::pad(std::string word) {
  /* start of data is a NULL ASCII character */
  if (word.size() % 56 == 0)
    return "00000000" + word;
  int preamble_size = (word.size() / 56 + 1) * 56 - word.size();
  return std::string(preamble_size - 8, '1') + std::string(8, '0') + word;
}

std::string Functions::hammit(std::string word) {
  /* this creates error correcting code for later use */
  int current_multiplier = 1;
  for (int i = 0; i < 6; i++) {
    int checking = current_multiplier;
    std::cout << checking << "\n";
    current_multiplier *= 2;
  }
  return "5";
}
