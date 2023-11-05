//
// Created by mobin on 18/09/23.
//

#include "../header/Gun.h"

Gun::Gun(std::string name, int price, int damage, int kill_reward,
         bool need_to_buy) {
  this->name = name;
  this->price = price;
  this->damage = damage;
  this->kill_reward = kill_reward;
  this->need_to_buy = need_to_buy;
}

// Gun::Gun() {}

std::string Gun::get_type() {
  if (type == "pistol" || type == "heavy") {
    return type;
  }
  return name;
}

bool Gun::operator==(Gun g) {

  if (this->name == g.name && this->price == g.price &&
      this->damage == g.damage && this->kill_reward == g.kill_reward &&
      this->need_to_buy == g.need_to_buy && this->get_type() == g.get_type()) {
    return true;
  } else {
    return false;
  }
}

bool Gun::operator==(const Gun g) const {
  if (this->name == g.name && this->price == g.price &&
      this->damage == g.price && this->kill_reward == g.kill_reward &&
      this->need_to_buy == g.need_to_buy) {
    return true;
  } else {
    return false;
  }
}

Gun Gun::null =
    Gun("مشسنتتستتشسینبتمنتسیبتممستیبمنتسمندسیببر رهذ", 3, 4, 5, true);

// std::vector<Gun> Gun::null_vector_of_gun = {Gun::null};