//
// Created by mobin on 18/09/23.
//

#include "IO.h"

int IO::get_number_of_commands() {
  std::string s;
  int r;
  std::cin >> s >> r;
  return r;
}

std::string IO::get_command_type() {
  std::string s;
  std::cin >> s;
  return s;
}

void IO::command_output(std::string s) { std::cout << s << "\n"; }

void IO::print_winner(Team winner) { std::cout << winner.get_name() << " won\n"; }

int IO::get_number_of_rounds() {
  int r;
  std::cin >> r;
  return r;
}
