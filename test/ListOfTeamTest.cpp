//
// Created by mobin on 20/10/23.
//

#include <gtest/gtest.h>
#include "ListOfTeam.h"
#include "Configuration.h"

TEST(ListOfTeam, basics) {
  Time time1(0, 0, 2);
  std::vector<Weapon> gun;
  ListOfTeam listOfTeam;
  Team team("team" , gun);
  listOfTeam.add_team(team);
  EXPECT_FALSE(listOfTeam.player_exist("name"));
  listOfTeam.get_team("team").add_player("name", time1);
  EXPECT_TRUE(listOfTeam.player_exist("name"));
  Player p1("name", "team", 0, time1);
  std::reference_wrapper<Player> player(p1);
  EXPECT_TRUE(listOfTeam.get_player("name").get() == player);
  EXPECT_EQ(listOfTeam.get_number_of_team(), 1);
  EXPECT_TRUE(listOfTeam.player_exist("name"));
  Team team2("team2", gun);
  listOfTeam.add_team(team2);
  EXPECT_EQ(listOfTeam.get_number_of_team(), 2);
}

TEST(ListOfTeam, restart) {
  Time time1(0, 0, 2);
  std::vector<Weapon> gun;
  ListOfTeam listOfTeam;
  Team team("team", gun);
  Team team2("team2", gun);
  listOfTeam.add_team(team);
  listOfTeam.add_team(team2);
  listOfTeam.get_team("team").add_player("name", time1);
  listOfTeam.get_team("team2").add_player("name2", time1);

  listOfTeam.get_player("name").get().set_health(83);
  listOfTeam.get_player("name2").get().set_health(3);

  listOfTeam.restart();

  EXPECT_EQ(listOfTeam.get_player("name").get().get_health(),
            Configuration::get_instance()->starting_health);
  EXPECT_EQ(listOfTeam.get_player("name2").get().get_health(),
            Configuration::get_instance()->starting_health);
}

TEST(ListOfTeam, determineWinner) {
  Time time1(0, 0, 2);
  std::vector<Weapon> gun;
  ListOfTeam listOfTeam;
  Team team1("team1", gun);
  Team team2("team2", gun);
  listOfTeam.add_team(team1);
  listOfTeam.add_team(team2);

  Team winner = listOfTeam.determine_winner();
  EXPECT_EQ(winner.get_name(), "team1");

  listOfTeam.get_team("team1").add_player("name", time1);
  listOfTeam.get_team("team2").add_player("name2", time1);
  winner = listOfTeam.determine_winner();
  EXPECT_EQ(winner.get_name(), "team1");
  EXPECT_EQ(listOfTeam.get_player("name").get().get_win_number(), 1);
  EXPECT_EQ(listOfTeam.get_player("name2").get().get_lose_number(), 1);

  listOfTeam.get_team("team2").add_player("name3", time1);
  listOfTeam.get_player("name").get().set_health(0);
  winner = listOfTeam.determine_winner();
  EXPECT_EQ(winner.get_name(), "team2");
}
