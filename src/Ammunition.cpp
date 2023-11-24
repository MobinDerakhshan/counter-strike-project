//
// Created by mobin on 30/09/23.
//

#include "Ammunition.h"
#include "Configuration.h"

Ammunition::Ammunition() : knife(Configuration::get_instance()->knife) {}

void Ammunition::add_gun(const std::shared_ptr<Weapon> &gun) {
  if (!is_full(gun->get_type())) {
    if (gun->get_type() == heavy) {
      list_of_heavy_guns.push_back(gun);
    } else if (gun->get_type() == pistol) {
      list_of_pistols.push_back(gun);
    }
  }
}

void Ammunition::clear() {
  deleted_weapons.insert(deleted_weapons.end(), list_of_heavy_guns.begin(),
                         list_of_heavy_guns.end());
  deleted_weapons.insert(deleted_weapons.end(), list_of_pistols.begin(),
                         list_of_pistols.end());
  list_of_pistols.clear();
  list_of_heavy_guns.clear();
}

std::shared_ptr<Weapon> Ammunition::get_gun(gun_type gun_type) {
  if (gun_type == heavy) {
    return get_heavy_gun();
  } else if (gun_type == pistol) {
    return get_pistol();
  } else if (gun_type == cold_weapon) {
    return std::make_shared<Weapon>(knife);
  }
}

bool Ammunition::is_full(gun_type gun_type) {
  if (gun_type == heavy) {
    return get_heavy_gun_number() ==
           Configuration::get_instance()->number_of_players_heavy_gun;
  } else if (gun_type == pistol) {
    return get_pistol_number() ==
           Configuration::get_instance()->number_of_players_pistol;
  } else {
    return true;
  }
}

std::shared_ptr<Weapon> Ammunition::get_heavy_gun() {
  std::shared_ptr<Weapon> gun;
  if (!list_of_heavy_guns.empty()) {
    gun = list_of_heavy_guns.back();
  }
  return gun;
}

std::shared_ptr<Weapon> Ammunition::get_pistol() {
  std::shared_ptr<Weapon> gun;
  if (!list_of_pistols.empty()) {
    gun = list_of_pistols.back();
  }
  return gun;
}

int Ammunition::get_heavy_gun_number() { return list_of_heavy_guns.size(); }

int Ammunition::get_pistol_number() { return list_of_pistols.size(); }
