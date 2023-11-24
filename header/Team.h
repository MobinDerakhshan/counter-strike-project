//
// Created by mobin on 18/09/23.
//

#ifndef P_TEAM_H
#define P_TEAM_H
#include <algorithm>
#include <exception>
#include <memory>
#include <vector>

#include "Player.h"

class Team {
public:
  Team(const std::string &name, std::vector<Weapon> authorizedGuns);

  std::string get_name();

  int get_number_of_players();

  /**
   *
   * @param player_name
   * @return true if player exists in the team, false otherwise
   */
  bool player_exists(std::string player_name);

  /**
   * make sure this player exists before using
   *
   * @param player_name
   * @return player named "player_name" if there is in the team, runtime error otherwise
   */
  Player &get_player(const std::string &player_name);

  /**
   * make sure this player exists before using
   *
   * @param i
   * @return player with index i if there is, runtime error otherwise
   */
  Player &get_player(int i);

  /**
   *
   * @param name
   * @return gun if allowed for this team, empty shared_ptr otherwise
   */
  std::shared_ptr<Weapon> get_gun(const std::string &name);

  /**
   * @brief add player named "player_name" and set number for player
   *
   * number of player is assigned based of order of entry
   *
   * @param player_name
   * @param t
   */
  void add_player(const std::string &player_name, const Time &t);

  /**
   * @brief add guns to the list of gun
   *
   * @param guns
   */
  void add_gun(std::vector<Weapon> &guns);

  /**
   * @brief run win function for all player in the team
   */
  void win();

  /**
   * @brief run lose function for all player in the team
   */
  void lose();

  /**
   * @brief reset health of all player in the team
   */
  void restart();

  /**
   * @brief sort player according to their kill number, death number and number
   * of them
   */
  void sort_player();

  /**
   *
   * @return true if all of the player in the team are dead
   */
  bool all_die();

  /**
   *
   * @return true if team is full of players and cant add another player
   */
  bool is_full();

private:
  std::string name;
  std::vector<Player> list_of_players;
  std::vector<Weapon> list_of_gun;
};

#endif // P_TEAM_H