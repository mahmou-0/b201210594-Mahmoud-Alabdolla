#pragma once

#include <iostream>

class ArrayList{
  std::string digits;
public:
  ArrayList(unsigned long long number = 0);
  ArrayList(const char *);
  ArrayList(ArrayList &);


  friend bool IsNull(const ArrayList &);

  friend ArrayList &operator+=(ArrayList &, const ArrayList &);
  friend ArrayList operator+(const ArrayList &, const ArrayList &);
  friend ArrayList &operator*=(ArrayList &, const ArrayList &);
  friend ArrayList operator*(const ArrayList &, const ArrayList &);

  std::string ToString();
};
