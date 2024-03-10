#pragma once
#include "Product.h"

class Milk : public Product
{
private:
	static std::string img;
public:
	Milk(std::string name);
};

class Fish : public Product
{
private:
	static std::string img;
public:
	Fish(std::string name);
};

class Meet : public Product
{
private:
	static std::string img;
public:
	Meet(std::string name);
};
