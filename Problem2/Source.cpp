#include<iostream>
using namespace std;

struct Node
{
	int info;
	Node* pLeft;
	Node* pRight;
};

typedef Node* Tree;
Node* CreateNode(int x)
{
	Node* p;
	p = new Node;
	if (p == NULL)
	{
		exit(-1);
	}
	else
	{
		p->info = x;
		p->pLeft = NULL;
		p->pRight = NULL;
	}
	return p;
}

void CreateTree(Tree& a)
{
	a = NULL;
}


void DeleteTree(Tree& a)
{
	if (a != NULL)
	{
		DeleteTree(a->pLeft);
		DeleteTree(a->pRight);
		delete a;
	}

}

int InsertNode(Tree& a, int x)
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
		InsertNode(a->pRight, x);
	}
	else
	{
		InsertNode(a->pLeft, x);
	}
}

void xuatLNR(Tree a)
{
	if (a != NULL)
	{
		xuatLNR(a->pLeft);
		cout << a->info << " ";
		xuatLNR(a->pRight);
	}
}

int MaxNode(Tree a)
{
	if (a->pRight == NULL)
	{
		return a->info;
	}
	else
	{
		return MaxNode(a->pRight);
	}
}

void ThayThe(Tree& a, Tree& b)
{
	if (b->pLeft != NULL)
	{
		ThayThe(a, b->pLeft);
	}
	else
	{
		a->info = b->info;
		a = b;
		b = b->pRight;
	}
}

void DeleteNode(Tree& a, int x)
{
	if (a != NULL)
	{
		if (a->info < x)
		{
			DeleteNode(a->pRight, x);
		}
		else
		{
			if (a->info > x)
			{
				DeleteNode(a->pLeft, x);
			}
			else
			{
				Node* p;
				p = a;
				if (a->pLeft == NULL)
				{
					a = a->pRight;
				}
				else
				{
					if (a->pRight == NULL)
					{
						a = a->pLeft;
					}
					else
					{
						ThayThe(p, a->pLeft);
					}
					delete p;
				}
			}
		}
	}
	else
	{
		cout << "ko tim thay phan tu can xoa" << endl;
	}
}



void thaotac(Tree& a, int x, int chon)
{
	cin >> chon;
	for (int i = 0; i < chon; i++)
	{
		cin >> x;
		CreateNode(x);
		InsertNode(a, x);
	}
}

int k = 0;

void XuatBac1Node(Tree a)
{
	if (a != NULL)
	{
		k++;
		XuatBac1Node(a->pLeft);
		cout << k - 1 << " ";
		XuatBac1Node(a->pRight);
		k--;
	}
}

int main()
{
	Tree a;
	CreateTree(a);
	int x = 0;
	int chon = 0;
	thaotac(a, x, chon);
	cout << endl;
	XuatBac1Node(a);
	cout << endl;
	DeleteTree(a);
	system("pause");
	return 0;
}