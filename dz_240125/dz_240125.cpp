// dz_240125.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/*
- реализовать класс дробь
- числитель и знаменатель хранить в переменных класса
- реализовать методы ввода данных в переменные
- реализовать методы для выполнения операций сложения, вычитания, умножения, деления дробей  
*/
#include <iostream>
using namespace std;

class Drob 
{
    int num{ 1 };
    int denum{ 1 };
public:
    Drob () {}
    Drob(int num, int denum) 
    {
        this->num = num;
        this->denum = denum;
    }
    void show() 
    {
        if (num >= denum)
        {
            cout << num/denum << " " << (num-num/denum)%denum << "/" << denum << endl;
        }
        else
        {
            cout << num << "/" << denum << endl;
        }
    }
    void input()
    {
        cout << "числитель : " << endl;
        cin >> num;
        cout << "знаменатель : " << endl;
        cin >> denum;
        (denum == 0) ? denum = 1 : 1;
    }
    void sum() 
    {
        int num1 = num;
        int denum1 = denum;
        Drob::input();
        cout << num1 << "/" << denum1 << " + " << num << "/" << denum << " = ";
        num =num*denum1+ num1*denum;
        denum = denum*denum1;
        Drob::show();
    }
    void subtruct() 
    {
        int num1 = num;
        int denum1 = denum;
        Drob::input();
        cout << num1 << "/" << denum1 << " - " << num << "/" << denum << " = ";
        num = num * denum1 - num1 * denum;
        denum = denum * denum1;
        Drob::show();
    }
    void mult()
    {
        int num1 = num;
        int denum1 = denum;
        Drob::input();
        cout << num1 << "/" << denum1 << " * " << num << "/" << denum << " = ";
        num = num * num1;
        denum = denum * denum1;
        Drob::show();
    }
    void divide()
    {
        int num1 = num;
        int denum1 = denum;
        Drob::input();
        cout << num1 << "/" << denum1 << " : " << num << "/" << denum << " = ";
        num = num * denum1; num1;
        denum = denum * num1;
        Drob::show();
    }
};

int main()
{
    setlocale(LC_ALL, "");
    Drob db1(3, 5);
    db1.show();
    db1.input();
    db1.show();
    db1.sum();
}

