//
// Created by mobin on 18/09/23.
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
    r = add_user_command(name, team_name, t);
  } else if (command_type == "GET-MONEY") {
    string name;
    Time t(0, 0, 0);
    IO::get_command_data(name, t);
    r = get_money_command(name);
  } else if (command_type == "GET-HEALTH") {
    string name, cname;
    Time t(0, 0, 0);
    IO::get_command_data(name, t);
    r = get_health_command(name);
  } else if (command_type == "TAP") {
    string attacker, attacked, gun_type;
    Time t(0, 0, 0);
    IO::get_command_data(attacker, attacked, gun_type, t);
    r = tap_command(attacker, attacked, gun_type);
  } else if (command_type == "BUY") {
    string name, gun;
    Time t(0, 0, 0);
    IO::get_command_data(name, gun, t);
    r = buy_command(name, gun, t);
  } else if (command_type == "SCORE-BOARD") {
    Time t(0, 0, 0);
    IO::get_command_data(t);
    r = score_board_command();
  }

  IO::command_output(r);
}

string Round::add_user_command(const string& name, const string& team_name, const Time &t) {

  if(listOfTeam.player_exist(name)){
      return "you are already in this game";
  } else {
      Team &team = listOfTeam.get_team(team_name);
      auto player = listOfTeam.get_player(name);

      if (team.is_full()) {
          return "this team is full";
      } else {
          team.add_player(name, t);
          return "this user added to " + team.get_name();
      }
  }

}

string Round::get_health_command(const std::string& name) {

  if(!listOfTeam.player_exist(name)){
      return "invalid username";
  } else {
      auto player = listOfTeam.get_player(name);

      return to_string(player.get().get_health());
  }

}

string Round::get_money_command(const std::string& name) {

    if(!listOfTeam.player_exist(name)){
        return "invalid username";
    } else {
        auto player = listOfTeam.get_player(name);

        return to_string(player.get().get_money());
    }

}

string Round::buy_command(const std::string& name, const std::string& gun, Time &t) {

    if(!listOfTeam.player_exist(name)){
        return "invalid username";
    } else {
        auto player = listOfTeam.get_player(name);
        shared_ptr<Weapon> gun1 = listOfTeam.get_team(player.get().get_team_name()).get_gun(gun);
        if (!player.get().is_alive()) {
            return "deads can not buy";
        } else if (Configuration::get_instance()->buy_limit <= t) {
            return "you are out of time";
        } else if (!gun1) {
            return "invalid category gun";
        } else if (player.get().is_full(gun1->get_type())) {
            return "you have a " + Weapon::type_to_string(gun1->get_type());
        } else if (gun1->price > player.get().get_money()) {
            return "no enough money";
        } else {
            player.get().buy(gun1);
            return "I hope you can use it";
        }
    }
}

string Round::tap_command(const std::string& name_of_attacker, const std::string& name_of_attacked,
                          std::string gun_type) {
    if(!listOfTeam.player_exist(name_of_attacker) ||  !listOfTeam.player_exist(name_of_attacked)){
            return "invalid username";
    } else {
        auto attacker = listOfTeam.get_player(name_of_attacker);
        auto attacked = listOfTeam.get_player(name_of_attacked);
        auto gun1 = attacker.get().get_gun(Weapon::string_to_type(gun_type));

        if (!attacker.get().is_alive()) {
            return "attacker is dead";
        } else if (!attacked.get().is_alive()) {
            return "attacked is dead";
        } else if (!gun1) {
            return "no such gun";
        } else if (attacker.get().get_team_name() == attacked.get().get_team_name()) {
            return "friendly fire";
        } else {
            if (attacked.get().attacked(gun1->damage)) {
                attacker.get().kill_by(gun1->get_type());
            }
            return "nice shot";
        }
    }
}

string Round::score_board_command() {
  string s;
  for (int i = 0; i < listOfTeam.get_number_of_team(); i++) {
    Team &team = listOfTeam.get_team(i);
    s += team.get_name() + "-Players:" + "\n";
    team.sort_player();
    for (int j = 0; j < team.get_number_of_players(); j++) {
      Player player = team.get_player(j);
      s += to_string(j + 1) + " " + player.get_name() + " " +
           to_string(player.get_kill()) + " " + to_string(player.get_death()) +
           "\n";
    }
  }
  s.pop_back();
  return s;
}
