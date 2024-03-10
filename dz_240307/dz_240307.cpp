// dz_240307.cpp : 
//реализовать:
//добавление продуктов в холодильник, который состоит из нескольких полок
//Реализовать возможность получение продуктов с
//конкретной полки конкретной позиции.
//Учесть что если мето на полке нет, берем следующую полку
//#include <iostream>
#include<iostream>
#include<vector>

using namespace std;
#define random(a,b) a+rand()%(b+1-a)

#include "Product.h"
#include "TypeProduct.h"
#include "Shelf.h"
#include "Fridge.h"

string names[] = { "GlavProduct","AgroComplex","PioneerBread","CortevaAgriciens" };

int main()
{
    srand(time(NULL));
    
    int maxCountShelf = 3;
    int maxPlaсeShelf = 6;
    
    Shelf shelf1(maxPlaсeShelf);
    for (int i = 0; i < 2; i++) 
    {
        shelf1.addProduct(new Milk(names[random(0, 3)]));
    }
    for (int i = 0; i < 2; i++)
    {
        shelf1.addProduct(new Meet(names[random(0, 3)]));
    }
    for (int i = 0; i < 2; i++)
    {
        shelf1.addProduct(new Fish(names[random(0, 3)]));
    }
    /*shelf1.showAllProducts();
    cout << "============" << endl;*/
    
    Fridge fr(maxCountShelf);
    fr.addProductInFridge(shelf1);
    fr.showAllProductOffFridge();
    fr.getProductFromFridge(1,3);
    fr.showAllProductOffFridge();
}
