//
// Created by mobin on 30/09/23.
//

#ifndef R_IMMUNITIOIN_H
#define R_IMMUNITIOIN_H
#include <memory>
#include <vector>

#include "Weapon.h"

class Ammunition {
public:
  Ammunition();

  /**
   * @brief add gun to the list of pistols or list of heavy guns according to
   * the type of gun
   *
   * @param gun
   */
  void add_gun(const std::shared_ptr<Weapon> &gun);

  /**
   * @brief clear list of heavy guns vector and list of pistols vector and add
   * deleted guns to the deleted_weapons vector
   */
  void clear();

  /**
   *
   * @param gun_type
   * @return shared_ptr of gun if there is, empty shared_ptr otherwise
   */
  std::shared_ptr<Weapon> get_gun(gun_type gun_type);

  /**
   *
   * @param gun_type
   * @return true if ammunition is full of this type of gun
   */
  bool is_full(gun_type gun_type);

private:
  Weapon knife;
  std::vector<std::shared_ptr<Weapon>> list_of_pistols;
  std::vector<std::shared_ptr<Weapon>> list_of_heavy_guns;
  std::vector<std::shared_ptr<Weapon>> deleted_weapons;

  /**
   *
   * @return last gun in list_of_heavy_guns vector
   */
  std::shared_ptr<Weapon> get_heavy_gun();

  /**
   *
   * @return number of heavy guns
   */
  int get_heavy_gun_number();

  /**
   *
   * @return last gun in list_of_pistols vector
   */
  std::shared_ptr<Weapon> get_pistol();

  /**
   *
   * @return number of pistols
   */
  int get_pistol_number();
};

#endif // R_IMMUNITIOIN_H
