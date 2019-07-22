//Bai10
#include<iostream>
#include<stdio.h>
using namespace std;

//10.1
struct Node
{
	int info;
	Node *link;
};
Node * sp;
//10.2
void init()
{
	sp == NULL;
}
//10.3
int isEmpty()
{
	if (sp == NULL)
		return 1;
	return 0;
}
//10.4
void Push(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}
//10.5
int Pop(int &x)
{
	if(sp!= NULL)
	{
		Node *p = sp;
		x = p -> info;
		sp= p ->link;
		delete p;
		return x;
	}
	return 0;
}
//10.6
void from10to2(int n)
{
	Node *p;
	p = new Node;
	int x;
	while(n != 0)
	{
		x = n % 2;
		Push(x);
		n = n % 2;
	}
	while(isEmpty() == 0)
		cout << Pop(x);
}
int main()
{
	Node *p;
	p = new Node;
	init();
	int x, n;
	cout <<"Nhap n: ";
	cin >> n;
	from10to2(n); 
	cout << endl;
}