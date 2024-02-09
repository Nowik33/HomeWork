// dz_240202.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

//Дополнить программу с машинами следующими пунктами.
//Реализовать класс гараж.В который можно добавлять машины и убирать их.
//У машины должен быть уникальный идентификатор
//(номер машины(достаточно генерировать трехзначное число уникальное))

#include <iostream>
#include <string>

using namespace std;

class Car
{
	string model;
	string color;
	string vengine;
	string regnum;
	static int num;
	int uniqId = 0;
public:
	Car() {}
	Car( string color, string model, string vengine)
	{
		this->color = color;
		this->model = model;
		this->vengine = vengine;
		if (num < 10) regnum = "00" + to_string(num++);
		if (num < 100 and num > 9) regnum = "0" + to_string(num++);
		if (num > 99) regnum = to_string(num++);
	}

	void show()
	{
		cout << uniqId << "\t" << model << "\t" << color << "\t" << vengine << "\t" << regnum << endl;
	}

	void changeUniqId(int z) 
	{
		uniqId = z;
	}
};

int Car::num = 0;

class Garage
{
	static int id;
	int coun =0;
	Car* arrayCar = new Car[coun];
public:
	Garage() {}
	void addCar(Car x)
	{
		x.changeUniqId(id);
		Car* buf = new Car[coun+1];
		for (int i = 0; i < coun; i++) buf[i] = arrayCar[i];
		buf[coun] = x; 
		delete[]arrayCar;
		arrayCar = buf;
		coun++;
		id++;
	}
	void removeCar(int ind) 
	{
		if (ind<0 or ind>coun - 1)  return;
		Car* buf = new Car[coun - 1];
		for (int i = 0; i < ind; i++) buf[i] = arrayCar[i];
		for (int i=ind+1; i < coun; i++) buf[i-1] = arrayCar[i];
		delete[]arrayCar;
		arrayCar = buf;
		coun--;
	}
	void showCar() 
	{
		cout << endl;
		cout << "В гараже " << endl;
		cout << "================================================" << endl;
		cout << "uniqId" << "\t" << "model" << "\t" << "color" << "\t\t" << "vengine" << "\t" << "regnum" << endl;
		cout << "================================================" << endl;
		for (int i = 0; i< coun; i++) arrayCar[i].show();
	}
};

int Garage::id = 1;

int main()
{
	setlocale(LC_ALL, "");
	Car a0("black   ", "mazda6", "2L");
	Car a1("red     ", "mazda6", "2L");
	Car a2("white   ", "mazda6", "1.6L");
	Car a3("metallic", "mazda6", "1.6L");

	Car arr[] = {a0,a1,a2,a3};
	for (int i=0; i<4;i++) 
	{
		arr[i].show();
	}

	Garage g;
	g.addCar(arr[0]);
	g.showCar();
	g.addCar(arr[1]);
	g.showCar();
	g.addCar(arr[2]);
	g.showCar();
	g.addCar(arr[3]);
	g.showCar();
	cout << endl;
	g.removeCar(0);
	g.showCar();
	g.removeCar(2);
	g.showCar();
	cout << endl;
}

