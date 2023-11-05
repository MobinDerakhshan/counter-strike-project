//
// Created by mobin on 20/10/23.
//

#include "../header/Team.h"
#include <gtest/gtest.h>

TEST(Team, basics) {
  Time t(0, 0, 33);
  HeavyGun g1("gun", 9, 8, 3);
  Pistol g2("gun2", 5, 3, 8);
  Pistol g3("gun3", 8, 2, 11);
  std::vector<Gun> gun = {g1, g2, g3};

  Team t1("team", gun);

  EXPECT_EQ(t1.get_name(), "team");
  EXPECT_EQ(t1.get_number_of_players(), 0);
  EXPECT_EQ(t1.get_gun("gun") == g1, true);
  EXPECT_EQ(t1.get_gun("gun2") == g2, true);
  EXPECT_EQ(t1.get_gun("gun3") == g3, true);

  Player p1("name", "team", t);
  Player p2("name2", "team", t);
  t1.add_player("name", t);
  t1.add_player("name2", t);

  EXPECT_EQ(t1.get_player("name") == p1, true);
  EXPECT_EQ(t1.get_player("name2") == p2, true);
}

// deq
TEST(Team, winOrLose) {
  Time t(0, 0, 33);
  std::vector<Gun> gun;

  Team t1("team", gun);

  t1.add_player("name", t);
  t1.add_player("name2", t);
  Player &p1 = t1.get_player("name");
  Player &p2 = t1.get_player("name2");

  int money = p1.get_money();
  t1.win();

  EXPECT_EQ(p1.get_win_number(), 1);
  EXPECT_EQ(p2.get_win_number(), 1);
  EXPECT_EQ(p1.get_money(),
            money + Configuration::get_instance()->winners_price);

  money = p1.get_money();
  t1.lose();

  EXPECT_EQ(p1.get_lose_number(), 1);
  EXPECT_EQ(p2.get_lose_number(), 1);
  EXPECT_EQ(p1.get_money(),
            money + Configuration::get_instance()->losers_price);
}

TEST(Team, restart) {
  Time t(0, 0, 33);
  std::vector<Gun> gun;

  Team t1("team", gun);

  t1.add_player("name", t);
  t1.add_player("name2", t);

    t1.get_player("name").attacked(55);
    t1.get_player("name2").attacked(61);

  t1.restart();

  EXPECT_EQ(t1.get_player("name").get_health(),
            Configuration::get_instance()->starting_health);
  EXPECT_EQ(t1.get_player("name2").get_health(),
            Configuration::get_instance()->starting_health);
}

TEST(Team, sortPlayer) {
  Time t(0, 0, 33);
  std::vector<Gun> gun;

  Team t1("team", gun);

  t1.add_player("name", t);
  t1.add_player("name3", t);
  t1.add_player("name4", t);
  t1.add_player("name5", t);
  t1.add_player("name2", t);
  Player p1 = t1.get_player("name");
  Player p2 = t1.get_player("name2");
  Player p3 = t1.get_player("name3");
  Player p4 = t1.get_player("name4");
  Player p5 = t1.get_player("name5");
  t1.get_player("name").set_kill(2);
  t1.get_player("name").set_death(3);
  t1.get_player("name2").set_kill(2);
  t1.get_player("name2").set_death(3);
  t1.get_player("name3").set_kill(3);
  t1.get_player("name3").set_death(7);
  t1.get_player("name4").set_kill(2);
  t1.get_player("name4").set_death(5);
  t1.get_player("name5").set_kill(7);
  t1.get_player("name5").set_death(0);

  t1.sort_player();

  EXPECT_EQ(t1.get_player(0) == p5, true);
  EXPECT_EQ(t1.get_player(1) == p3, true);
  EXPECT_EQ(t1.get_player(2) == p1, true);
  EXPECT_EQ(t1.get_player(3) == p2, true);
  EXPECT_EQ(t1.get_player(4) == p4, true);
}

TEST(Team, all_die_and_is_full) {
  Time t(0, 0, 33);
  std::vector<Gun> gun;

  Team t1("team", gun);

  t1.add_player("name", t);
  t1.add_player("name2", t);
  EXPECT_EQ(t1.all_die(), false);

  t1.get_player("name").set_health(0);
  EXPECT_EQ(t1.all_die(), false);

  t1.get_player("name2").set_health(0);
  EXPECT_EQ(t1.all_die(), true);

  t1.add_player("name3", t);
  t1.add_player("name4", t);
  t1.add_player("name5", t);
  t1.add_player("name6", t);
  t1.add_player("name7", t);
  t1.add_player("name8", t);
  t1.add_player("name9", t);

  EXPECT_EQ(t1.is_full(), false);

  t1.add_player("name10", t);

  EXPECT_EQ(t1.is_full(), true);
}
