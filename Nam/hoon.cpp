#include <stdio.h>
#include <CoreWindow.h>
#include "cCola.h"
#include "cSida.h"
#include "cJuice.h"
#include "cFanta.h"
#include "Drink.h"

#define MAX_DRINKS	20

void init();
void viewDrink(Drink *drink);
int	 getNumberDrink(Drink *drink);
void buyDrink(Drink *drink);

int Sale = 0;
int coin = 0;
Drink *Cola = new cCola[MAX_DRINKS];
Drink *Sida = new cSida[MAX_DRINKS];
Drink *Juice = new cJuice[MAX_DRINKS];
Drink *Fanta = new cFanta[MAX_DRINKS];

int main(void)
{

	int order = 0;

	init();

	while (1) 
	{
		system("cls");
		printf("");
		viewDrink(Cola);
		printf("\n");
		viewDrink(Sida);
		printf("\n");
		viewDrink(Juice);
		printf("\n");
		viewDrink(Fanta);
		printf("\n");
		
		printf("┌─────────────┐\n");
		printf("│   ☞ [1] 콜라            │\n");
		printf("│   ☞ [2] 사이다          │\n");
		printf("│   ☞ [3] 오렌지 주스     │\n");
		printf("│   ☞ [4] 사이다          │ \n");
		printf("└─────────────┘\n");
		printf("┌─────────────┐\n");
		printf("│   ☞ [a] : 100원 투입    │\n");
		printf("│   ☞ [s] : 500원 투입    │\n");
		printf("│   ☞ [d] : 1000원 투입   │\n");
		printf("└─────────────┘\n");
		printf("┌─────────────┐\n");
		printf("│   ☞ [z] : 동전 반환     │\n");
		printf("│   ☞ [x] : 자판기 초기화 │\n");
		printf("│   ☞ [c] : 떠나기        │\n");
		printf("└─────────────┘\n");

		printf("[ 투입 금액 : %d ]\n", coin);
		printf("[ 현재 매출 %d ]\n", Sale);
		scanf("%s", &order);
	
		switch (order) 
		{
		case '1':
			buyDrink(Cola);
			break;
		case '2':
			buyDrink(Sida);
			break;
		case '3':
			buyDrink(Juice);
			break;
		case '4':
			buyDrink(Fanta);
			break;
		case 'a':
			coin += 100;
			break;
		case 's':
			coin += 500;
			break;
		case 'd':
			coin += 1000;
			break;
		case 'z':
			coin = 0;
			break;
		case 'x':
			init();
			printf("자판기를 초기화 했습니다.");
			break;
		case 'c':
			exit(1);
			break;
		default:
			break;
		}
	}

	return 0;
}

void	init()
{
	Sale = 0;
	coin = 0;
	for (int i = 0; i < MAX_DRINKS; i++) 
	{
		Cola[i].init();
		Sida[i].init();
		Juice[i].init();
		Fanta[i].init();
	}
}

void	viewDrink(Drink *drink)
{
	if (getNumberDrink(drink) == 0) // 재고 표시
		printf("(%s 재고없음 %d원) ", drink->getName(), getNumberDrink(drink), drink->getPrice());
	else
		printf("(%s %d개 %d원) ", drink->getName(), getNumberDrink(drink), drink->getPrice());
}

int getNumberDrink(Drink *drink) 
{
	int Num = 0;
	for (int i = 0; i < MAX_DRINKS; i++) 
	{
		if (drink[i].isExist()) {
			Num++;
		}
	}
	return Num;
}

void	buyDrink(Drink *drink) 
{
	for (int i = 0; i < MAX_DRINKS; i++) 
	{
		if (drink[i].isExist()) {
			drink[i].buy(&Sale, &coin);
			break;
		}
	}
}