//
// Created by mobin on 18/09/23.
//

#include "../header/IO.h"

int IO::get_number_of_commands() {
  std::string s;
  int r;
  std::cin >> s >> r;
  if (s != "ROUND") {
    // throw()
  }
  return r;
}

std::string IO::get_command_type() {
  std::string s;
  std::cin >> s;
  return s;
}

void IO::command_output(std::string s) { std::cout << s << "\n"; }

void IO::print_winner(std::string winner) { std::cout << winner << " won\n"; }

int IO::get_number_of_rounds() {
  int r;
  std::cin >> r;
  return r;
}
