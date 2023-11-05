//
// Created by mobin on 18/09/23.
//

#include "Player.h"

Player::Player(std::string name, std::string team_name, Time t) {
  this->name = name;
  this->team_name = team_name;
  set_kill(Configuration::get_instance()->starting_kill);
  set_death(Configuration::get_instance()->starting_death);
  set_win_number(Configuration::get_instance()->starting_win_number);
  set_lose_number(Configuration::get_instance()->starting_lose_number);
  set_money(Configuration::get_instance()->starting_money);
  if (t < Configuration::get_instance()->join_limit) {
    set_health(Configuration::get_instance()->starting_health);
  } else {
    set_health(Configuration::get_instance()->minimum_health);
  }
  ammunition = Ammunition();
}

void Player::kill_by(std::string gun_type) {
  int reward = get_gun(gun_type).kill_reward;
  set_money(get_money() + reward);
  set_kill(get_kill() + 1);
}

void Player::attacked(int damage) {
  set_health(get_health() - damage);
  if (!this->is_alive()) {
    die();
  }
}

void Player::die() {
  this->ammunition.clear();
  set_death(get_death() + 1);
}

void Player::buy(Gun &gun) {
  set_money(get_money() - gun.price);
  add_gun(gun);
}

void Player::win() {
  set_win_number(get_win_number() + 1);
  set_money(get_money() + Configuration::get_instance()->winners_price);
}

void Player::lose() {
  set_lose_number(get_lose_number() + 1);
  set_money(get_money() + Configuration::get_instance()->losers_price);
}

int Player::get_money() { return money; }

void Player::reset_health() {
  set_health(Configuration::get_instance()->starting_health);
}

int Player::get_health() { return health; }

void Player::set_health(int health) {
  this->health = health;
  if (health < Configuration::get_instance()->minimum_health) {
    this->health = Configuration::get_instance()->minimum_health;
  } else if (health > Configuration::get_instance()->starting_health) {
    this->health = Configuration::get_instance()->starting_health;
  }
}

void Player::set_money(int money) {
  this->money = money;
  if (money > Configuration::get_instance()->max_money) {
    this->money = Configuration::get_instance()->max_money;
  } else if (money < Configuration::get_instance()->minimum_money) {
    this->money = Configuration::get_instance()->minimum_money;
  }
}

void Player::set_kill(int kill) { this->kill_number = kill; }

void Player::set_death(int death) { this->death_number = death; }

void Player::set_win_number(int win_number) { this->win_number = win_number; }

void Player::set_lose_number(int lose_number) {
  this->lose_number = lose_number;
}

void Player::set_number_in_team(int number) { number_in_team = number; }

int Player::get_number_in_team() { return number_in_team; }

std::string Player::get_name() { return name; }

std::string Player::get_team_name() { return team_name; }

int Player::get_kill() { return kill_number; }

int Player::get_death() { return death_number; }

int Player::get_win_number() { return win_number; }

int Player::get_lose_number() { return lose_number; }

bool Player::is_alive() {
  if (get_health() == 0) {
    return false;
  } else {
    return true;
  }
}

bool Player::operator==(Player player) {
  if (this->get_name() == player.get_name()) {
    return true;
  } else {
    return false;
  }
}

bool Player::operator==(const Player player) const {
  if (this->name == player.name) {
    return true;
  } else {
    return false;
  }
}

bool Player::operator!=(Player player) {
  if (this->get_name() == player.get_name()) {
    return false;
  } else {
    return true;
  }
}

bool Player::operator!=(const Player player) const {
  if (this->name == player.name) {
    return false;
  } else {
    return true;
  }
}

bool Player::compare(Player p1, Player p2) {
  if (p1.get_kill() > p2.get_kill()) {
    return true;
  } else if (p1.get_kill() == p2.get_kill() &&
             p1.get_death() < p2.get_death()) {
    return true;
  } else if (p1.get_kill() == p2.get_kill() &&
             p1.get_death() == p2.get_death() &&
             p1.get_number_in_team() < p2.get_number_in_team()) {
    return true;
  } else {
    return false;
  }
}

void Player::add_gun(Gun &gun) { ammunition.add_gun(gun); }

Gun &Player::get_gun(std::string gun_type) {
  return ammunition.get_gun(gun_type);
}

bool Player::is_full(std::string gun_type) {
  return ammunition.is_full(gun_type);
}

Player Player::null =
    Player("شمستللمتشمسیتبمتسسمنب منسدمندت", "jffslkjljf", Time(0, 0, 0));