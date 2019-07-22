//Bai7
#include<iostream>
#include<stdio.h>
using namespace std;

//7.1
#define MAX 100
int a[MAX];
int front, rear;
//7.2
void init(int a[], int &front, int &rear)
{
	front = -1;
	rear = -1;
}
//7.3
int isEmpty()
{
	if(front == -1)
		return 1;
	return 0;
}
//7.4
int isFull()
{
	if(rear - front == MAX - 1)
		return 1;
	return 0;
}
//7.5
int Push(int a[], int &front, int &rear, int x)
{
	if(rear - front == MAX - 1)
		return 0;
	else
	{
		if(front == -1)
			front = 0;
		if(rear == MAX - 1)
		{
			for(int i = front; i <= rear; i++)
				a[i - front] = a[i];
			rear = MAX - 1 - front;
			front = 0;
		}
		a[++rear] = x;
		return 1;
	}
}
//7.6
int Pop(int a[], int &front, int &rear, int &x)
{
	if (front == -1)
		return 0;
	else
	{
		x = a[front++];
		if (front > rear)
		{
			front = - 1;
			rear = -1;
		}
		return 1;
	}
}
int main()
{
	int choice = 0;
	int x, sp, i;
	system("cls");
	cout <<"--------------Bai tap 7 - Chuong 2 -Queue danh sach dac-------------\n";
	cout <<"1.Khoi tao queue rong\n";
	cout <<"2.Kiem tra queue rong\n";
	cout <<"3.Kiem tra queue day\n";
	cout <<"4.Them mot phan tu vao queue\n";
	cout <<"5.Xoa mot phan tu trong queue\n";
	cout <<"6.Thoat\n";
	do
	{
		cout<<"Vui long nhap so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init(a, front, rear);
			cout <<"Khoi danh sach rong thanh cong\n";
			break;
		case 2:
			i = isEmpty();
			if(i == 1)
				cout <<"Queue rong\n";
			else
				cout <<"Queue co phan tu\n";
			break;
		case 3:
			i = isFull();
			if(i == 1)
				cout <<"Queue day\n";
			else
				cout <<"Queue chua day\n";
			break;
		case 4:
			cout <<"Nhap gia tri can them vao Queue: ";
			cin >> x;
			i = Push(a, front, rear, x);
			if(i == 1)
				cout <<"Them phan tu thanh cong\n";
			else
				cout <<"Khong them duoc phan tu\n";
			break;
		case 5:
			cout <<"Nhap gia tri can xoa khoi Queue: ";
			cin >> x;
			i = Pop(a, front, rear, x);
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