//
// Created by mobin on 18/09/23.
//

#include "ListOfTeam.h"

void ListOfTeam::add_team(Team &team) { list_of_teams.push_back(team); }

int ListOfTeam::get_number_of_team() { return list_of_teams.size(); }

Team &ListOfTeam::get_team(const std::string &team_name) {
  for (Team &i : list_of_teams) {
    if (i.get_name() == team_name) {
      return i;
    }
  }
  throw std::runtime_error(" invalid team name");
}

Team &ListOfTeam::get_team(int i) {
  if (get_number_of_team() > i) {
    return list_of_teams[i];
  } else {
    throw std::runtime_error(" invalid team number");
  }
}

std::reference_wrapper<Player> ListOfTeam::get_player(const std::string &name) {
  for (Team &i : list_of_teams) {
    if (i.player_exists(name)) {
      return std::reference_wrapper<Player>(i.get_player(name));
    }
  }
  throw std::runtime_error("This player does not exist");
}

bool ListOfTeam::player_exist(const std::string &player_name) {
  bool exist = false;
  for (Team &i : list_of_teams) {
    if (i.player_exists(player_name)) {
      exist = true;
      break;
    }
  }
  return exist;
}

void ListOfTeam::restart() {
  for (Team &i : list_of_teams) {
    i.restart();
  }
}

// if all die first team will win
Team &ListOfTeam::determine_winner() {
  Team &winner = list_of_teams[0];
  int in_the_game = 0;
  for (int i = 0; i < list_of_teams.size(); i++) {
    if (!list_of_teams[i].all_die()) {
      in_the_game = i;
      break;
    }
  }
  for (int i = 0; i < list_of_teams.size(); i++) {
    if (i == in_the_game) {
      list_of_teams[i].win();
      winner = list_of_teams[i];
    } else {
      list_of_teams[i].lose();
    }
  }
  return winner;
}
