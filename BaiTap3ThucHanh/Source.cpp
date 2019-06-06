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

int Test_snt(int n)
{
	if (n<2) return 0;
	for (int i = 2; i<n; i++)
		if (!(n%i))
			return 0;
	return 1;
}

void XuatSNT(TREE a)
{
	if (a != NULL)
	{
		XuatSNT(a->pLeft);
		if (Test_snt(a->info == 1))
			cout << a->info << " ";
		XuatSNT(a->pRight);
	}
}


int k = 0;
int Muc;
void XuatBac1Node(TREE& a)
{

	if (a != NULL)
	{
		k++;
		XuatBac1Node(a->pLeft);
		if (k - 1 >= Muc)
			cout << a->info << " ";
		XuatBac1Node(a->pRight);
		k--;
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
	cin >> Muc;
	XuatBac1Node(a);
	system("pause");
	return 0;
}