/**
* @file             getAnswer.cpp
* @description      Cevabı al ve bir dosyaya yaz
* @course           c++
* @assignment       c++
* @date             6 Ağustos 2022 Cumartesi
* @author           Mahmoud Alabdolla
*/

#include <iostream>
#include <fstream>
#include "../include/ArrayList.h"

using namespace std;

void writeTo(const char* fileName, const string& contents) {
  ofstream File(fileName);
  File << contents;
  File.close();
}

void getAnswer(const int& number) {
  ArrayList total(number);
  for (int i = number - 1; i > 0; i--) {
    ArrayList sum("0");
    for (const char j: to_string(i)) {
      int num = (int) j - 48;
      sum += total * num;
    }
    total = sum;
  }
  writeTo("Sonuc.txt", total.ToString());
}
