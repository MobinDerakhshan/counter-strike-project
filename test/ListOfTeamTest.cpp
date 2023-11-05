//
// Created by mobin on 20/10/23.
//

#include <gtest/gtest.h>
#include "ListOfTeam.h"

TEST(ListOfTeam, basics) {
  Time time1(0, 0, 2);
  std::vector<Gun> gun;
  ListOfTeam listOfTeam;
  listOfTeam.add_team("team", gun);
  listOfTeam.get_team("team").add_player("name", time1);
  Player player("name", "team", time1);

  EXPECT_EQ(listOfTeam.get_player("name") == player, true);
  EXPECT_EQ(listOfTeam.get_number_of_team(), 1);

  listOfTeam.add_team("team2", gun);
  EXPECT_EQ(listOfTeam.get_number_of_team(), 2);
}

TEST(ListOfTeam, restart) {
  Time time1(0, 0, 2);
  std::vector<Gun> gun;
  ListOfTeam listOfTeam;
  listOfTeam.add_team("team", gun);
  listOfTeam.add_team("team2", gun);
  listOfTeam.get_team("team").add_player("name", time1);
  listOfTeam.get_team("team2").add_player("name2", time1);

  listOfTeam.get_player("name").set_health(83);
  listOfTeam.get_player("name2").set_health(3);

  listOfTeam.restart();

  EXPECT_EQ(listOfTeam.get_player("name").get_health(),
            Configuration::get_instance()->starting_health);
  EXPECT_EQ(listOfTeam.get_player("name2").get_health(),
            Configuration::get_instance()->starting_health);
}

TEST(ListOfTeam, determineWinner) {
  Time time1(0, 0, 2);
  std::vector<Gun> gun;
  ListOfTeam listOfTeam;
  listOfTeam.add_team("team1", gun);
  listOfTeam.add_team("team2", gun);

  std::string winner = listOfTeam.determine_winner();
  EXPECT_EQ(winner, "team1");

  listOfTeam.get_team("team1").add_player("name", time1);
  listOfTeam.get_team("team2").add_player("name2", time1);
  winner = listOfTeam.determine_winner();
  EXPECT_EQ(winner, "team1");
  EXPECT_EQ(listOfTeam.get_player("name").get_win_number(), 1);
  EXPECT_EQ(listOfTeam.get_player("name2").get_lose_number(), 1);

  listOfTeam.get_team("team").add_player("name3", time1);
  listOfTeam.get_player("name").set_health(0);
  winner = listOfTeam.determine_winner();
  EXPECT_EQ(winner, "team2");
}
