//
// Created by mobin on 18/09/23.
//
// ref raper
#ifndef P_GAME_H
#define P_GAME_H

#include "Configuration.h"
#include "IO.h"
#include "ListOfTeam.h"
#include "Round.h"

class Game {
public:
  /**
   * @brief make teams and add them to list of team and get number of rounds
   * from input
   */
  Game();

  /**
   * @brief start game
   */
  void play();

private:
  int round_number;
  ListOfTeam listOfTeam;
};

#endif // P_GAME_H
