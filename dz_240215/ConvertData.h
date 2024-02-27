#pragma once
#include<string>
#include<iostream>
class ConvertData
{
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int secunde;
public:
	ConvertData(std::string data);
	void show();
};

