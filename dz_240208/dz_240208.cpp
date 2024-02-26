// dz_240208.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//--  char* arr;
//--int size;

//--constructor(const char[])
//--  operator = (const char[])

//--show-- empty--compare-stoi--find--rfind--replace--append--clear;

#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
    MyString str("Morton1923");
    str.show();
    MyString str1 = "Maus1923";
    str1.show();
    cout << str.empty()<<endl;
    cout << str.compare("Morton") << "  " << str.compare("Morton1923") << endl;
    cout << MyString::stoi("-99") << "  " << MyString::stoi("0") << "  " << MyString::stoi("99") << endl;
    cout << str.find("ton") << "  " << str.find("Maus") << endl;
    cout << str.rfind("ton") << "  " << str.rfind("Maus") << endl;
    str.replace("KCMorton1923", 6);
    str.show();
    str.replace(" Maus   ", 6);
    str.show();
    str.append(" Klaus");
    str.show();
    str.clear();
}