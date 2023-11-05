//
// Created by mobin on 30/09/23.
//

#ifndef R_IMMUNITIOIN_H
#define R_IMMUNITIOIN_H

#include "vector"

#include "Configuration.h"
#include "Gun.h"
#include "HeavyGun.h"
#include "Pistol.h"

class Ammunition {
public:
  /**
   * @brief add gun to the list of pistols and list of heavy guns according to
   * the type of gun
   *
   * @param gun
   */
  void add_gun(Gun &gun);

  /**
   *
   * @param gun_type
   * @return gun if there is, null otherwise
   */
  Gun &get_gun(std::string gun_type);

  /**
   *
   * @return number of heavy guns
   */
  int get_heavy_gun_number();

  /**
   *
   * @return number of pistols
   */
  int get_pistol_number();

  /**
   *
   * @param gun_type
   * @return true if ammunition is full of this type of gun
   */
  bool is_full(std::string gun_type);

  /**
   * @brief clear list of heavy guns vector and list of pistols vector
   */
  void clear();

private:
  Gun knife = Configuration::get_instance()->knife;
  std::vector<Gun> list_of_pistols;
  std::vector<Gun> list_of_heavy_guns;

  Gun &get_heavy_gun();
  Gun &get_pistol();
};

#endif // R_IMMUNITIOIN_H
