//
// Created by mobin on 18/09/23.
//

#ifndef P_PLAYER_H
#define P_PLAYER_H
#include <memory>

#include "Ammunition.h"
#include "Time.h"

class Player {
public:
  Player(std::string name, std::string team_name, int number_in_team,
         const Time &t);

  std::string get_name() const;

  std::string get_team_name() const;

  int get_health() const;

  int get_money() const;

  int get_kill() const;

  int get_death() const;

  int get_win_number() const;

  int get_lose_number() const;

  int get_number_in_team() const;

  /**
   *
   * @param gun_type
   * @return shared_ptr gun with type "gun_type" if there is, empty shared_ptr otherwise
   */
  std::shared_ptr<Weapon> get_gun(gun_type gun_type);

  void set_health(int health);

  void reset_health();

  void set_money(int money);

  void increment_kill();

  void set_death(int death);

  void set_win_number(int win_number);

  void set_lose_number(int lose_number);

  void set_number_in_team(int number);

  void add_gun(std::shared_ptr<Weapon> &gun);

  /***
   * @brief decrease money and add gun
   *
   * dont check anything and imagine all thing is ok(player is alive, have
   * money, ...)
   *
   * @param gun
   */
  void buy(std::shared_ptr<Weapon> gun);

  /**
   * @brief increase money and kill number
   *
   * @param gun_type
   */
  void kill_by(gun_type gun_type);

  /**
   * @brief decrease health and run die function if damage kill player
   *
   * @param damage
   * @return false if player is alive, true otherwise
   */
  bool attacked(int damage);

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
  bool is_full(gun_type gun_type);

  /**
   *
   * @return true if health was 0
   */
  bool is_alive() const;

  /**
   * @brief just compare name of players
   *
   * @param player
   * @return
   */
  bool operator==(const Player &player) const;

  /**
   * @brief just compare name of players
   *
   * @param player
   * @return
   */
  bool operator!=(const Player &player) const;

  /**
   * compare kill number, death number, number of players
   *
   * @param p1
   * @param p2
   * @return
   */
  static bool compare(const Player &p1, const Player &p2);

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
