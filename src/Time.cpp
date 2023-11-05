//
// Created by mobin on 18/09/23.
//

#include "Time.h"

Time::Time(int mm, int ss, int ttt) {
  this->mm = mm;
  this->ss = ss;
  this->ttt = ttt;
}

void Time::set(int mm, int ss, int ttt) {
  this->mm = mm;
  this->ss = ss;
  this->ttt = ttt;
}

bool Time::operator<(Time t1) {
  if (this->mm < t1.mm) {
    return true;
  } else if (this->mm == t1.mm && this->ss < t1.ss) {
    return true;
  } else if (this->mm == t1.mm && this->ss == t1.ss && this->ttt < t1.ttt) {
    return true;
  } else {
    return false;
  }
}

bool Time::operator<=(Time t1) {
  if (this->mm < t1.mm) {
    return true;
  } else if (this->mm == t1.mm && this->ss < t1.ss) {
    return true;
  } else if (this->mm == t1.mm && this->ss == t1.ss && this->ttt <= t1.ttt) {
    return true;
  } else {
    return false;
  }
}

bool Time::operator<(Time t1) const {
  if (this->mm < t1.mm) {
    return true;
  } else if (this->mm == t1.mm && this->ss < t1.ss) {
    return true;
  } else if (this->mm == t1.mm && this->ss == t1.ss && this->ttt < t1.ttt) {
    return true;
  } else {
    return false;
  }
}

bool Time::operator==(const Time &t1) const {
  if (this->mm == t1.mm && this->ss == t1.ss && this->ttt == t1.ttt) {
    return true;
  } else {
    return false;
  }
}

bool Time::operator<=(Time t1) const {
  if (this->mm < t1.mm) {
    return true;
  } else if (this->mm == t1.mm && this->ss < t1.ss) {
    return true;
  } else if (this->mm == t1.mm && this->ss == t1.ss && this->ttt <= t1.ttt) {
    return true;
  } else {
    return false;
  }
}

std::istream &operator>>(std::istream &in, Time &time) {

  std::string time_str;
  std::cin >> time_str;

  std::string minutes, seconds, milliseconds;
  std::stringstream time_stream(time_str);

  std::getline(time_stream, minutes, ':');
  std::getline(time_stream, seconds, ':');
  std::getline(time_stream, milliseconds);

  time.set(stoi(minutes), stoi(seconds), stoi(milliseconds));
}
