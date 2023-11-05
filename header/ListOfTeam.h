//
// Created by mobin on 18/09/23.
//

#ifndef P_LISTOFTEAM_H
#define P_LISTOFTEAM_H
#include "Team.h"
#include <vector>

class ListOfTeam {
public:
  /**
   * @brief add new team to list of team vector
   *
   * @param team_name
   * @param guns_of_team
   */
  void add_team(std::string team_name, std::vector<Gun> guns_of_team);

  /***
   *
   * @param team_name name of team
   * @return team if there is, null otherwise
   */
  Team &get_team(std::string team_name);

  /***
   *
   * @param i index of team
   * @return team if there is, null if i was out of range
   */
  Team &get_team(int i);

  /***
   *@brief check all team to find player
   *
   * @param name name of player
   * @return player if there is, null otherwise
   */
  Player &get_player(std::string player_name);

  /**
   *
   * @return number of teams
   */
  int get_number_of_team();

  /***
   * @brief reset and all player in the game
   *
   * set players health with starting health
   */
  void restart();

  /***
   * @brief determine for each team win or lose and return name of winner team
   *
   * winner is a team that has one player alive
   * if two team have player alive team with less index is winner
   *
   * @return name of winner team
   */
  std::string determine_winner();

private:
  std::vector<Team> list_of_team;
};

#endif // P_LISTOFTEAM_H
