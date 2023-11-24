//
// Created by mobin on 21/10/23.
//

#include <gtest/gtest.h>
#include "Ammunition.h"

TEST(Ammunition, basics) {
  Ammunition ammunition;
  std::shared_ptr gun1 = std::make_shared<Weapon>("gun1", heavy, 5, 8, 333);
  std::shared_ptr gun2 = std::make_shared<Weapon>("gun2", pistol, 6, 3, 111);
  EXPECT_FALSE(ammunition.is_full(heavy));
  ammunition.add_gun(gun1);
  EXPECT_TRUE(ammunition.get_gun(gun1->get_type()) == gun1);
  EXPECT_TRUE(ammunition.is_full(heavy));

  EXPECT_FALSE(ammunition.is_full(pistol));
  ammunition.add_gun(gun2);
  EXPECT_EQ(ammunition.get_gun(gun2->get_type()) == gun2, true);
  EXPECT_TRUE(ammunition.is_full(pistol));
}

TEST(Ammunition, clear) {
  Ammunition ammunition;
  std::shared_ptr<Weapon> gun1 = std::make_shared<Weapon>("gun1", heavy, 5, 8, 333);
  std::shared_ptr<Weapon> gun2 = std::make_shared<Weapon>("gun2", pistol, 6, 3, 111);

  ammunition.add_gun(gun1);
  ammunition.add_gun(gun2);
  ammunition.clear();
  EXPECT_FALSE(ammunition.get_gun(gun1->get_type()));
  EXPECT_FALSE(ammunition.get_gun(gun2->get_type()));
}
