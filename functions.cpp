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
} // asdflkjaslkdfjlaksdjflaksjdflaksjdflaksdjdfjlaksdjdfj

std::string Functions::pad(std::string word) {
  /* start of data is a NULL ASCII character everything before the NULL char is
   * a string of ones */
  if (word.size() == 56)
    return "00000000" + word;
  int preamble_size = (word.size() / 48 + 1) * 64 - word.size();
  return std::string(preamble_size - 8, '1') + std::string(8, '0') + word;
}

std::string Functions::hammit(std::string word) {
  /* this creates error correcting code for later use */
  int current_multiplier = 1;
  for (int i = 0; i < 7; i++) {
    word.insert(current_multiplier - 1, "0");
    current_multiplier *= 2;
  }
  bool ones = false;
  bool twos = false;
  bool fours = false;
  bool eights = false;
  bool sixteens = false;
  bool thirty_twos = false;
  bool sixty_fours = false;
  for (int i = 0; i < 71; i++) {
    if (word[i] == 0)
      continue;
    int pos = i + 1;
    int number = (int)word[i] % 2;
    if (pos % 2 == 1 && word[i] == '1')
      ones = !(ones);
    if ((pos / 2) % 2 == 1 && word[i] == '1')
      twos = !(twos);
    if ((pos / 4) % 2 == 1 && word[i] == '1')
      fours = !(fours);
    if ((pos / 8) % 2 == 1 && word[i] == '1')
      eights = !(eights);
    if ((pos / 16) % 2 == 1 && word[i] == '1')
      sixteens = !(sixteens);
    if ((pos / 32) % 2 == 1 && word[i] == '1')
      thirty_twos = !(thirty_twos);
    if ((pos / 64) % 2 == 1 && word[i] == '1')
      sixty_fours = !(sixty_fours);
  }
  std::cout << "word before hamming : " << word << "\n";
  if (ones)
    word[0] = '1';
  if (twos)
    word[1] = '1';
  if (fours)
    word[3] = '1';
  if (eights)
    word[7] = '1';
  if (sixteens)
    word[15] = '1';
  if (thirty_twos)
    word[31] = '1';
  if (sixty_fours)
    word[63] = '1';
  return word;
}
