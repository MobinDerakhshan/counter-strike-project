//
// Created by mobin on 20/10/23.
//
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "Round.h"

class MockTeam : public Team {
public:
  MockTeam(std::string name, std::vector<Gun> authorizedGuns)
      : Team(name, authorizedGuns) {}
  MOCK_METHOD(void, add_player, (std::string name, Time time));
};

class MockPlayer : public Player {
public:
  MockPlayer(std::string name, std::string team_name, Time time)
      : Player(name, team_name, time) {}
  MOCK_METHOD(void, buy, (Gun & gun));
  MOCK_METHOD(void, attacked, (int damage));
  MOCK_METHOD(void, kill_by, (std::string gun_type));
};

TEST(Round, addUser) {
  Time time1(0, 0, 3);
  Time time2(1, 0, 0);
  std::vector<Gun> gun;
  ListOfTeam listOfTeam;
  listOfTeam.add_team("team", gun);
  listOfTeam.add_team("team2", gun);
  Round round(listOfTeam);

  MockTeam mockTeam("team", gun);
  listOfTeam.get_team("team") = mockTeam;
  EXPECT_CALL(mockTeam, add_player("name", time1)).Times(1);

  EXPECT_EQ(round.add_user("name", "team", time1) == "this user added to team",
            true);
  round.add_user("namee", "team2", time2);

  Player player("name", "team", time1);
  EXPECT_EQ(listOfTeam.get_player("name") == player, true);
  EXPECT_NE(listOfTeam.get_player("name") == Player::null, true);
  EXPECT_NE(listOfTeam.get_player("namee") == Player::null, true);

  EXPECT_EQ(listOfTeam.get_player("name").get_health(),
            Configuration::get_instance()->starting_health);
  EXPECT_EQ(listOfTeam.get_player("namee").get_health(),
            Configuration::get_instance()->minimum_health);

  EXPECT_EQ(round.add_user("name", "team2", time1),
            "you are already in this game");

  round.add_user("name2", "team", time1);
  round.add_user("name3", "team", time1);
  round.add_user("name4", "team", time1);
  round.add_user("name5", "team", time1);
  round.add_user("name6", "team", time1);
  round.add_user("name7", "team", time1);
  round.add_user("name8", "team", time1);
  round.add_user("name9", "team", time1);
  round.add_user("name10", "team", time1);
  EXPECT_EQ(round.add_user("name11", "team", time1), "this get_team is full");
}

TEST(Round, getMoney) {
  Time time1(0, 0, 3);
  std::vector<Gun> gun;
  ListOfTeam listOfTeam;
  listOfTeam.add_team("team", gun);
  Round round(listOfTeam);

  round.add_user("name", "team", time1);

  EXPECT_EQ(round.get_money("name2"), "invalid username");
  EXPECT_EQ(round.get_money("name"),
            to_string(listOfTeam.get_player("name").get_money()));
}

TEST(Round, getHealth) {
  std::vector<Gun> gun;
  ListOfTeam listOfTeam;
  listOfTeam.add_team("team", gun);
  Round round(listOfTeam);

  Time time1(0, 0, 3);
  round.add_user("name", "team", time1);

  EXPECT_EQ(round.get_health("name2"), "invalid username");
  EXPECT_EQ(round.get_health("name"),
            to_string(listOfTeam.get_player("name").get_health()));
}

