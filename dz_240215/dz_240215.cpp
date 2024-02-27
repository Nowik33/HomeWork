// dz_240215.cpp : 
//Напишите класс, который будет получать строку в виде
//2020 - 05 - 12T23:50 : 21.817Z
//и преобразовать в поля объекта DateTime
//в котором поля это
//год день месяц часы минуты секунды

#include <iostream>
#include "ConvertData.h"
using namespace std;

int main()
{
	string inputData{ "2020-05-12T23:50:21.817Z" };
	ConvertData dateTime(inputData);
	dateTime.show();
}

