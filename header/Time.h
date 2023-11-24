//
// Created by mobin on 18/09/23.
//

#ifndef P_TIME_H
#define P_TIME_H
#include <iostream>
#include <sstream>

class Time {
public:
  Time(int mm, int ss, int ttt);
  void set(int, int, int);
  bool operator<(const Time &t1) const;
  bool operator<=(const Time &t1) const;
  bool operator==(const Time &t1) const;
  friend void operator>>(std::istream &in, Time &time);

private:
  int minute, second, millisecond;
};

#endif // P_TIME_H
