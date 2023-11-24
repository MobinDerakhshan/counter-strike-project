//
// Created by mobin on 18/09/23.
//

#include "Team.h"
#include "Configuration.h"

Team::Team(const std::string &name, std::vector<Weapon> authorizedGuns)
    : name(name) {
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

void Team::add_player(const std::string &player_name, const Time &t) {
  int number_of_player = list_of_players.size() - 1;
  list_of_players.emplace_back(player_name, get_name(), number_of_player, t);
}

bool Team::player_exists(std::string player_name) {
  bool exists = false;
  for (Player &i : list_of_players) {
    if (i.get_name() == player_name) {
      exists = true;
      break;
    }
  }
  return exists;
}

Player &Team::get_player(const std::string &player_name) {
  for (Player &i : list_of_players) {
    if (i.get_name() == player_name) {
      return i;
    }
  }
  throw std::runtime_error("wrong get play");
}

Player &Team::get_player(int i) {
  if (i < get_number_of_players()) {
    return list_of_players[i];
  } else {
    throw std::runtime_error(" message");
  }
}

bool Team::all_die() {
  if (list_of_players.empty()) {
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

void Team::add_gun(std::vector<Weapon> &guns) { list_of_gun = std::move(guns); }

std::shared_ptr<Weapon> Team::get_gun(const std::string &name) {
  std::shared_ptr<Weapon> gun;
  for (Weapon &i : list_of_gun) {
    if (i.name == name) {
      gun = std::make_shared<Weapon>(i);
    }
  }
  return gun;
}
