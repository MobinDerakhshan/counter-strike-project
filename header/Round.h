//
// Created by mobin on 18/09/23.
//

#ifndef P_ROUND_H
#define P_ROUND_H
#include <variant>
#include <memory>

#include "Configuration.h"
#include "IO.h"
#include "ListOfTeam.h"

using namespace std;

class Round {
public:
  Round(ListOfTeam &listOfTeam);

  /**
   * @brief restart list of teams & run command function & print winner of this
   * round
   */
  void start_round();

  /**
   * @brief get command & run related function & print answer
   */
  void command();

  /**
   * @brief add player named "name" to the team named "team" and check
   * conditions
   *
   * @param name
   * @param team_name
   * @param t
   * @return
   */
  string add_user_command(const string& name, const string& team_name,const Time &t);

  /**
   * @brief get money of player named "name"
   *
   * @param name
   * @return
   */
  string get_money_command(const string& name);

  /**
   * @brief get health of player maned "name"
   *
   * @param name
   * @return
   */
  string get_health_command(const string& name);

  /**
   * @brief buy_command gun named "gun" for player named "name"
   *
   * @param name
   * @param gun
   * @param t
   * @return
   */
  string buy_command(const string& name, const string& gun, Time &t);

  /**
   * @brief player named "attacker" attack another player named "attacked" with
   * his gun from type of "gun_type"
   *
   * @param name_of_attacker
   * @param name_of_attacked
   * @param gun_type
   * @return
   */
  string tap_command(const string& name_of_attacker, const string& name_of_attacked, string gun_type);

  /**
   * @brief sort player and then return score board
   *
   * @return
   */
  string score_board_command();

private:
  ListOfTeam &listOfTeam;
  int command_number;
};

#endif // P_ROUND_H
