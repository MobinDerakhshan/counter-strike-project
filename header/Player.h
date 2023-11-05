//
// Created by mobin on 18/09/23.
//

#ifndef P_PLAYER_H
#define P_PLAYER_H

#include "Ammunition.h"
#include "Time.h"
#include "string"

class Player {
public:
  Player(std::string name, std::string team_name, Time t);

  std::string get_name();

  std::string get_team_name();

  int get_health();

  int get_money();

  int get_kill();

  int get_death();

  int get_win_number();

  int get_lose_number();

  int get_number_in_team();

  /**
   *
   * @param gun_type
   * @return gun with type "gun_type" if there is, null otherwise
   */
  Gun &get_gun(std::string gun_type);

  void set_health(int health);

  void reset_health();

  void set_money(int money);

  void set_kill(int kill);

  void set_death(int death);

  void set_win_number(int win_number);

  void set_lose_number(int lose_number);

  void set_number_in_team(int number);

  void add_gun(Gun &gun);

  /***
   * @brief decrease money and add gun
   *
   * dont check anything and imagine all thing is ok(player is alive, have
   * money, ...)
   *
   * @param gun
   */
  void buy(Gun &gun);

  /**
   * @brief increase money and kill number
   *
   * @param gun_type string of type of gun that player use
   */
  void kill_by(std::string gun_type);

  /**
   * @brief decrease health and run die function if damage kill player
   *
   * @param damage
   */
  void attacked(int damage);

  /**
   * @brief clear ammunition and increase death number
   */
  void die();

  /**
   * @brief increase money and win number
   */
  void win();

  /**
   * @brief increase money and lose number
   */
  void lose();

  /**
   *
   * @param gun_type
   * @return true if ammunition is full of this type of gun
   */
  bool is_full(std::string gun_type);

  /**
   *
   * @return true if health was 0
   */
  bool is_alive();

  /**
   * @brief just compare name of players
   *
   * @param player
   * @return
   */
  bool operator==(Player player);

  /**
   * @brief just compare name of players
   *
   * @param player
   * @return
   */
  bool operator==(const Player player) const;

  /**
   * @brief just compare name of players
   *
   * @param player
   * @return
   */
  bool operator!=(Player player);

  /**
   * @brief just compare name of players
   *
   * @param player
   * @return
   */
  bool operator!=(const Player player) const;

  /**
   * compare kill number, death number, number of players
   *
   * @param p1
   * @param p2
   * @return
   */
  static bool compare(Player p1, Player p2);

  static Player null;

private:
  std::string name;
  std::string team_name;
  int health;
  int money;
  int kill_number;
  int death_number;
  int win_number;
  int lose_number;
  int number_in_team;
  Ammunition ammunition;
};

// typedef Player *PlayerPointer;

#endif // P_PLAYER_H
