//
// Created by mobin on 18/09/23.
//

#include "Game.h"

Game::Game() {
  round_number = IO::get_number_of_rounds();

  listOfTeam.add_team(Configuration::get_instance()->team1);
  listOfTeam.add_team(Configuration::get_instance()->team2);
}

void Game::play() {
  for (int i = 0; i < round_number; i++) {
    Round r(listOfTeam);
    r.start_round();
  }
}
