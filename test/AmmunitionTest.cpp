//
// Created by mobin on 21/10/23.
//

#include <gtest/gtest.h>
#include "Ammunition.h"

TEST(Ammunition, basics) {
  Ammunition ammunition;
  HeavyGun gun1("gun1", 5, 8, 333);
  Pistol gun2("gun2", 6, 3, 111);
  EXPECT_EQ(ammunition.get_pistol_number(), 0);
  EXPECT_EQ(ammunition.get_heavy_gun_number(), 0);
  ammunition.add_gun(gun1);
  ammunition.add_gun(gun2);
  EXPECT_EQ(ammunition.get_gun(gun1.get_type()) == gun1, true);
  EXPECT_EQ(ammunition.get_gun(gun2.get_type()) == gun2, true);

  EXPECT_EQ(ammunition.get_heavy_gun_number(), 1);
  EXPECT_EQ(ammunition.get_pistol_number(), 1);
}

TEST(Ammunition, isfull) {
  Ammunition ammunition;
  HeavyGun gun1("gun1", 5, 8, 333);
  Pistol gun2("gun2", 6, 3, 111);
  EXPECT_EQ(ammunition.is_full("heavy"), false);
  EXPECT_EQ(ammunition.is_full("pistol"), false);
  ammunition.add_gun(gun1);
  ammunition.add_gun(gun2);
  EXPECT_EQ(ammunition.is_full("heavy"), true);
  EXPECT_EQ(ammunition.is_full("pistol"), true);
}

TEST(Ammunition, clear) {
  Ammunition ammunition;
  HeavyGun gun1("gun1", 5, 8, 333);
  Pistol gun2("gun2", 6, 3, 111);
  ammunition.add_gun(gun1);
  ammunition.add_gun(gun2);
  ammunition.clear();
  EXPECT_EQ(ammunition.get_gun(gun1.get_type()) == Gun::null, true);
  EXPECT_EQ(ammunition.get_gun(gun2.get_type()) == Gun::null, true);
}
