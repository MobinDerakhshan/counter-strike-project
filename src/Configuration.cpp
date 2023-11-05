//
// Created by mobin on 30/09/23.
//

#include "../header/Configuration.h"

Configuration *Configuration::idk1 = NULL;

Configuration::Configuration() {

  guns_of_team1.push_back(m4a1);
  guns_of_team1.push_back(awp);
  guns_of_team1.push_back(desert_eagle);
  guns_of_team1.push_back(ups_s);

  guns_of_team2.push_back(ak);
  guns_of_team2.push_back(awp);
  guns_of_team2.push_back(revolver);
  guns_of_team2.push_back(glock_18);
}

Configuration *Configuration::get_instance() {
  if (idk1 == NULL) {
    idk1 = new Configuration();
  }
  return idk1;
}

void Configuration::clear() {
    delete idk1;
}