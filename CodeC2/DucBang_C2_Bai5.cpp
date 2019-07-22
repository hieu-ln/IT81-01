//Bai5
#include<iostream>
#include<stdio.h>
using namespace std;

//5.1
# define MAX 100
int a[MAX];
int n;
//5.2
void init(int a[], int &sp)
{
	sp = -1;
}
//5.3
int isEmpty(int a[], int sp)
{
	if(sp == -1)
		return 1;
	return 0;
}
//5.4
int isFull(int a[], int sp)
{
	if(sp == MAX - 1)
		return 1;
	return 0;
}
//5.5
int Push(int a[], int &sp, int x)
{
	if(sp < MAX - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}
//5.6
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
	int choice = 0;
	int x, sp, i;
	system("cls");
	cout <<"--------------Bai tap 5 - Chuong 2 -Stack danh sach dac-------------\n";
	cout <<"1.Khoi tao stack rong\n";
	cout <<"2.Kiem tra stack rong\n";
	cout <<"3.Kiem tra stack day\n";
	cout <<"4.Them mot phan tu vao stack\n";
	cout <<"5.Xoa mot phan tu trong stack\n";
	cout <<"6.Thoat\n";
	do
	{
		cout<<"Vui long nhap so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init(a, sp);
			cout <<"Khoi danh sach rong thanh cong\n";
			break;
		case 2:
			i = isEmpty(a, n);
			if(i == 1)
				cout <<"Stack rong\n";
			else
				cout <<"Stack co phan tu\n";
			break;
		case 3:
			i = isFull(a, n);
			if(i == 1)
				cout <<"Stack day\n";
			else
				cout <<"Stack chua day\n";
			break;
		case 4:
			cout <<"Nhap gia tri can them vao stack: ";
			cin >> x;
			i = Push(a, sp, x);
			if(i == 1)
				cout <<"Them phan tu thanh cong\n";
			else
				cout <<"Khong them duoc phan tu\n";
			break;
		case 5:
			i = Pop(a, sp, x);
			if(i == 1)
				cout <<"Xoa thanh cong phan tu\n";
			else
				cout <<"Khong co phan tu nao de xoa\n";
			break;
		case 6:
			cout <<"Goodbye\n";
			break;
		default:
			break;
		}
	}while(choice != 7);
	system("pause");
	return 0;
}