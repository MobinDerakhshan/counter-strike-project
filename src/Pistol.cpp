//
// Created by mobin on 18/09/23.
//

#include "Pistol.h"

Pistol::Pistol(std::string name, int price, int damage, int kill_reward)
    : Gun(name, price, damage, kill_reward, true) {
  type = "pistol";
}

std::string Pistol::get_type() { return type; }
