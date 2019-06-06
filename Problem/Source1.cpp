#include<iostream>
using namespace std;

struct Node
{
	int info;
	Node* pLeft;
	Node* pRight;
};

typedef Node* TREE;

Node* CreateNode(int x)
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
	int x;

	do
	{
		cin >> x;
		if (x != -1)
			InserNode(a, x);
	} while (x != -1);
	xuatLNR(a);
	system("pause");
	return 0;
}