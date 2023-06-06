/**
* @file             ArrayList.cpp
* @description      Büyük tamsayı sınıfı uygulaması
* @course           c++
* @assignment       c++
* @date             6 Ağustos 2022 Cumartesi
* @author           Mahmoud Aabdolla
*/

#include <iostream>
#include <string.h>
#include "../include/ArrayList.h"
using namespace std;

ArrayList::ArrayList(unsigned long long number)
{
  do{
    digits.push_back(number % 10);
    number /= 10;
  } while (number);
}
ArrayList::ArrayList(const char *c)
{
  digits = "";
  for (int i = strlen(c) - 1; i >= 0;i--)
  {
    if(!isdigit(c[i]))
      throw("ERROR");
    digits.push_back(c[i] - '0');
  }
}
bool IsNull(const ArrayList& a)
{
  if(a.digits.size() == 1 && a.digits[0] == 0)
    return true;
  return false;
}
ArrayList &operator+=(ArrayList &a,const ArrayList& b)
{
  int t = 0, s, i;
  int n = a.digits.size(), m = b.digits.size();
  if(m > n)
    a.digits.append(m - n, 0);
  n = a.digits.size();
  for (i = 0; i < n;i++){
    if(i < m)
      s = (a.digits[i] + b.digits[i]) + t;
    else
      s = a.digits[i] + t;
    t = s / 10;
    a.digits[i] = (s % 10);
  }
  if(t)
    a.digits.push_back(t);
  return a;
}
ArrayList operator+(const ArrayList &a, const ArrayList &b)
{
  ArrayList temp;
  temp = a;
  temp += b;
  return temp;
}
ArrayList &operator*=(ArrayList &a, const ArrayList &b)
{
  if(IsNull(a) || IsNull(b)){
    a = ArrayList();
    return a;
  }
  int n = a.digits.size(), m = b.digits.size();
  int *v = new int[n + m]();
  for (int i = 0; i < n;i++)
    for (int j = 0; j < m;j++){
      v[i + j] += (a.digits[i] ) * (b.digits[j]);
    }
  n += m;
  a.digits.resize(n + m - 1);
  for (int s, i = 0, t = 0; i < n; i++)
  {
    s = t + v[i];
    v[i] = s % 10;
    t = s / 10;
    a.digits[i] = v[i] ;
  }
  for (int i = n - 1; i >= 1 && !v[i];i--)
    a.digits.pop_back();
  delete[] v;
  return a;
}
ArrayList operator*(const ArrayList&a,const ArrayList&b){
  ArrayList tmp;
  tmp = a;
  tmp *= b;
  return tmp;
}

string ArrayList::ToString() {
  string value;
  for (int i = digits.size() - 1; i >= 0;i--) {
    value.append(to_string((short) digits[i]));
  }
  return value;
}
