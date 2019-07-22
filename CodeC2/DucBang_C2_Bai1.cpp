//Bai1
#include<stdio.h>
#include<iostream>
using namespace std;

#define MAX 100
int a[MAX];
int n;
void input(int a[], int &n)
{
	cout <<"Nhap so phan tu can dung: ";
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cout <<"Nhap a[" << i << "] ";
		cin >> a[i];
	}
}
void output(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}
int search(int a[], int n, int x)
{
	for(int i = 0; i < n; i++)
		if(a[i] == x)
			return i;
	return 0;
}
int insertlast(int a[], int &n, int x)
{
	if(n < MAX)
	{
		a[n] = x;
		n++;
		return 1;
	}
	else
		return 0;
}
int Deletelast(int a[], int &n)
{
	if(n > 0)
	{
		n--;
		return 1;
	}
	return 0;
}
int Deletepos(int a[], int &n, int x)
{
	if(x >= 0 && x < n)
	{
		for(int i = x; i < n - 1; i++)
			a[i] = a[i + 1];
		n--;
		return 1;
	}
	return 0;
}
int SearchandDelete(int a[], int &n, int x)
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] == x)
		{
			int k = Deletepos(a, n, i);
			return 1;
		}
	}
	return 0;
}
int main()
{
	int choice = 0;
	int x, i;
	system("cls");
	cout <<"--------------Bai tap 1 - Chuong 2 - Danh sach dac-------------\n";
	cout <<"1.Nhap danh sach\n";
	cout <<"2.Xuat danh sach\n";
	cout <<"3.Tim phan tu trong danh sach\n";
	cout <<"4.Them phan tu cuoi danh sach\n";
	cout <<"5.Xoa phan tu cuoi danh sach\n";
	cout <<"6.Xoa phan tu tai vi tri duoc chon\n";
	cout <<"7.Tim va xoa 1 phan tu x trong danh sach neu co\n";
	cout <<"8.Thoat\n";
	do
	{
		cout<<"Vui long nhap so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			input(a, n);
			cout <<"Nhap danh sach thanh cong\n";
			break;
		case 2:
			output(a, n);
			cout <<"Xuat danh sach thanh cong\n";
			break;
		case 3:
			cout <<"Nhap gia tri can tim: ";
			cin >> x;
			i = search(a, n, x);
			if(i == 0)
				cout <<"Gia tri can tim khong co trong danh sach\n";
			else
				cout <<"Gia tri " << x << " tai vi tri a[" << i << "]\n";
			break;
		case 4:
			cout <<"Nhap gia tri can them cuoi danh sach: ";
			cin >> x;
			i = insertlast(a, n, x);
			if(i == 1)
			{
				cout <<"Them phan tu thanh cong\n";
				cout <<"Danh sach sau khi them:\n";
				output(a, n);
			}
			else
				cout <<"Khong them duoc phan tu\n";
			break;
		case 5:
			i = Deletelast(a, n);
			if(i == 1)
			{
				cout <<"Xoa thanh cong phan tu\n";
				cout <<"Danh sach sau khi xoa:\n";
				output(a, n);
			}
			else
				cout <<"Khong co phan tu nao de xoa\n";
			break;
		case 6:
			cout <<"Nhap vi tri can xoa: ";
			cin >> i;
			i = Deletepos(a, n, i);
			if(i == 1)
			{
				cout <<"Xoa thanh cong phan tu\n";
				cout <<"Danh sach sau khi xoa:\n";
				output(a, n);
			}
			else
				cout <<"Khong co phan tu nao de xoa\n";
			break;
		case 7:
			cout <<"Nhap phan tu can tim va xoa: ";
			cin >> x;
			i = SearchandDelete(a, n, x);
			if(i == 1)
			{
				cout <<"Xoa thanh cong phan tu\n";
				cout <<"Danh sach sau khi xoa:\n";
				output(a, n);
			}
			else
				cout <<"Khong co phan tu nao de xoa\n";
			break;
		case 8:
			cout <<"Goodbye\n";
			break;
		default:
			break;
		}
	}while(choice != 8);
	system("pause");
	return 0;
}