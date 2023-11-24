//
// Created by mobin on 22/10/23.
//

#include <gtest/gtest.h>
#include "Weapon.h"

TEST(Gun, Operator) {
  Weapon gun1("gun1", heavy, 23, 34, 45);
  Weapon gun2("gun3", heavy, 88, 90, 3);
  Weapon gun3("gun3", pistol, 88, 90, 3);
  Weapon gun4("gun3", pistol, 88, 90, 3);

  EXPECT_EQ(gun1 == gun2, false);
  EXPECT_EQ(gun3 == gun2, false);
  EXPECT_EQ(gun4 == gun3, true);
}