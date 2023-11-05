//
// Created by mobin on 18/09/23.
// clang format + ctrl + alt + l
//

#include "Round.h"

Round::Round(ListOfTeam &listOfTeam1)
    : listOfTeam(listOfTeam1), command_number(IO::get_number_of_commands()) {}

void Round::start_round() {
  listOfTeam.restart();
  for (int i = 0; i < command_number; i++) {
    command();
  }
  IO::print_winner(listOfTeam.determine_winner());
}

void Round::command() {
  string command_type = IO::get_command_type();
  string r;
  if (command_type == "ADD-USER") {
    string name, team_name;
    Time t(0, 0, 0);
    IO::get_command_data(name, team_name, t);
    r = add_user(name, team_name, t);
  } else if (command_type == "GET-MONEY") {
    string name;
    Time t(0, 0, 0);
    IO::get_command_data(name, t);
    r = get_money(name);
  } else if (command_type == "GET-HEALTH") {
    string name, cname;
    Time t(0, 0, 0);
    IO::get_command_data(name, t);
    r = get_health(name);
  } else if (command_type == "TAP") {
    string attacker, attacked, gun_type;
    Time t(0, 0, 0);
    IO::get_command_data(attacker, attacked, gun_type, t);
    r = tap(attacker, attacked, gun_type);
  } else if (command_type == "BUY") {
    string name, gun;
    Time t(0, 0, 0);
    IO::get_command_data(name, gun, t);
    r = buy(name, gun, t);
  } else if (command_type == "SCORE-BOARD") {
    Time t(0, 0, 0);
    IO::get_command_data(t);
    r = score_board();
  }

  IO::command_output(r);
}

string Round::add_user(string name, string team_name, Time &t) {

  Team &team = listOfTeam.get_team(team_name);

  Player &player = listOfTeam.get_player(name);

  if (player != Player::null) {
    return "you are already in this game";
  } else if (team.is_full()) {
    return "this team is full";
  } else {
    team.add_player(name, t);
    return "this user added to " + team.get_name();
  }
}

string Round::get_health(std::string name) {
  Player &player = listOfTeam.get_player(name);

  if (player == Player::null) {
    return "invalid username";
  } else {
    return to_string(player.get_health());
  }
}

string Round::get_money(std::string name) {

  Player &player = listOfTeam.get_player(name);

  if (player == Player::null) {
    return "invalid username";
  } else {
    return to_string(player.get_money());
  }
}

string Round::buy(std::string name, std::string gun, Time &t) {

  Player &player = listOfTeam.get_player(name);

  if (player == Player::null) {
    return "invalid username";
  }
  Gun &gun1 = listOfTeam.get_team(player.get_team_name()).get_gun(gun);

  if (!player.is_alive()) {
    return "deads can not buy";
  } else if (Configuration::get_instance()->buy_limit <= t) {
    return "you are out of time";
  } else if (gun1 == Gun::null) {
    return "invalid category gun";
  } else if (player.is_full(gun1.get_type())) {
    return "you have a " + gun1.get_type();
  } else if (gun1.price > player.get_money()) {
    return "no enough money";
  } else {
    player.buy(gun1);
    return "I hope you can use it";
  }
}

string Round::tap(std::string name_of_attacker, std::string name_of_attacked,
                  std::string gun_type) {
  Player &attacker = listOfTeam.get_player(name_of_attacker);
  Player &attacked = listOfTeam.get_player(name_of_attacked);
  Gun &gun1 = attacker.get_gun(gun_type);

  if (attacked == Player::null || attacker == Player::null) {
    return "invalid username";
  } else if (!attacker.is_alive()) {
    return "attacker is dead";
  } else if (!attacked.is_alive()) {
    return "attacked is dead";
  } else if (gun1 == Gun::null) {
    return "no such gun";
  } else if (attacker.get_team_name() == attacked.get_team_name()) {
    return "friendly fire";
  } else {
    attacked.attacked(gun1.damage);
    if (!attacked.is_alive()) {
      attacker.kill_by(gun1.get_type());
    }
    return "nice shot";
  }
}

string Round::score_board() {
  string s = "";
  Team team = Team::null;
  Player player = Player::null;
  for (int i = 0; i < listOfTeam.get_number_of_team(); i++) {
    team = listOfTeam.get_team(i);
    s += team.get_name() + "-Players:" + "\n";
    team.sort_player();
    for (int j = 0; j < team.get_number_of_players(); j++) {
      player = team.get_player(j);
      s += to_string(j + 1) + " " + player.get_name() + " " +
           to_string(player.get_kill()) + " " + to_string(player.get_death()) +
           "\n";
    }
  }
  s.pop_back();
  return s;
}
