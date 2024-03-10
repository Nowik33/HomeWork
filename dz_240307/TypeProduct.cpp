#include "TypeProduct.h"

Milk::Milk(string name):Product(name) 
{
	type = "milk";
}
string Milk::img = "milk.png";

Fish::Fish(string name):Product(name)
{
	type = "fish";
}
string Fish::img = "fish.png";

Meet::Meet(string name) :Product(name)
{
	type = "meet";
}
string Meet::img = "meet.png";