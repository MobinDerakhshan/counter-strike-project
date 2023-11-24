//
// Created by mobin on 18/09/23.
//

#ifndef P_LISTOFTEAM_H
#define P_LISTOFTEAM_H
#include <vector>
#include <exception>

#include "Team.h"

class ListOfTeam {
public:
  /***
   *
   * @brief add new team to list of team vector
   *
   * @param team
   */
  void add_team(Team &team);

  /***
   * @brief determine for each team win or lose and return winner team
   *
   * winner is a team that has one player alive
   * if two team have player alive team with less index is winner
   *
   * @return name of winner team
   */
  Team &determine_winner();

  /***
   * make sure this team exists before using
   *
   * @param team_name name of team
   * @return team if there is, runtime error otherwise
   */

  Team &get_team(const std::string &team_name);

  /***
   * make sure this team exists before using
   *
   * @param i index of team
   * @return team if there is, runtime error otherwise
   */
  Team &get_team(int i);

  /***
   * @brief check all team to find player
   *
   * make sure this team exists before using
   *
   * @param player_name
   * @return player if there is, runtime error otherwise
   */
  std::reference_wrapper<Player> get_player(const std::string& player_name);

  /**
   *
   * @param player_name
   * @return true if player exist in the game, false otherwise
   */
  bool player_exist(const std::string &player_name);

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


private:
  std::vector<Team> list_of_teams;
};

#endif // P_LISTOFTEAM_H
