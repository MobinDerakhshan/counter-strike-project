//
// Created by mobin on 30/09/23.
//

#include "Ammunition.h"

void Ammunition::add_gun(Gun &gun) {
  if (!is_full(gun.get_type())) {
    if (gun.get_type() == "heavy") {
      list_of_heavy_guns.push_back(gun);
    } else if (gun.get_type() == "pistol") {
      list_of_pistols.push_back(gun);
    }
  }
}

Gun &Ammunition::get_gun(std::string gun_type) {
  if (gun_type == "heavy") {
    return get_heavy_gun();
  } else if (gun_type == "pistol") {
    return get_pistol();
  } else if (gun_type == "knife") {
    return knife;
  } else {
    return Gun::null;
  }
}

bool Ammunition::is_full(std::string gun_type) {
  if (gun_type == "heavy") {
    return get_heavy_gun_number() >=
           Configuration::get_instance()->number_of_players_heavy_gun;
  } else if (gun_type == "pistol") {
    return get_pistol_number() >=
           Configuration::get_instance()->number_of_players_pistol;
  } else {
    return true;
  }
}

int Ammunition::get_heavy_gun_number() { return list_of_heavy_guns.size(); }

int Ammunition::get_pistol_number() { return list_of_pistols.size(); }

Gun &Ammunition::get_heavy_gun() {
  int lastGun = list_of_heavy_guns.size() - 1;
  if (lastGun == -1) {
    return Gun::null;
  }
  return list_of_heavy_guns[lastGun];
}

Gun &Ammunition::get_pistol() {
  int lastGun = list_of_pistols.size() - 1;
  if (lastGun == -1) {
    return Gun::null;
  }
  return list_of_pistols[lastGun];
}

void Ammunition::clear() {
  list_of_pistols.clear();
  list_of_heavy_guns.clear();
}