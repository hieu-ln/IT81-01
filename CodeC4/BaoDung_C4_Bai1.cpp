#include <iostream>
#include <stdio.h>
using namespace std;
#define COUNT 10

struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node *root;

void Init()
{
	root = NULL;
}

void InsertNode(Node *&p, int x)
{
	if (p == NULL)
	{
		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if (p->info == x)
			return;
		else
			if (p->info > x)
				return InsertNode(p->left, x);
			else
				return InsertNode(p->right, x);
	}
}

Node *search(Node *p, int x)
{
	while (p != NULL)
	{
		if (p->info == x)
			return p;
		else
			if (p->info > x)
				return search(p->left, x);
			else
				return search(p->right, x);
	}
}

void searchStandFor(Node *&p, Node *&q)
{
	if (q->left == NULL)
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		searchStandFor(p, q->left);
}

int Delete(Node *&T, int x)
{
	if (T == NULL)
		return 0;
	if (T->info == x)
	{
		Node *p = T;
		if (T->left == NULL)
			T = T->right;
		else
			if (T->right == NULL)
				T = T->left;
			else
				searchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if (T->info < x)
		return Delete(T->right, x);
	if (T->info > x)
		return Delete(T->left, x);
}

void DuyetNLR(Node *p)
{
	if (p != NULL)
	{
		cout << p->info << " ";
		DuyetNLR(p->left);
		DuyetNLR(p->right);
	}
}

void DuyetLNR(Node *p)
{
	if (p != NULL)
	{
		DuyetLNR(p->left);
		cout << p->info << " ";
		DuyetLNR(p->right);
	}
}

void DuyetLRN(Node *p)
{
	if (p != NULL)
	{
		DuyetLRN(p->left);
		DuyetLRN(p->right);
		cout << p->info << " ";
	}
}

void print2DUtil(Node *p, int space)
{
	if (p == NULL)
		return;
	space += COUNT;
	print2DUtil(p->right, space);
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->info << "\n";
	print2DUtil(p->left, space);
}

void Process_Tree()
{
	print2DUtil(root, 0);
}

int main()
{
	int choice = 0;
	int x, i;
	Node *p;
	system("cls");
	cout << "------  BAI TAP 1 , CHUONG 4 , CAY NPTK  -------" << endl;
	cout << "1. Khoi tao cay NPTK rong" << endl;
	cout << "2. Them phan tu vao cay NPTK" << endl;
	cout << "3. Tim phan tu co gia tri X trong cay NPTK" << endl;
	cout << "4. Xoa phan tu co gia tri X trong cay NPTK" << endl;
	cout << "5. Duyet cay NPTK theo LNR" << endl;
	cout << "6. Duyet cay NPTK theo NLR" << endl;
	cout << "7. Duyet cay NPTK theo LRN" << endl;
	cout << "8. Xuat cay NPTK" << endl;
	cout << "9. Thoat" << endl;
	do
	{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			Init();
			cout << "Ban vua khoi tao cay NPTK thanh cong!\n";
			break;
		case 2:
			cout << "Vui long nhap gia tri X can them";
			cin >> x;
			InsertNode(root, x);
			cout << "Cay NPTK sau khi them la: ";
			Process_Tree();
			break;
		case 3:
			cout << "Vui long nhap gia tri X can tim";
			cin >> x;
			p = search(root, x);
			if (p != NULL)
				cout << "Tim thay X = " << x << " trong cay NPTK" << endl;
			break;
		case 4:
			cout << "Vui long nhap gia tri X can xoa";
			cin >> x;
			i = Delete(root, x);
			if (i == 0)
				cout << "Khong tim thay X = " << x << " de xoa!" << x << endl;
			else
			{
				cout << "Da xoa thanh cong phan tu X = " << x << "trong cay NPTK" << endl;
				cout << "Cay NPTK sau khi xoa la: ";
				Process_Tree();
			}
			break;
		case 5:
			cout << "Cay NPTK duyet theo LNR la: ";
			DuyetLNR(root);
			break;
		case 6:
			cout << "Cay NPTK duyet theo NLR la: ";
			DuyetNLR(root);
			break;
		case 7:
			cout << "Cay NPTK duyet theo LRN la: ";
			DuyetLRN(root);
			break;
		case 8:
			cout << "Cay NPTK nhu sau: ";
			Process_Tree();
			break;
		case 9:
			cout << "Goodbye ...!" << endl;
			break;
		default:
			break;
		}
	} while (choice != 9);
	system("pause");
	return 0;
}