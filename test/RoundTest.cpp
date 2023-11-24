//
// Created by mobin on 20/10/23.
//
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "Round.h"

class MockTeam : public Team {
public:
  MockTeam(std::string name, std::vector<Weapon> authorizedGuns)
      : Team(name, authorizedGuns) {}
  MOCK_METHOD(void, add_player, (std::string name, Time time));
};

class MockPlayer : public Player {
public:
  MockPlayer(std::string name, std::string team_name, int number_in_team, Time time)
      : Player(name, team_name, number_in_team, time) {}
  MOCK_METHOD(void, buy, (std::shared_ptr<Weapon> gun));
  MOCK_METHOD(void, attacked, (int damage));
  MOCK_METHOD(void, kill_by, (gun_type gun_type));
};

TEST(Round, addUser) {
  std::istringstream input("ROUND 42");
  std::cin.rdbuf(input.rdbuf());
  Time time1(0, 0, 3);
  Time time2(1, 0, 0);
  std::vector<Weapon> gun;
  ListOfTeam listOfTeam;
  MockTeam mockTeam("team", gun);
  Team team2("team2", gun);
  listOfTeam.add_team(mockTeam);
  listOfTeam.add_team(team2);
  Round round(listOfTeam);

  EXPECT_CALL(mockTeam, add_player("name", time1)).Times(1);
  EXPECT_EQ(round.add_user_command("name", "team", time1) == "this user added to team",
            true);

  round.add_user_command("namee", "team2", time2);

  Player player("name", "team", 0, time1);
  EXPECT_TRUE(listOfTeam.get_player("name").get() == player);
  EXPECT_TRUE(listOfTeam.player_exist("name"));
  EXPECT_TRUE(listOfTeam.player_exist("namee"));

  EXPECT_EQ(listOfTeam.get_player("name").get().get_health(),
            Configuration::get_instance()->starting_health);
  EXPECT_EQ(listOfTeam.get_player("namee").get().get_health(),
            Configuration::get_instance()->minimum_health);

  EXPECT_EQ(round.add_user_command("name", "team2", time1),
            "you are already in this game");

    round.add_user_command("name2", "team", time1);
    round.add_user_command("name3", "team", time1);
    round.add_user_command("name4", "team", time1);
    round.add_user_command("name5", "team", time1);
    round.add_user_command("name6", "team", time1);
    round.add_user_command("name7", "team", time1);
    round.add_user_command("name8", "team", time1);
    round.add_user_command("name9", "team", time1);
    round.add_user_command("name10", "team", time1);
  EXPECT_EQ(round.add_user_command("name11", "team", time1), "this team is full");
}

TEST(Round, getMoney) {
  std::istringstream input("ROUND 42");
  std::cin.rdbuf(input.rdbuf());
  Time time1(0, 0, 3);
  std::vector<Weapon> gun;
  ListOfTeam listOfTeam;
  Team team("team", gun);
  listOfTeam.add_team(team);
  Round round(listOfTeam);

    round.add_user_command("name", "team", time1);

  EXPECT_EQ(round.get_money_command("name2"), "invalid username");
  EXPECT_EQ(round.get_money_command("name"),
            to_string(listOfTeam.get_player("name").get().get_money()));
}

TEST(Round, getHealth) {
  std::istringstream input("ROUND 42");
  std::cin.rdbuf(input.rdbuf());
  std::vector<Weapon> gun;
  ListOfTeam listOfTeam;
  Team team("team", gun);
  listOfTeam.add_team(team);
  Round round(listOfTeam);

  Time time1(0, 0, 3);
    round.add_user_command("name", "team", time1);

  EXPECT_EQ(round.get_health_command("name2"), "invalid username");
  EXPECT_EQ(round.get_health_command("name"),
            to_string(listOfTeam.get_player("name").get().get_health()));
}

