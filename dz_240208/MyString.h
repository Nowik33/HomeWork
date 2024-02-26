#pragma once
#include <iostream>
class MyString
{
private:
	char* str;
	int size;

public:
	MyString(const char arr[]);
	void operator=(const char arr[]);
	void show();
	bool empty();
	int compare(const char arr[]);
	static int stoi(const char arr[]);
	int find(const char arr[]);
	int rfind(const char arr[]);
	void replace(const char arr[], int pozition);
	void append(const char arr[]);
	void clear();
};


