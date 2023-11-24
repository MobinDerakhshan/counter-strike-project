//
// Created by mobin on 18/09/23.
//

#ifndef P_GUN_H
#define P_GUN_H
#include "string"
#include "vector"

enum gun_type { heavy, pistol, cold_weapon};

class Weapon {
public:
  Weapon(std::string name, gun_type gunType, int price, int damage,
         int kill_reward);
  /**
   *
   * @return "heavy" if gun is a HeavyGun, "pistol" if gun is a Pistol, name of
   * gun otherwise
   */
  gun_type get_type();

  static gun_type string_to_type(std::string s);

  static std::string type_to_string(gun_type type);

  /**
   * @brief compare name, price, damage, kill, reward, need_to_buy and type
   *
   * @param g
   * @return
   */
  bool operator==(Weapon g);
  bool operator==(const Weapon g) const;

  std::string name;
  gun_type type;
  int price;
  int damage;
  int kill_reward;
};

#endif // P_GUN_H
