//
// Created by mobin on 18/09/23.
//

#ifndef P_PISTOL_H
#define P_PISTOL_H
#include "Gun.h"

class Pistol : public Gun {
public:
  Pistol(std::string name, int price, int damage, int kell_reward);

  /**
   *
   * @return "pistol"
   */
  virtual std::string get_type();

  const bool need_to_buy = true;
};

#endif // P_PISTOL_H
