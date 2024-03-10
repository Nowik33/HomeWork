#pragma once
#include<vector>
#include<iostream>
#include"Product.h"

class Shelf
{
	vector<Product*> products;
	int maxCount;
	int countProducts = 0;
public:
	Shelf(){}
	Shelf(int maxCount);
	Shelf(const Shelf& shelf);
	void addProduct(Product* product);
	void showAllProducts();
	Product* getProductByIndex(int index);
};

