//
// Created by mobin on 18/09/23.
//

#ifndef P_HEAVYGUN_H
#define P_HEAVYGUN_H
#include "Gun.h"

class HeavyGun : public Gun {
public:
  HeavyGun(std::string name, int price, int damage, int kell_reward);

  /**
   *
   * @return "heavy"
   */
  virtual std::string get_type();
};

#endif // P_HEAVYGUN_H
