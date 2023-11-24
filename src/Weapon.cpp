//
// Created by mobin on 18/09/23.
//

#include "Weapon.h"

Weapon::Weapon(std::string name, gun_type gunType, int price, int damage,
               int kill_reward)
    : name(name), type(gunType), price(price), damage(damage),
      kill_reward(kill_reward) {}

gun_type Weapon::get_type() { return type; }

gun_type Weapon::string_to_type(std::string s){
    gun_type g;
    if(s == "heavy"){
        g = heavy;
    }
    else if(s == "pistol"){
        g = pistol;
    }
    else if(s == "knife"){
        g = cold_weapon;
    }
    return g;
}

std::string Weapon::type_to_string(gun_type type) {
    std::string g;
    if(type == heavy){
        g = "heavy";
    }
    else if(type == pistol){
        g = "pistol";
    }
    else if(type == cold_weapon){
        g = "knife";
    }
    return g;
}

bool Weapon::operator==(Weapon g) {

  if (this->name == g.name && this->price == g.price &&
      this->damage == g.damage && this->kill_reward == g.kill_reward &&
      this->type == g.type) {
    return true;
  } else {
    return false;
  }
}

bool Weapon::operator==(const Weapon g) const {
  if (this->name == g.name && this->price == g.price &&
      this->damage == g.price && this->kill_reward == g.kill_reward &&
      this->type == g.type) {
    return true;
  } else {
    return false;
  }
}
