//
// Created by mobin on 30/09/23.
//

///////////////Rpa : all inf
#ifndef R_IDK_H
#define R_IDK_H

#include <vector>

#include "Gun.h"
#include "HeavyGun.h"
#include "Pistol.h"
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

  std::vector<Gun> guns_of_team1;
  std::vector<Gun> guns_of_team2;

  const Time round_duration = Time(2, 15, 0);
  const Time buy_limit = Time(0, 45, 0);
  const Time join_limit = Time(0, 3, 0);

  HeavyGun ak = HeavyGun("AK", 2700, 31, 100);
  HeavyGun awp = HeavyGun("AWP", 4300, 110, 50);
  HeavyGun m4a1 = HeavyGun("M4A1", 2700, 29, 100);

  Pistol revolver = Pistol("Revolver", 600, 51, 150);
  Pistol glock_18 = Pistol("Glock-18", 300, 11, 200);
  Pistol desert_eagle = Pistol("Desert-Eagle", 600, 53, 175);
  Pistol ups_s = Pistol("UPS-S", 300, 13, 225);

  Gun knife = Gun("knife", 0, 43, 500, false);

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
  static Configuration *idk1;
};

#endif // R_IDK_H
