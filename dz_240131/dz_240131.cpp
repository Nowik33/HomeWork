// dz_240131.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/*
Напишите класс - конвертер валюты.
Умеет работать с RUB DOL EUR
Берем текущий курс
*/
#include <iostream>
#include <iomanip>
using namespace std;

class Converter 
{
    double rub;
    double usd;
    double eur;
public:
    Converter (double rub, double usd,double eur) 
    {
        this->rub = rub;
        this->usd = usd;
        this->eur = eur;
    }
    void show()
    {
        cout << "===============================" << endl;
        cout << "сумма USD : " << fixed << setprecision(2) << rub / usd << endl;
        cout << "сумма EUR : " << fixed << setprecision(2) << rub / eur << endl;
    }
};

int main()
{
    setlocale(LC_ALL,"");
    double vusd = 0;
    double veur = 0;
    double vrub = 0;
    cout << "ВВОД КУРСОВЫХ ЗНАЧЕНИЙ USD, EUR" << endl;
    cout << "НА СЕГОДНЯ ПО ДАННЫМ ЦБ РФ" << endl; 
    cout << "===============================" << endl;
    cout << "Курс USD : ";
    cin >> vusd;
    cout << "Курс EUR : ";
    cin >> veur;
    cout << "Сумма RUB : ";
    cin >> vrub;
    Converter cv(vrub, vusd, veur);
    cv.show();
}

