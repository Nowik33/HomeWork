#include "ConvertData.h"
ConvertData::ConvertData(std::string data)
{
	year = stoi(data.substr(0, 4));
	month = stoi(data.substr(6, 7));
	day = stoi(data.substr(8, 9));
	hour = stoi(data.substr(11, 12));
	minute= stoi(data.substr(14, 15));
	secunde = stoi(data.substr(17, 18));
}
void ConvertData::show()
{
	std::cout << "Year   :" << year << std::endl;
	std::cout << "Month  :" << month << std::endl;
	std::cout << "Day    :" << day << std::endl;
	std::cout << "Hour   :" << hour << std::endl;
	std::cout << "Minute :" << minute << std::endl;
	std::cout << "Secunde:" << secunde << std::endl;
}

