#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"
#include "iostream"
#include "windows.h"


using namespace std;
// Dinh nghia book
struct book{
	int masach;
	char tensach[30];
	char tacgia[30];
	char nxb[30];
	int namxb;
	int trangthai;
};
// Dinh nghia 1 node
struct Booknode{
	
	book info;
	Booknode *pNext;
};

// Dinh nghia 1 book node
struct list{
	Booknode *pHead;
	Booknode *pTail;
};
// Tao 1 Node moi
Booknode *taonode(book &s)
{
	Booknode *p;
	p=new Booknode;
	if(p==NULL)
	{
		cout<<"\n Khong du bo nho";
		return NULL;
	}
	p->info=s;
	p->pNext=NULL;
	return p;
}
//Chen vao dau danh sach	
void chendau(list &l, book s)
	{
		Booknode *p = taonode(s);
		if (l.pHead=NULL)
		{
			l.pHead=l.pTail=p;
		}
		else
		{
			l.pHead->pNext=p;
			p->pNext=NULL;
		}
}

//Xoa dau danh sach
int xoadau(list &l)
	{	
		if(l.pHead!=NULL)
		{	Booknode *p = l.pHead;
			l.pHead=l.pHead->pNext;
			delete p;
			if(l.pHead==NULL)
				l.pTail=NULL;
			return 1;
		}
		return 0;
	}

//Xoa theo ten sach
void xoatensach(list &l, char key[30])
{
	Booknode *p, *q = NULL; p=l.pHead;
	while((p!=NULL)&&strcmp(p->info.tensach,key)==0)
	{
		q=p;
		p=p->pNext;
	}
	if(p==NULL)
		cout<<"Khong co quyen sach co ten la: "<<key;
	if(q!=NULL)
		xoatensach(l,key);
	else
		xoadau(l);
}
//Tim kiem theo ten tac gia
void search_tacgia(list l, char ktacgia[30])
{
	Booknode *R;
	R=l.pHead;
	while(R!=NULL)
	{
			
			if(strcmp(R->info.tacgia,ktacgia)==0)
			{
				cout<<"\n --------------------------------------";
				cout<<"\n Ma Sach: "<<R->info.masach;
				cout<<"\n Ten Sach: "<<R->info.tensach;
				cout<<"\n Tac Gia: "<<R->info.tacgia;
				cout<<"\n Nha Xuat Ban: "<<R->info.nxb;
				cout<<"\n Nam Xuat Ban: "<<R->info.namxb;
				cout<<"\n Trang Thai (0-Chua muon : 1-Da muon): "<<R->info.trangthai;
				cout<<"\n --------------------------------------";
			}
			R=R->pNext;
	}
}

//Xem nhung cuon dang muon
void xuat(list l)
{
	int i=1;
	Booknode *R = l.pHead;
	cout<<"\n";
	if(R==NULL)
		cout<<"\n\t Danh Sach Rong - Khong The Xuat !";
	else
	{
		while(R!=NULL)
		{
			cout<<"\n ------------------------------------------";
			cout<<"\n | Sach thu: "<<i++<<"                             |";
			cout<<"\n ------------------------------------------";
			cout<<"\n Ma Sach: "<<R->info.masach;
			cout<<"\n Ten Sach: "<<R->info.tensach;
			cout<<"\n Tac Gia: "<<R->info.tacgia;
			cout<<"\n Nha Xuat Ban: "<<R->info.nxb;
			cout<<"\n Nam Xuat Ban: "<<R->info.namxb;
			cout<<"\n Trang Thai (0-Chua muon : 1-Da muon): "<<R->info.trangthai;
			R=R->pNext;
			cout<<"\n ------------------------------------------";
		}
	}
}
void Thoat() {
    cout << endl;
    cout << "\t\t\t\tChuc moi nguoi ngay moi tot lanh!" << endl;
    cout<<"\t\t**---------------------  \\(^.^)/  ---------------------**";
    cout << endl;
}
int main()
{
	list l;
	l.pHead=NULL;
	l.pTail=NULL;
	book s;
	int key; char ktacgia[30];
	int chon, nam;
	char tg[30];
		system("color A");
	do{
		system("cls");
		cout<<"\n\t ---------------------------------";
		cout<<"\n\t | CHUONG TRINH QUAN LY THU VIEN |";
		cout<<"\n\t ---------------------------------";
		cout<<"\n\t 1. Them 1 quyen sach vao dau danh sach ";
		cout<<"\n\t 2. Duyet danh sach ";
		cout<<"\n\t 3. Xoa 1 Phan Tu dau Danh Sach ";
		cout<<"\n\t 4. Xoa 1 Quyen Sach Theo Ten Tac Sach ";
		cout<<"\n\t 5. Seach 1 Quyen sach theo ten tac gia ";
		cout<<"\n\t 0. Thoat ";
		cout<<"\n\t # Chon (1->6 or 0 de thoat): ";
		cin>>chon;
		switch(chon)
		{
		case 1: {
			cout<<"\n\t Nhap Ma Sach: ";cin>>s.masach; fflush(stdin);
			cout<<"\n\t Nhap Ten Sach: "; gets(s.tensach);
			cout<<"\n\t Nhap Ten Tac Gia: "; gets(s.tacgia);
			cout<<"\n\t Nhap Ten NXB: "; gets(s.nxb);
			cout<<"\n\t Nhap Nam Xuat Ban: "; cin>>s.namxb;
			cout<<"\n\t Trang Thai (0-Chua muon : 1-Da Muon): "; cin>>s.trangthai;
			taonode(s);
			chendau(l,s); 
			break;
				}
		case 2:
			{
				xuat(l);
				break;
			}
		case 3:
			{
				xoadau(l);
				Sleep(500);
				cout<<"\n\t Delete Complited !!!";
				break;
			}
		case 5:
			{
				cout<<"\n\t Nhap Ten Tac Gia : "; fflush(stdin);
				gets(ktacgia);
				search_tacgia(l,ktacgia);
				break;
			}
		case 0:
			{
				Thoat();
				break; 
			}
		}
		if(chon!=0){
			cout<<endl; 
			cout<<"=> enter de tro ve!";
			getch();
			system("cls");
		}
	}
	while(chon!=0);
	return 0; 
}