#include<iostream>
using namespace std;

struct Node //Cau truc du lieu cua mot node
{
	int info;
	Node* pLeft;
	Node* pRight;
};

typedef Node* TREE; // Cau truc du lieu cua cay

Node* CreateNode(int x) //Tao mot node co du lieu bang x
{
	Node* p;
	p = new Node;
	if (p == NULL)
	{
		exit(1);
	}
	else
	{
		p->info = x;
		p->pLeft = NULL;
		p->pRight = NULL;
	}
	return p;
}

void CreateTree(TREE& a)
{
	a = NULL;
}

int InserNode(TREE& a, int x)
{
	if (a == NULL)
	{
		a = new Node;
		if (a == NULL)
		{
			return -1;
		}
		a->info = x;
		a->pLeft = NULL;
		a->pRight = NULL;
		return 1;
	}
	if (x == a->info)
	{
		return 0;
	}
	if (x > a->info)
	{
		InserNode(a->pRight, x);
	}
	if (x < a->info)
	{
		InserNode(a->pLeft, x);
	}
}

int MaxValue(TREE & a)
{
	if (a->pRight == NULL) return a->info;
	else return MaxValue(a->pRight);
}

void thaythe(TREE &q, TREE &p) {
	// tim phan tu trai nhat cua cay ben phai
	//if(t==NULL) return;
	if (p->pLeft != NULL) {
		thaythe(q, p->pLeft);
	}
	else {
		q->info = p->info;
		q = p;
		p = p->pRight;
	}

}

void delTree(TREE &t, int x) {
	if (t == NULL) return;
	if (t->info > x) delTree(t->pLeft, x);
	if (t->info < x) delTree(t->pRight, x);
	if (t->info == x) { // khi tim ra phan tu do roi
		// xoa Node la hoac Node co 1 phan tu
		Node *q = t;// xoa phan tu bang con tro
		if (t->pLeft == NULL) { // neu ma ben traiphan tu do bang NULL
			t = t->pRight; // cho t tro toi t->pRight
		}
		else if (t->pRight == NULL) 
		{
			t = t->pLeft;
		}
		// xoa Node co 2 phan tu Trai va Phai
		else thaythe(q, t->pRight);
		delete q;
	}
}

void xuatLNR(TREE a)
{
	if (a != NULL)
	{
		xuatLNR(a->pLeft);
		cout << a->info << " ";
		xuatLNR(a->pRight);
	}
}

int main()
{
	TREE a;
	CreateTree(a);
	int n, x;
	do
	{
		cin >> n;
		if (n == 1)
		{
			cin >> x;
			InserNode(a, x);
		}
		else if (n == 2)
		{
			delTree(a, MaxValue(a));
		}
	} while (n != -1);
	xuatLNR(a);
	system("pause");
	return 0;
}