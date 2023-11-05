//
// Created by mobin on 18/09/23.
//

#ifndef P_TEAM_H
#define P_TEAM_H
#include <algorithm>
#include <vector>

#include "Player.h"

class Team {
public:
  Team(std::string name, std::vector<Gun> authorizedGuns);

  std::string get_name();

  int get_number_of_players();

  /**
   *
   * @param player_name
   * @return player named "player_name" if there is in the team, null otherwise
   */
  Player &get_player(std::string player_name);

  /**
   *
   * @param i
   * @return player with index i if there is, null otherwise
   */
  Player &get_player(int i);

  /**
   *
   * @param name
   * @return gun if allowed for this team, null otherwise
   */
  Gun &get_gun(std::string name);

  /**
   * @brief add player named "name" and set number for player
   *
   * number of player is assigned based of order of entry
   *
   * @param name
   * @param t
   */
  void add_player(std::string name, Time t);

  /**
   * @brief add guns to the list of gun
   *
   * @param guns
   */
  void add_gun(std::vector<Gun> &guns);

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

  static Team null;

private:
  std::string name;
  std::vector<Player> list_of_players;
  std::vector<Gun> list_of_gun;
};

#endif // P_TEAM_H