//
// Created by mobin on 22/10/23.
//

#include "Gun.h"
#include "HeavyGun.h"
#include "Pistol.h"
#include <gtest/gtest.h>

TEST(Gun, Operator) {
  HeavyGun gun1("gun1", 23, 34, 45);
  HeavyGun gun2("gun3", 88, 90, 3);
  Pistol gun3("gun3", 88, 90, 3);
  Pistol gun4("gun3", 88, 90, 3);

  EXPECT_EQ(gun1 == gun2, false);
  EXPECT_EQ(gun3 == gun2, false);
  EXPECT_EQ(gun4 == gun3, true);
}