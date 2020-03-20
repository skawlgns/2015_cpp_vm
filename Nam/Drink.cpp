#include "Drink.h"
#include <stdio.h>
void Drink::init(char tmp_name[20], int tmp_price)
{
	strcpy(name, tmp_name);
	price = tmp_price;
	bExist = true;
}

void Drink::buy(int* sale, int* coin)
{
	if (*coin > price) {
		*sale += price;
		*coin -= price;
		bExist = false;
	}
}

Drink::Drink()
{
}


Drink::~Drink()
{
}
