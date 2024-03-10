#include "Fridge.h"
#include "Shelf.h"
#include"Product.h"
#include "TypeProduct.h"

Fridge::Fridge(int maxCountShelf) 
{
	this->maxCountShelf = maxCountShelf;
}

void Fridge::addProductInFridge(Shelf stype)
{
	for (int i =0; i<maxCountShelf; i++ ) 
	{
		Shelf* buf = new Shelf(stype);
		fridgeShelf.push_back(buf);
		countShelf++;
	}
}

void Fridge::showAllProductOffFridge()
{
	for (int i = 0; i < countShelf; i++)
	{
		cout << "Shelf : " << i+1 << endl;
		cout << "===================" << endl;
		fridgeShelf[i]->showAllProducts();
	}
	cout << endl;
}

void Fridge::getProductFromFridge(int fridgeShelfIndex, int index)
{
	fridgeShelf[fridgeShelfIndex]->getProductByIndex(index);
}