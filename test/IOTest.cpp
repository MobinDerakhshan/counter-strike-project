//
// Created by mobin on 21/10/23.
//
#include "IO.h"
#include <gtest/gtest.h>
#include <sstream>

TEST(IO, get_command_number) {
  std::istringstream input("ROUND 42");
  std::cin.rdbuf(input.rdbuf());

  EXPECT_EQ(IO::get_number_of_commands(), 42);
}

TEST(IO, get_number_of_rounds) {
  std::istringstream input("42");
  std::cin.rdbuf(input.rdbuf());

  EXPECT_EQ(IO::get_number_of_rounds(), 42);
}

TEST(IO, get_command_type) {
  std::istringstream input("kshhfkjblskdl");
  std::cin.rdbuf(input.rdbuf());

  std::string s;
  IO::get_command_data(s);

  EXPECT_EQ(s, "kshhfkjblskdl");
}

TEST(IO, print_winner) {
  std::ostringstream outputStream;
  std::streambuf *originalCout = std::cout.rdbuf();
  std::cout.rdbuf(outputStream.rdbuf());

  IO::print_winner("team");

  std::string output = outputStream.str();
  std::string expectedOutput = "team won\n";
  EXPECT_EQ(output, expectedOutput);
}

TEST(IO, command_output) {
  std::ostringstream outputStream;
  std::streambuf *originalCout = std::cout.rdbuf();
  std::cout.rdbuf(outputStream.rdbuf());

  IO::print_winner("kjashhdfjalkshfj");

  std::string output = outputStream.str();
  std::string expectedOutput = "kjashhdfjalkshfj won\n";
  EXPECT_EQ(output, expectedOutput);
}

TEST(IO, get_command_data_int) {
  std::istringstream input("144");
  std::cin.rdbuf(input.rdbuf());

  int x;
  IO::get_command_data(x);

  EXPECT_EQ(x, 144);
}

TEST(IO, get_command_data_time) {
  std::istringstream input("1:2:2");
  std::cin.rdbuf(input.rdbuf());

  Time time1(0, 0, 0);
  IO::get_command_data(time1);

  Time time2(1, 2, 2);
  EXPECT_EQ(time1, time2);
}

TEST(IO, get_command_data_string) {
  std::istringstream input("42 Hello World 3.14");
  std::cin.rdbuf(input.rdbuf());

  std::string strValue;

  IO::get_command_data(strValue);

  EXPECT_EQ(strValue, "Hello");
}

TEST(IO, get_command_data_multiple_arguments) {

  std::istringstream input("42 Hello World 3.14");
  std::cin.rdbuf(input.rdbuf());

  int intValue;
  std::string strValue;
  double doubleValue;

  IO::get_command_data(intValue, strValue, doubleValue);

  EXPECT_EQ(intValue, 42);
  EXPECT_EQ(strValue, "Hello");
  EXPECT_EQ(doubleValue, 3.14);

  std::istringstream input2("42 3.14 Hello 0:0:999");
  std::cin.rdbuf(input.rdbuf());

  int intValue2;
  double doubleValue2;
  std::string strValue2;
  Time time1(0, 0, 0);
  Time time2(0, 0, 999);

  IO::get_command_data(intValue, doubleValue, strValue, time1);

  EXPECT_EQ(intValue, 42);
  EXPECT_EQ(doubleValue, 3.14);
  EXPECT_EQ(strValue, "Hello");
  EXPECT_EQ(time1, time1);
}
