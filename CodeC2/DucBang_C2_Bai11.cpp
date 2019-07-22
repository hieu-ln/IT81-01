//Bai11
#include<iostream>
#include<stdio.h>
using namespace std;

//11.1
struct Node
{
	int info;
	Node *link;
};
Node *front, *rear;
//11.2
void init()
{
	front = NULL;
	rear = NULL;
}
//11.3
int isEmpty()
{
	if(front == NULL)
		return 1;
	return 0;
}
//11.4
void Push(int x)
{
	Node *p;
	p = new Node;
	p ->info = x;
	p ->link = NULL;
	if(rear == NULL)
		front = p;
	else
		rear ->link = p;
	rear = p;
}
//11.5
int Pop(int &x)
{	
	if(front != NULL)
	{
		Node *p;
		p = front;
		x = p ->info;
		front = front ->link;
		if(front == NULL)
			rear == NULL;
		delete p;
		return x;
	}
	return 0;
}
int main()
{
	int choice = 0;
	int x, sp, i;
	system("cls");
	cout <<"--------------Bai tap 11 - Chuong 2 -Queue danh sach lien ket-------------\n";
	cout <<"1.Khoi tao queue rong\n";
	cout <<"2.Kiem tra queue rong\n";
	cout <<"3.Them mot phan tu vao queue\n";
	cout <<"4.Xoa mot phan tu trong queue\n";
	cout <<"5.Thoat\n";
	do
	{
		cout<<"Vui long nhap so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init();
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
			cout <<"Nhap gia tri can them vao Queue: ";
			cin >> x;
			Push(x);
			if(i == 1)
				cout <<"Them phan tu thanh cong\n";
			else
				cout <<"Khong them duoc phan tu\n";
			break;
		case 4:
			i = Pop(x);
			if(i == x)
				cout <<"Lay thanh cong phan tu " << x <<"\n";
			else
				cout <<"Khong co phan tu nao de xoa\n";
			break;
		case 5:
			cout <<"Goodbye\n";
			break;
		default:
			break;
		}
	}while(choice != 6);
	system("pause");
	return 0;
}