?#include <iostream>
#include <stdio.h>
using namespace std;
//cau 3.1: khai bao cau truc danh sach
struct Node
{
	int info;
	Node *link;
};
Node *first;
// cau 3.2: khoi tao danh sach rong
void Init()
{
	first = NULL;
}
// cau 3.3: xuat cac phan tu trong ds
void Process_list()
{
	Node *p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << "\t";
		p = p->link;
	}
	cout << endl;
}
// cau 3.4: tim 1 phan tu trong ds
Node *Search(int x)
{
	Node *p = first;
	while (p != NULL && p->info != x)
	{
		p = p->link;
	}
	return p;
}
// cau 3.5: them phan tu vao ?au ds 
void Insert_first(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}
// cau 3.6: xoa phan tu ?au ds
int Delete_first()
{
	if (first != NULL)
	{
		Node *p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}
// cau 3.7: them phan tu cuoi ds
void Insert_last(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if (first == NULL)
	{
		first = p;
	}
	else
	{
		Node *q = first;
		while (q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}
// cau 3.8: xoa phan tu cuoi ds
int Delete_last()
{
	if (first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while (p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first)
		{
			q->link = NULL;
		}
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
// cau 3.9: tim phan tu trong ds, roi xoa phan tu nay neu ...
int SearchAndDelete(int x)
{
	if (first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while (p->info != x && p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first && p->link != NULL)
		{
			// phan tu giua ds
			if (p->link != NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;
			return 1;
		}
		else if (p == first)
		{
			// phan tu dau ds
			first = p->link;
			delete p;
			return 1;
		}
		else if (p->link == NULL && p->info == x)
		{
			// phan tu cuoi ds
			q->link = NULL;
			delete p;
			return 1;
		}
		else
			return 0;
	}
	return 0;
}
// ham doi cho gia tri cua 2 phan tu
void swap(Node *a, Node *b)
{
	int t = a->info;
	a->info = b->info;
	b->info = t;
}
//cau 3.10: sap xep ds co thu tu tang dan
//su dung Selection Sort
void Sort()
{
	Node *p, *q, *min;
	//Di chuyen ranh gioi giua mang sap xep & chua sap xep
	p = first;
	while (p != NULL)
	{
		//tim phan tu nho nhat trong mang chua sap xep
		min = p;
		q = p->link;
		while (q != NULL)
		{
			if (q->info < min->info)
				min = q;
			q = q->link;
		}
		//doi cho phan tu nho nhat voi phan tu dau tien 
		swap(min, p);
		p = p->link;
	}
}
//cau 3.10: sap xep ds co thu tu giam dan
//su dung Selection Sort
void Sort()
{
	Node *p, *q, *min;
	//Di chuyen ranh gioi giua mang sap xep & chua sap xep
	p = first;
	while (p != NULL)
	{
		//tim phan tu nho nhat trong mang chua sap xep
		min = p;
		q = p->link;
		while (q != NULL)
		{
			if (q->info > min->info)
				min = q;
			q = q->link;
		}
		//doi cho phan tu nho nhat voi phan tu dau tien 
		swap(min, p);
		p = p->link;
	}
}
int main()
{
	int choice = 0;
	int x, i;
	Node *p;
	system("cls");
	cout << "------- BAI TAP 3 , CHUONG 2 , DANH SACH LIEN KET DON";
	cout << "1. Khoi tao danh sach lien ket don rong" << endl;
	cout << "2. Them phan tu vao dau DSLK don" << endl;
	cout << "3. Them phan tu vao cuoi DSLK don" << endl;
	cout << "4. Xoa phan tu vao dau DSLK don" << endl;
	cout << "5. Xoa phan tu vao cuoi DSLK don" << endl;
	cout << "6. Xuat DSLK don" << endl;
	cout << "7. Tim mot phan tu gia tri x trong DSLK don" << endl;
	cout << "8. Tim mot phan tu gia tri x va xoa no neu co" << endl;
	cout << "9. Sap xep DSLK don tang dan " << endl;
	cout << "10. Sap xep DSLK don giam dan " << endl;
	cout << "11. Thoat" << endl;
	do
	{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			Init();
			cout << "Ban vua khoi tao DSLK don thanh cong!\n";
			break;
		case 2:
			cout << "Vui long nhap gia tri x: ";
			cin >> x;
			Insert_first(x);
			cout << "Danh sach sau khi them la: ";
			Process_list();
			break;
		case 3:
			cout << "Vui long nhap gia tri x: ";
			cin >> x;
			Insert_last(x);
			cout << "Danh sach sau khi them la: ";
			Process_list();
			break;
		case 4:
			i = Delete_first();
			if (i == 0)
				cout << "Danh sach rong, khong the xoa!" << x << endl;
			else
			{
				cout << "Da xoa thanh cong phan tu dau cua DSLK don!" << endl;
				cout << "Danh sach sau khi xoa la: ";
				Process_list();
			}
			break;
		case 5:
			i = Delete_last();
			if (i == 0)
				cout << "Danh sach rong, khong the xoa!" << x << endl;
			else
			{
				cout << "Da xoa thanh cong phan tu cuoi cua DSLK don!" << endl;
				cout << "Danh sach sau khi xoa la: ";
				Process_list();
			}
			break;
		case 6:
			cout << "Danh sach hien tai la: ";
			Process_list();
			break;
		case 7:
			cout << "Vui long nhap gia tri can tim x = ";
			cin >> x;
			p = Search(x);
			if (p != NULL)
			{
				cout << "Tim thay phan tu co gia tri x = " << x << endl;
			}
			else
				cout << "khong tim thay phan tu co gia tri x = " << x << "!!" << endl;
			break;
		case 8:
			cout << "Vui long nhap gia tri can tim x = ";
			cin >> x;
			i = SearchAndDelete(x);
			if (i == 1)
			{
				cout << "Tim thay x = " << x << "va da xoa thanh cong" << endl;
				cout << "Danh sach sau khi xoa la: ";
				Process_list();
			}
			else
				cout << "khong tim thay phan tu co gia tri x = " << x << "!!" << endl;
			break;
		case 9:
			Sort();
			cout << "Danh sach sau khi sap xep tang dan la: ";
			Process_list();
			break;
		case 10:
			Sort();
			cout << "Danh sach sau khi sap xep giam dan la: ";
			Process_list();
			break;
		case 11:
			cout << "Goodbye ....!" << endl;
			break;
		default:
			break;
		}
	} while (choice != 11);
	system("pause");
	return 0;
}
