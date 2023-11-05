//
// Created by mobin on 18/09/23.
//

#include "../header/Time.h"
//#include <sstream>

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
/*
int m, s, t;
scanf("%d:%d:%d", &m, &s, &t);
time.set(m, s, t);
*/

/*	std::string time_str;
                std::cin >> time_str;

    std::string minutes, seconds, milliseconds;
    std::stringstream time_stream(time_str);

    std::getline(time_stream, minutes, ':');
    std::getline(time_stream, seconds, ':');
    std::getline(time_stream, milliseconds);

    time.set(stoi(minutes), stoi(seconds), stoi(milliseconds));
*/
/*char colon; // to store the colons between hours, minutes, and seconds
    int hours, minutes, seconds;
    std::cin >> hours >> colon >> minutes >> colon >> seconds; // Read input in
   the format "hh:mm:ss" time.set(hours, minutes, seconds); std::cout <<
   hours<<" "<< minutes<< " " << seconds<<"\n"; return in;*/