TEST(Round, buy) {
  std::istringstream input("ROUND 42");
  std::cin.rdbuf(input.rdbuf());
  Time time1(0, 0, 3);
  Time time2(3, 5, 9);
  std::shared_ptr<Weapon> gun1 = std::make_shared<Weapon>("gun1", heavy, 5, 3, 2);
  std::shared_ptr<Weapon> gun2 = std::make_shared<Weapon>("gun2", pistol, 54, 66, 22);
  std::shared_ptr<Weapon> gun3 = std::make_shared<Weapon>("gun3", heavy, 34, 23, 66);
  std::vector<Weapon> gun = {*gun1, *gun2, *gun3};
  ListOfTeam listOfTeam;
  Team team("team", gun);
  listOfTeam.add_team(team);
  Round round(listOfTeam);

  round.add_user_command("name", "team", time1);
  EXPECT_FALSE(listOfTeam.get_player("name").get().get_gun(heavy));

  EXPECT_EQ(round.buy_command("name4", "gun1", time1), "invalid username");

  listOfTeam.get_player("name").get().set_health(0);
  EXPECT_EQ(round.buy_command("name", "gun2", time1), "deads can not buy");

  listOfTeam.get_player("name").get().set_health(44);
  EXPECT_EQ(round.buy_command("name", "gun2", time2), "you are out of time");
  EXPECT_FALSE(listOfTeam.get_player("name").get().get_gun(pistol));

  EXPECT_EQ(round.buy_command("name", "gun4", time1), "invalid category gun");

    round.add_user_command("name3", "team", time1);
  MockPlayer mockPlayer("name3", "team", 0, time1);
  listOfTeam.get_player("name3") = mockPlayer;
  EXPECT_CALL(mockPlayer, buy(gun1)).Times(1);
  EXPECT_EQ(round.buy_command("name3", "gun1", time1), "I hope you can use it");
  EXPECT_EQ(listOfTeam.get_player("name3").get().get_gun(heavy) == gun1, true);

  EXPECT_EQ(round.buy_command("name3", "gun3", time1), "you have a heavy");

  listOfTeam.get_player("name").get().set_money(1);
  EXPECT_EQ(round.buy_command("name", "gun2", time1), "no enough a money");
}

TEST(Round, tap) {
  std::istringstream input("ROUND 42");
  std::cin.rdbuf(input.rdbuf());
  Weapon gun1("gun1", heavy, 5, 300, 2);
  Weapon gun2("gun2", pistol, 54, 66, 22);
  Weapon gun3("gun3", heavy, 34, 23, 66);
  std::vector<Weapon> gun = {gun1, gun2, gun3};
  ListOfTeam listOfTeam;
  Team team("team", gun);
  Team team2("team2", gun);
  listOfTeam.add_team(team);
  listOfTeam.add_team(team2);
  Round round(listOfTeam);

  Time time1(0, 0, 3);
  Time time2(0, 0, 5);
    round.add_user_command("name", "team", time1);
    round.add_user_command("name2", "team2", time2);
    round.add_user_command("name3", "team", time1);

  EXPECT_EQ(round.tap_command("nameeee", "name", "heavy"), "invalid username");
  EXPECT_EQ(round.tap_command("name", "nameeee", "heavy"), "invalid username");
  EXPECT_EQ(round.tap_command("nameeee", "nameeee", "heavy"), "invalid username");

  listOfTeam.get_player("name").get().set_health(0);
  listOfTeam.get_player("name2").get().set_health(0);
  EXPECT_EQ(round.tap_command("name", "name2", "heavy"), "attacker is dead");

  listOfTeam.get_player("name").get().set_health(33);
  EXPECT_EQ(round.tap_command("name", "name2", "heavy"), "attacked is dead");

  listOfTeam.get_player("name2").get().set_health(55);
  EXPECT_EQ(round.tap_command("name", "name2", "heavy"), "no such gun");

    round.buy_command("name", "gun1", time1);
  EXPECT_EQ(round.tap_command("name", "name3", "heavy"), "friendly fire");

  MockPlayer mockAttacker("name", "team", 0, time1);
  MockPlayer mockAttacked("name2", "team2", 1, time2);
  listOfTeam.get_player("name") = mockAttacker;
  listOfTeam.get_player("name2") = mockAttacked;
    round.buy_command("name", "gun1", time1);
  EXPECT_CALL(mockAttacker, kill_by(gun1.get_type())).Times(1);
  EXPECT_CALL(mockAttacked, attacked(gun1.damage)).Times(1);
  EXPECT_EQ(round.tap_command("name", "name2", "heavy"), "nice shot");
}

TEST(Round, scoreBoard) {
  std::istringstream input("ROUND 42");
  std::cin.rdbuf(input.rdbuf());
  std::vector<Weapon> gun;
  ListOfTeam listOfTeam;
  Team team("team", gun);
  Team team2("team2", gun);
  listOfTeam.add_team(team);
  listOfTeam.add_team(team2);
  Round round(listOfTeam);

  Time time1(0, 0, 3);
  Time time2(0, 0, 5);
    round.add_user_command("name", "team", time1);
    round.add_user_command("name2", "team", time2);
    round.add_user_command("name3", "team2", time1);
    round.add_user_command("name4", "team2", time2);

  listOfTeam.get_player("name2").get().increment_kill();
  listOfTeam.get_player("name2").get().increment_kill();
  listOfTeam.get_player("name3").get().set_death(2);

  std::string s = "team-Players:\n1 name2 2 0\n2 name 0 0\nteam2-Players:\n1 "
                  "name4 0 0\n2 name3 0 2";
  EXPECT_EQ(round.score_board_command(), s);
}