TEST(Round, buy) {
  Time time1(0, 0, 3);
  Time time2(3, 5, 9);
  HeavyGun gun1("gun1", 5, 3, 2);
  Pistol gun2("gun2", 54, 66, 22);
  HeavyGun gun3("gun3", 34, 23, 66);
  std::vector<Gun> gun = {gun1, gun2, gun3};
  ListOfTeam listOfTeam;
  listOfTeam.add_team("team", gun);
  Round round(listOfTeam);

  round.add_user("name", "team", time1);
  EXPECT_EQ(listOfTeam.get_player("name").get_gun("heavy") == Gun::null, true);

  EXPECT_EQ(round.buy("name4", "gun1", time1), "invalid username");

  listOfTeam.get_player("name").set_health(0);
  EXPECT_EQ(round.buy("name", "gun2", time1), "deads can not buy");

  listOfTeam.get_player("name").set_health(44);
  EXPECT_EQ(round.buy("name", "gun2", time2), "you are out of time");
  EXPECT_EQ(listOfTeam.get_player("name").get_gun("pistol") == Gun::null, true);

  EXPECT_EQ(round.buy("name", "gun4", time1), "invalid category gun");

  round.add_user("name3", "team", time1);
  MockPlayer mockPlayer("name3", "team", time1);
  listOfTeam.get_player("name3") = mockPlayer;
  EXPECT_CALL(mockPlayer, buy(gun1)).Times(1);
  EXPECT_EQ(round.buy("name3", "gun1", time1), "I hope you can use it");
  EXPECT_EQ(listOfTeam.get_player("name3").get_gun("heavy") == gun1, true);

  EXPECT_EQ(round.buy("name3", "gun3", time1), "you have a heavy");

  listOfTeam.get_player("name").set_money(1);
  EXPECT_EQ(round.buy("name", "gun2", time1), "no enough a money");
}

TEST(Round, tap) {
  HeavyGun gun1("gun1", 5, 300, 2);
  Pistol gun2("gun2", 54, 66, 22);
  HeavyGun gun3("gun3", 34, 23, 66);
  std::vector<Gun> gun = {gun1, gun2, gun3};
  ListOfTeam listOfTeam;
  listOfTeam.add_team("team", gun);
  listOfTeam.add_team("team2", gun);
  Round round(listOfTeam);

  Time time1(0, 0, 3);
  Time time2(0, 0, 5);
  round.add_user("name", "team", time1);
  round.add_user("name2", "team2", time2);
  round.add_user("name3", "team", time1);

  EXPECT_EQ(round.tap("nameeee", "name", "heavy"), "invalid username");
  EXPECT_EQ(round.tap("name", "nameeee", "heavy"), "invalid username");
  EXPECT_EQ(round.tap("nameeee", "nameeee", "heavy"), "invalid username");

  listOfTeam.get_player("name").set_health(0);
  listOfTeam.get_player("name2").set_health(0);
  EXPECT_EQ(round.tap("name", "name2", "heavy"), "attacker is dead");

  listOfTeam.get_player("name").set_health(33);
  EXPECT_EQ(round.tap("name", "name2", "heavy"), "attacked is dead");

  listOfTeam.get_player("name2").set_health(55);
  EXPECT_EQ(round.tap("name", "name2", "heavy"), "no such gun");

  round.buy("name", "gun1", time1);
  EXPECT_EQ(round.tap("name", "name3", "heavy"), "friendly fire");

  MockPlayer mockAttacker("name", "team", time1);
  MockPlayer mockAttacked("name2", "team2", time2);
  listOfTeam.get_player("name") = mockAttacker;
  listOfTeam.get_player("name2") = mockAttacked;
  round.buy("name", "gun1", time1);
  EXPECT_CALL(mockAttacker, kill_by(gun1.get_type())).Times(1);
  EXPECT_CALL(mockAttacked, attacked(gun1.damage)).Times(1);
  EXPECT_EQ(round.tap("name", "name2", "heavy"), "nice shot");
}

TEST(Round, scoreBoard) {
  std::vector<Gun> gun;
  ListOfTeam listOfTeam;
  listOfTeam.add_team("team", gun);
  listOfTeam.add_team("team2", gun);
  Round round(listOfTeam);

  Time time1(0, 0, 3);
  Time time2(0, 0, 5);
  round.add_user("name", "team", time1);
  round.add_user("name2", "team", time2);
  round.add_user("name3", "team2", time1);
  round.add_user("name4", "team2", time2);

  listOfTeam.get_player("name2").set_kill(2);
  listOfTeam.get_player("name3").set_death(2);

  std::string s = "team-Players:\n1 name2 2 0\n2 name 0 0\nteam2-Players:\n1 "
                  "name4 0 0\n2 name3 0 2";
  EXPECT_EQ(round.score_board(), s);
}
