//Bai6
#include<iostream>
#include<stdio.h>
using namespace std;


# define MAX 100
int a[MAX];
int sp;

void init(int a[], int &sp)
{
	sp = -1;
}

int isEmpty(int a[], int sp)
{
	if(sp == -1)
		return 1;
	return 0;
}

int isFull(int a[], int sp)
{
	if(sp == MAX - 1)
		return 1;
	return 0;
}

int Push(int a[], int &sp, int x)
{
	if(sp < MAX - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}

int Pop(int a[], int &sp, int x)
{
	if(sp != -1)
	{
		x = a[sp--];
		return x;
	}
	return 0;
}
int main()
{
	int x, sp, i, z, choice;
	system("cls");
	cout <<"--------------Bai tap 6 - Chuong 2 -Doi he 10 sang he 2-------------\n";
	cout <<"1. Doi he 2 sang he 10\n";
	cout <<"2. Thoat\n";
	do{
		cout <<"Chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init(a, sp);
			do{
				cout <<"Nhap so he thap phan can chuyen: ";
				cin >> x;
			}while(x <= 0);
			while(x != 0)
			{
				i = x % 2;
				z = Push(a, sp, i);
				x = x/2;
			}
			cout <<"So nhi phan la: ";
			while(isEmpty(a, sp) == 0)
				cout << Pop(a, sp, i);
			cout << endl;
			break;
		case 2:
			cout <<"Goodbye\n";
			break;
		default:
			cout <<"Nhap sai. Hay nhap lai: ";
			break;
		}
	}while(choice == 1);
	return 0;
}