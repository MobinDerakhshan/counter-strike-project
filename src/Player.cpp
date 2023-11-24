//
// Created by mobin on 18/09/23.
//

#include "Player.h"
#include "Configuration.h"

Player::Player(std::string name, std::string team_name, int number_in_team,
               const Time &t)
    : name(name), team_name(team_name), number_in_team(number_in_team),
      money(Configuration::get_instance()->starting_money),
      kill_number(Configuration::get_instance()->starting_kill),
      death_number(Configuration::get_instance()->starting_death),
      win_number(Configuration::get_instance()->starting_win_number),
      lose_number(Configuration::get_instance()->starting_lose_number) {
  if (t < Configuration::get_instance()->join_limit) {
    health = Configuration::get_instance()->starting_health;
  } else {
    health = Configuration::get_instance()->minimum_health;
  }
}

void Player::kill_by(gun_type gun_type) {
  int reward = get_gun(gun_type)->kill_reward;
  set_money(get_money() + reward);
  increment_kill();
}

bool Player::attacked(int damage) {
  set_health(get_health() - damage);
  if (!this->is_alive()) {
    die();
      return true;
  }
  else{
      return false;
  }
}

void Player::die() {
  this->ammunition.clear();
  set_death(get_death() + 1);
}

void Player::buy(std::shared_ptr<Weapon> gun) {
  set_money(get_money() - gun->price);
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

int Player::get_money() const { return money; }

void Player::reset_health() {
  set_health(Configuration::get_instance()->starting_health);
}

int Player::get_health() const { return health; }

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

void Player::increment_kill() { this->kill_number += 1; }

void Player::set_death(int death) { this->death_number = death; }

void Player::set_win_number(int win_number) { this->win_number = win_number; }

void Player::set_lose_number(int lose_number) {
  this->lose_number = lose_number;
}

void Player::set_number_in_team(int number) { number_in_team = number; }

int Player::get_number_in_team() const { return number_in_team; }

std::string Player::get_name() const { return name; }

std::string Player::get_team_name() const { return team_name; }

int Player::get_kill() const { return kill_number; }

int Player::get_death() const { return death_number; }

int Player::get_win_number() const { return win_number; }

int Player::get_lose_number() const { return lose_number; }

bool Player::is_alive() const {
  if (get_health() == 0) {
    return false;
  } else {
    return true;
  }
}

bool Player::operator==(const Player &player) const {
  if (this->get_name() == player.get_name()) {
    return true;
  } else {
    return false;
  }
}

bool Player::operator!=(const Player &player) const {
  if (this->get_name() == player.get_name()) {
    return false;
  } else {
    return true;
  }
}

bool Player::compare(const Player &p1, const Player &p2) {
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

void Player::add_gun(std::shared_ptr<Weapon> &gun) { ammunition.add_gun(gun); }

std::shared_ptr<Weapon> Player::get_gun(gun_type gun_type) {
  return ammunition.get_gun(gun_type);
}

bool Player::is_full(gun_type gun_type) { return ammunition.is_full(gun_type); }
