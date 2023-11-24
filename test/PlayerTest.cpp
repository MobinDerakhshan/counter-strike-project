//
// Created by mobin on 15/10/23.
//

#include <gtest/gtest.h>
#include "Player.h"
#include "Configuration.h"

TEST(Player, basics) {
  Time t1(0, 0, 0);
  Time t2(0, 3, 1);
  Player p1("name1", "team1", 0, t1);
  Player p2("name2", "team2", 1, t2);
  std::shared_ptr<Weapon> gun = std::make_shared<Weapon>("gun", heavy, 5, 6, 7);
  int i = 20358;

  EXPECT_EQ(p1.get_name(), "name1");
  EXPECT_EQ(p1.get_team_name(), "team1");
  EXPECT_EQ(p1.get_kill(), Configuration::get_instance()->starting_kill);
  EXPECT_EQ(p1.get_death(), Configuration::get_instance()->starting_death);
  EXPECT_EQ(p1.get_win_number(), Configuration::get_instance()->starting_win_number);
  EXPECT_EQ(p1.get_lose_number(), Configuration::get_instance()->starting_lose_number);
  EXPECT_EQ(p1.get_money(), Configuration::get_instance()->starting_money);
  EXPECT_EQ(p1.get_health(), Configuration::get_instance()->starting_health);
  EXPECT_EQ(p2.get_health(), Configuration::get_instance()->minimum_health);

  p1.set_health(44);
  EXPECT_EQ(p1.get_health(), 44);
  p1.set_health(10000);
  EXPECT_EQ(p1.get_health(), Configuration::get_instance()->starting_health);
  p1.set_health(-346);
  EXPECT_EQ(p1.get_health(), Configuration::get_instance()->minimum_health);
  p1.reset_health();
  EXPECT_EQ(p1.get_health(), Configuration::get_instance()->starting_health);

  p1.set_money(2222);
  EXPECT_EQ(p1.get_money(), 2222);
  p1.set_money(444444);
  EXPECT_EQ(p1.get_money(), Configuration::get_instance()->max_money);
  p1.set_money(-33);
  EXPECT_EQ(p1.get_money(), Configuration::get_instance()->minimum_money);

  int kill_number = p1.get_kill();
  p1.increment_kill();
  EXPECT_EQ(p1.get_kill(), kill_number + 1);

  p1.set_death(i);
  EXPECT_EQ(p1.get_death(), i);

  p1.set_win_number(i);
  EXPECT_EQ(p1.get_win_number(), i);

  p1.set_lose_number(i);
  EXPECT_EQ(p1.get_lose_number(), i);

  p1.set_number_in_team(i);
  EXPECT_EQ(p1.get_number_in_team(), i);

  p1.add_gun(gun);
  EXPECT_TRUE(p1.get_gun(gun->get_type()) == gun);
}

TEST(Player, buy) {
  Time t1(0, 0, 0);
  Player p1("name", "team", 0, t1);

  EXPECT_FALSE(p1.get_gun(pistol));

  std::shared_ptr<Weapon> g1 = std::make_shared<Weapon>("gun", heavy, 4, 5, 6);
  int money = p1.get_money();
  p1.buy(g1);
  int chang = money - p1.get_money();
  EXPECT_EQ(chang, g1->price);
  EXPECT_TRUE(p1.get_gun(heavy) == g1);

  std::shared_ptr<Weapon> g2 = std::make_shared<Weapon>("gun", pistol, 8, 0, 6666);

  money = p1.get_money();
  p1.buy(g2);
  chang = money - p1.get_money();
  EXPECT_EQ(chang, g2->price);
  EXPECT_TRUE(p1.get_gun(pistol) == g2);
}

TEST(Player, kill) {
  Time t1(0, 0, 0);
  Player p1("name", "team", 0, t1);
  std::shared_ptr<Weapon> g1 = std::make_shared<Weapon>("gun", heavy, 64, 33, 7);

  p1.add_gun(g1);
  int money = p1.get_money();
  int kill = p1.get_kill();
  p1.kill_by(g1->get_type());
  EXPECT_EQ(p1.get_kill(), kill + 1);
  EXPECT_EQ(p1.get_money(), money + g1->kill_reward);
}

TEST(Player, attacked) {
  Time t1(0, 0, 0);
  Player p1("name", "team", 0, t1);
  int health = p1.get_health();
  p1.attacked(7);
  EXPECT_EQ(p1.get_health(), health - 7);
  EXPECT_EQ(p1.get_win_number(), 0);
  EXPECT_EQ(p1.get_lose_number(), 0);

  p1.reset_health();
  EXPECT_EQ(p1.get_health(), Configuration::get_instance()->starting_health);

  std::shared_ptr<Weapon> g1 = std::make_shared<Weapon>("gun", heavy, 33, 44, 55);

  p1.add_gun(g1);
  p1.attacked(p1.get_health() + 10);
  EXPECT_EQ(p1.get_health(), Configuration::get_instance()->minimum_health);
  EXPECT_EQ(p1.get_win_number(),
            Configuration::get_instance()->starting_win_number);
  EXPECT_EQ(p1.get_lose_number(),
            Configuration::get_instance()->starting_lose_number);
  EXPECT_EQ(p1.get_death(), Configuration::get_instance()->starting_death + 1);
  EXPECT_FALSE(p1.is_full(g1->get_type()));
}

TEST(Player, winOrLose) {
  Time t1(0, 0, 0);
  Player p1("name", "team", 0, t1);
  int money = p1.get_money();
  int win_number = p1.get_win_number();
  p1.win();
  EXPECT_EQ(p1.get_win_number(), win_number + 1);
  EXPECT_EQ(p1.get_money(),
            money + Configuration::get_instance()->winners_price);

  money = p1.get_money();
  int lose_number = p1.get_lose_number();
  p1.lose();
  EXPECT_EQ(p1.get_lose_number(), lose_number + 1);
  EXPECT_EQ(p1.get_money(),
            money + Configuration::get_instance()->losers_price);
}

TEST(Player, Operator) {
  Time t1(0, 0, 0);
  Time t2(0, 0, 1);
  Player p1("name", "team", 0, t1);
  Player p2("name", "team4", 0, t2);
  Player p3("name2", "team", 1, t1);

  EXPECT_EQ(p1 == p2, true);
  EXPECT_EQ(p1 == p3, false);
  EXPECT_EQ(p1 != p2, false);
  EXPECT_EQ(p1 != p3, true);
}

TEST(Player, compare) {
  Time t1(0, 0, 0);
  Player p1("name", "team", 1, t1);
  Player p2("name2", "team", 2, t1);
  Player p3("name3", "team", 3, t1);
  Player p4("name4", "team", 4, t1);
  Player p5("name5", "team", 0, t1);

  p1.increment_kill();
  p1.set_death(1);
  p1.set_number_in_team(1);
  p2.increment_kill(); p2.increment_kill();
  p2.set_death(4);
  p2.set_number_in_team(2);
  p3.increment_kill();
  p3.set_death(2);
  p3.set_number_in_team(3);
  p4.increment_kill();
  p4.set_death(1);
  p4.set_number_in_team(4);
  p5.increment_kill(); p5.increment_kill();
  p5.set_death(1);
  p5.set_number_in_team(0);

  EXPECT_FALSE(Player::compare(p1, p2));
  EXPECT_TRUE(Player::compare(p1, p3));
  EXPECT_TRUE(Player::compare(p1, p4));
  EXPECT_FALSE(Player::compare(p1, p5));
  EXPECT_FALSE(Player::compare(p2, p5));
}
