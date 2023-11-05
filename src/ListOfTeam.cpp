//
// Created by mobin on 18/09/23.
//

#include "ListOfTeam.h"

void ListOfTeam::add_team(std::string team_name,
                          std::vector<Gun> guns_of_team) {
  list_of_team.emplace_back(team_name, guns_of_team);
}

int ListOfTeam::get_number_of_team() { return list_of_team.size(); }

Team &ListOfTeam::get_team(std::string team_name) {
  for (Team &i : list_of_team) {
    if (i.get_name() == team_name) {
      return i;
    }
  }
  return Team::null;
}

Team &ListOfTeam::get_team(int i) {
  if (get_number_of_team() > i - 1) {
    return list_of_team[i];
  } else {
    return Team::null;
  }
}

Player &ListOfTeam::get_player(std::string name) {
  for (Team &i : list_of_team) {
    if (i.get_player(name) != Player::null) {
      return i.get_player(name);
    }
  }
  return Player::null;
}

void ListOfTeam::restart() {
  for (Team &i : list_of_team) {
    i.restart();
  }
}

// if all die first get_team will win
std::string ListOfTeam::determine_winner() {
  std::string winner;
  int in_the_game = 0;
  for (int i = 0; i < list_of_team.size(); i++) {
    if (!list_of_team[i].all_die()) {
      in_the_game = i;
      break;
    }
  }
  for (int i = 0; i < list_of_team.size(); i++) {
    if (i == in_the_game) {
      list_of_team[i].win();
      winner = list_of_team[i].get_name();
    } else {
      list_of_team[i].lose();
    }
  }
  return winner;
}
