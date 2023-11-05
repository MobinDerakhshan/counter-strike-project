//
// Created by mobin on 18/09/23.
//

#include "Team.h"

Team::Team(std::string name, std::vector<Gun> authorizedGuns) : name(name) {
  add_gun(authorizedGuns);
}

void Team::win() {
  for (Player &i : list_of_players) {
    i.win();
  }
}

void Team::lose() {
  for (Player &i : list_of_players) {
    i.lose();
  }
}

void Team::restart() {
  for (Player &i : list_of_players) {
    i.reset_health();
  }
}

void Team::add_player(std::string name, Time t) {
  list_of_players.emplace_back(name, get_name(), t);
  int number_of_player = list_of_players.size() - 1;
  list_of_players[number_of_player].set_number_in_team(number_of_player);
}

Player &Team::get_player(std::string player_name) {
  for (Player &i : list_of_players) {
    if (i.get_name() == player_name) {
      return i;
    }
  }
  return Player::null;
}

Player &Team::get_player(int i) {
  if (i < get_number_of_players()) {
    return list_of_players[i];
  } else {
    return Player::null;
  }
}

bool Team::all_die() {
  if (list_of_players.size() == 0) {
    return false;
  }
  for (Player &i : list_of_players) {
    if (i.is_alive()) {
      return false;
    }
  }
  return true;
}

int Team::get_number_of_players() { return list_of_players.size(); }

std::string Team::get_name() { return name; }

void Team::sort_player() {
  std::sort(list_of_players.begin(), list_of_players.end(), Player::compare);
}

bool Team::is_full() {
  return get_number_of_players() ==
         Configuration::get_instance()->max_player_for_each_team;
}

void Team::add_gun(std::vector<Gun> &guns) {
  for (Gun &i : guns) {
    list_of_gun.push_back(i);
  }
}

Gun &Team::get_gun(std::string name) {
  for (Gun &i : list_of_gun) {
    if (i.name == name) {
      return i;
    }
  }
  return Gun::null;
}

std::vector<Gun> i = {Gun::null};
Team Team::null = Team("سستشسسعهذذذ هذبخهللذقهلذخهاسقلل", i);