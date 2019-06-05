//Tìm chiều cao của BST

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

int HeightOfTree(TREE a)
{
	if (a == NULL)
	{
		return 0;
	}
	int d1 = HeightOfTree(a->pLeft);
	int d2 = HeightOfTree(a->pRight);
	if (d1 > d2)
	{
		return d1 + 1;
	}
	else
	{
		return d2 + 1;
	}
}


int main()
{
	TREE a;
	CreateTree(a);
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		InserNode(a, x);
	}
	cout << HeightOfTree(a);
	system("pause");
	return 0;
}