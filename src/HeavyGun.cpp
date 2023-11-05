//
// Created by mobin on 18/09/23.
//

#include "HeavyGun.h"
HeavyGun::HeavyGun(std::string name, int price, int damage, int kill_reward)
    : Gun(name, price, damage, kill_reward, true) {
  type = "heavy";
}

std::string HeavyGun::get_type() { return type; }
