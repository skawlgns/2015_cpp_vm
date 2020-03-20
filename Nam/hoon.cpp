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
		
		printf("������������������������������\n");
		printf("��   �� [1] �ݶ�            ��\n");
		printf("��   �� [2] ���̴�          ��\n");
		printf("��   �� [3] ������ �ֽ�     ��\n");
		printf("��   �� [4] ���̴�          �� \n");
		printf("������������������������������\n");
		printf("������������������������������\n");
		printf("��   �� [a] : 100�� ����    ��\n");
		printf("��   �� [s] : 500�� ����    ��\n");
		printf("��   �� [d] : 1000�� ����   ��\n");
		printf("������������������������������\n");
		printf("������������������������������\n");
		printf("��   �� [z] : ���� ��ȯ     ��\n");
		printf("��   �� [x] : ���Ǳ� �ʱ�ȭ ��\n");
		printf("��   �� [c] : ������        ��\n");
		printf("������������������������������\n");

		printf("[ ���� �ݾ� : %d ]\n", coin);
		printf("[ ���� ���� %d ]\n", Sale);
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
			printf("���Ǳ⸦ �ʱ�ȭ �߽��ϴ�.");
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
	if (getNumberDrink(drink) == 0) // ��� ǥ��
		printf("(%s ������ %d��) ", drink->getName(), getNumberDrink(drink), drink->getPrice());
	else
		printf("(%s %d�� %d��) ", drink->getName(), getNumberDrink(drink), drink->getPrice());
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