/**
* @file             main.cpp
* @description      Uygulama ana girişi
* @course           c++
* @assignment       c++
* @date             6 Ağustos 2022 Cumartesi
* @author           Mahmoud Alabdolla
*/

#include <iostream>
#include "../include/getAnswer.h"

using namespace std;

int main() {
  int number;
  cout << "Numara: ";
  cin >> number;
  getAnswer(number);
  return 0;
}
