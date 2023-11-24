//
// Created by mobin on 30/09/23.
//

#ifndef R_IDK_H
#define R_IDK_H

#include <vector>

#include "Weapon.h"
#include "Team.h"
#include "Time.h"

class Configuration {
public:
  static Configuration *get_instance();

  /**
   * @brief memory deallocation
   */
  static void clear();

  Configuration(Configuration &other) = delete;

  void operator=(const Configuration &) = delete;

  // if all die first team will win
  const std::string name_of_team1 = "Counter-Terrorist";
  const std::string name_of_team2 = "Terrorist";

  const std::vector<Weapon> guns_of_team1 = {Weapon("AWP", heavy, 4300, 110, 50),
                                             Weapon("M4A1", heavy, 2700, 29, 100),
                                             Weapon("Desert-Eagle", pistol, 600, 53, 175),
                                             Weapon("UPS-S", pistol, 300, 13, 225)};
  const std::vector<Weapon> guns_of_team2 = {Weapon("AWP", heavy, 4300, 110, 50),
                                             Weapon("AK", heavy, 2700, 31, 100),
                                             Weapon("Revolver", pistol, 600, 51, 150),
                                             Weapon("Glock-18", pistol, 300, 11, 200)};

  Team team1 = Team(name_of_team1, guns_of_team1);
  Team team2 = Team(name_of_team2, guns_of_team2);

  const Time round_duration = Time(2, 15, 0);
  const Time buy_limit = Time(0, 45, 0);
  const Time join_limit = Time(0, 3, 0);

  const Weapon knife = Weapon("knife", cold_weapon, 0, 43, 500);

  const int max_player_for_each_team = 10;
  const int number_of_players_heavy_gun = 1;
  const int number_of_players_pistol = 1;
  const int starting_health = 100;
  const int starting_money = 1000;
  const int starting_kill = 0;
  const int starting_death = 0;
  const int starting_win_number = 0;
  const int starting_lose_number = 0;
  const int minimum_health = 0;
  const int minimum_money = 0;
  const int winners_price = 2700;
  const int losers_price = 2400;
  const int max_money = 10000;

private:
  Configuration();
  static Configuration *configuration1;
};

#endif // R_IDK_H
