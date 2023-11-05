//
// Created by mobin on 22/10/23.
//

#include "Time.h"
#include <gtest/gtest.h>
#include <sstream>

TEST(Time, Operator) {
  Time time1(0, 0, 0);
  Time time2(0, 0, 1);
  Time time3(0, 1, 0);
  Time time4(1, 0, 1);
  Time time5(1, 1, 1);
  Time time6(1, 0, 1);

  EXPECT_EQ(time1 <= time2, true);
  EXPECT_EQ(time1 == time3, false);
  EXPECT_EQ(time6 == time4, true);
  EXPECT_EQ(time5 < time1, false);
  EXPECT_EQ(time4 <= time6, true);

  std::istringstream input("1:2:2");
  std::cin.rdbuf(input.rdbuf());

  std::cin >> time1;

  Time time(1, 2, 2);
  EXPECT_EQ(time1 == time, true);
}
