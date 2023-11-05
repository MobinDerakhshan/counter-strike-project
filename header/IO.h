//
// Created by mobin on 18/09/23.
//

#ifndef P_INPUT_H
#define P_INPUT_H
#include "Time.h"
#include <cstdarg>
#include <iostream>

using namespace std;

class IO {
public:
  static int get_number_of_commands();
  static std::string get_command_type();
  template <typename T> static void get_command_data(T &t) { std::cin >> t; }
  template <typename T, typename... Args>
  static void get_command_data(T &t, Args &... args) {

    std::cin >> t;

    get_command_data(args...);
  }
  static void command_output(std::string s);
  static void print_winner(std::string winner);

  static int get_number_of_rounds();
};

#endif // P_INPUT_H
