// dz_240124.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Необходимо создать класс автомобиль.
//У авто есть цена, цвет, модель, объем двигателя.
//Создать конструктор со всем параметрами, все методы аксессоры и мутаторы.
//Реализовать метод show() выводящий всю информацию о машине.
//Сделать 4 разные машины.Проверить все методы.
#include <iostream>

using namespace std;

class Car
{
private:
	int price;
	string color;
	string model;
	string vengine;
public:
	Car() {}
	Car(int price, string color, string model, string vengine)
	{
		this->price = price;
		this->color = color;
		this->model = model;
		this->vengine = vengine;
	}
	void show() 
	{
		cout << model << "\t" << color << "\t" << vengine << "\t" << price << endl;
	}
	void changeprice(int pr) 
	{
		price = pr;
	}
	int getprice() 
	{
		return price;
	}
};


int main()
{
	setlocale(LC_ALL, "");
	Car a1(10000, "black   ", "mazda6", "2L");
	Car a2(10000, "red     ", "mazda6", "2L");
	Car a3(10000, "white   ", "mazda6", "1.6L");
	Car a4(10000, "metallic", "mazda6", "1.6L");

	int size = 4;
	Car arr[] {a1,a2,a3,a4};
			
	cout << endl;
	cout << "Прайс лист на автомобили" << endl;
	cout << "======================================" << endl;
	for (int i = 0; i < size; i++)
	{
		arr[i].show();
	}

	cout << a1.getprice() << endl;
	//a1.price = 6000; //private!
	arr[2].changeprice(6000);
	arr[3].changeprice(6000);

	cout << endl;
	cout << "Новый прайс лист на автомобили" << endl;
	cout << "======================================" << endl;
	for (int i = 0; i < size; i++)
	{
		arr[i].show();
	}
}

