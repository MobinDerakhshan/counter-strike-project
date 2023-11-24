//
// Created by mobin on 18/09/23.
//

#include "Time.h"

Time::Time(int mm, int ss, int ttt) {
  this->minute = mm;
  this->second = ss;
  this->millisecond = ttt;
}

void Time::set(int mm, int ss, int ttt) {
  this->minute = mm;
  this->second = ss;
  this->millisecond = ttt;
}

bool Time::operator<(const Time &t1) const {
  if (this->minute < t1.minute) {
    return true;
  } else if (this->minute == t1.minute && this->second < t1.second) {
    return true;
  } else if (this->minute == t1.minute && this->second == t1.second && this->millisecond < t1.millisecond) {
    return true;
  } else {
    return false;
  }
}

bool Time::operator==(const Time &t1) const {
  if (this->minute == t1.minute && this->second == t1.second && this->millisecond == t1.millisecond) {
    return true;
  } else {
    return false;
  }
}

bool Time::operator<=(const Time &t1) const {
  if (this->minute < t1.minute) {
    return true;
  } else if (this->minute == t1.minute && this->second < t1.second) {
    return true;
  } else if (this->minute == t1.minute && this->second == t1.second && this->millisecond <= t1.millisecond) {
    return true;
  } else {
    return false;
  }
}

void operator>>(std::istream &in, Time &time) {

  std::string time_str;
  std::cin >> time_str;

  std::string minutes, seconds, milliseconds;
  std::stringstream time_stream(time_str);

  std::getline(time_stream, minutes, ':');
  std::getline(time_stream, seconds, ':');
  std::getline(time_stream, milliseconds);

  time.set(stoi(minutes), stoi(seconds), stoi(milliseconds));
}
