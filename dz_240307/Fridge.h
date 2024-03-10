#pragma once
#include "Shelf.h"
#include<vector>

class Fridge
{
	int countShelf=0;
	int maxCountShelf=0;
	std::vector<Shelf*> fridgeShelf;

public:
	Fridge(int maxCountShelf);
	void addProductInFridge(Shelf stype);
	void getProductFromFridge(int fridgeShelfIndex, int index);
	void showAllProductOffFridge();
};