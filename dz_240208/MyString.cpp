#include "MyString.h"

MyString::MyString(const char arr[])
{
	size = 0;
	for (int i = 0; arr[i] != '\0'; i++) size++;
	str = new char[size + 1];
	for (int i = 0; i < size + 1; i++) str[i] = arr[i];
}
void MyString::operator=(const char arr[])
{
	if (size > 0) delete[] str;
	size = 0;
	for (int i = 0; arr[i] != '\0'; i++) size++;
	str = new char[size + 1];
	for (int i = 0; i < size + 1; i++) str[i] = arr[i];
}
void MyString::show()
{
	if (size > 0)
		std::cout << str << std::endl;
}
bool MyString::empty()
{
	return !size;
}
int MyString::compare(const char arr[])
{
	for (int i = 0; i <= size; i++) {
		if (str[i] > arr[i]) return 1;
		else if (str[i] < arr[i]) return -1;
	}
	return 0;
}
int MyString::stoi(const char arr[])
{
	int num = 0;
	int m = (arr[0] == '-') ? 1 : 0;
	for (int i = 0 + m; arr[i] != '\0'; i++) {
		if (arr[i] >= '0' && arr[i] <= '9') {
			num = num * 10 + (arr[i] - 48);
		}
		else return NULL;
	}
	if (m == 1) num *= -1;
	return num;
}
int MyString::find(const char arr[])
{
	int j = 0;
	for(int i=0;i<size;i++)
	{
		if (str[i]==arr[j])
		{
			while (i<size and arr[j]!='\0')
			{
				if(str[i] != arr[j]) 
				{
					j = 0;
					break;
				}
				i++;
				j++;
			}
		}
		if (str[i-1] == arr[j-1] and arr[j] == '\0') return i - j;
	}
	return -1;
}
int MyString::rfind(const char arr[])
{
	int arrSize = 0;
	for (int i = 0; arr[i] != '\0'; i++) arrSize++;
	int j = arrSize-1;
	for (int i = size-1; i >=0; i--)
	{
		if (str[i] == arr[j])
		{
			while (i >= 0 and j>= 0)
			{
				if (str[i] != arr[j])
				{
					j = arrSize - 1;
					break;
				}
				i--;
				j--;
			}
		}
		if (str[i+1] == arr[j+1] and (j+1) == 0) return i+2;
	}
	return -1;
}
void MyString::replace(const char arr[], int pozition)
{
	int arrSize = 0;
	for (int i = 0; arr[i] != '\0'; i++) arrSize++;
	if (size<=arrSize+pozition) 
	{
		char* buf = new char[arrSize + pozition+ 1];
		for (int i = 0; i < pozition; i++)
		{
			buf[i] = str[i];
		}
		for (int i = pozition, j =0; j < arrSize + 1; i++, j++)
		{
			buf[i] = arr[j];
		}
		delete[]str;
		str = buf;
		size = arrSize+pozition;
	}
	if (size > arrSize+pozition)
	{
		char* buf = new char[size + 1];
		for (int i = 0; i < pozition; i++)
		{
			buf[i] = str[i];
		}
		for (int i = pozition, j = 0; j < arrSize; i++, j++)
		{
			buf[i] = arr[j];
		}
		for (int i = pozition+arrSize; i < size+1; i++)
		{
			buf[i] = str[i];
		}

		delete[]str;
		str = buf;
	}
}
void MyString::append(const char arr[])
{
	int arrSize = 0;
	for (int i = 0; arr[i] != '\0'; i++) arrSize++;
	char* buf = new char[arrSize + size + 1];
	for (int i=0; i<size;i++) 
	{
		buf[i] = str[i];
	}
	for (int i = 0; i <= arrSize; i++)
	{
		buf[size+i] = arr[i];
	}
	delete[]str;
	str = buf;
	size += arrSize;
}
void MyString::clear()
{
	delete[] str;
	size = 0;
}

