#pragma once
#include <string.h>

class Drink
{
private:
	int	 price;
	char name[20];
	bool bExist;

public:
	virtual void init() = 0;

protected:
	void init(char tmp_name[20], int tmp_price);

public:
	void buy(int* sale, int* coin);

public:
	bool isExist() { return bExist; }
	int	 getPrice() { return price; }
	char* getName() { return name; }

public:
	Drink();
	~Drink();
};

