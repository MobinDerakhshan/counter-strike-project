//
// Created by mobin on 18/09/23.
//

#ifndef P_GUN_H
#define P_GUN_H
#include "string"
#include "vector"

class Gun {
public:
  Gun(std::string name, int price, int damage, int kill_reward,
      bool need_to_buy);
  /**
   *
   * @return "heavy" if gun is a HeavyGun, "pistol" if gun is a Pistol, name of
   * gun otherwise
   */
  virtual std::string get_type();

  /**
   * @brief compare name, price, damage, kill, reward, need_to_buy and type
   *
   * @param g
   * @return
   */
  bool operator==(Gun g);
  bool operator==(const Gun g) const;

  std::string name;
  int price;
  int damage;
  int kill_reward;
  std::string type;
  bool need_to_buy;

  static Gun null;
};

#endif // P_GUN_H
