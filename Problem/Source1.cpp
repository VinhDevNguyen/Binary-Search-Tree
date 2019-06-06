#include <iostream>
using namespace std;


struct node
{
	int info;
	node *left;
	node *right;
};
typedef node* Tree;

void Insert(Tree &t, int x)
{
	if (t == NULL)
	{
		node *p = new node;
		p->info = x;
		p->left = p->right = NULL;
		t = p;
	}
	else
	{
		if (x>t->info)
			Insert(t->right, x);
		if (x<t->info)
			Insert(t->left, x);
	}
}

void inputTree(Tree &t)
{
	int x;
	cin >> x;
	if (x == -1) return;
	while (x != -1)
	{
		if (x >= 1)
			Insert(t, x);
		cin >> x;
	}
}

void LNR(Tree T)
{
	if (T != NULL)
	{
		LNR(T->left);
		cout << T->info << " ";
		LNR(T->right);
	}
}

int check(int x)
{
	if (x<2) return 0;
	for (int i = 2; i <= x / 2; i++)
		if (x%i == 0)
			return 0;
	return 1;
}


void listPrime(Tree t)
{
	if (t != NULL)
	{
		if (check(t->info))
			cout << t->info << " ";
		listPrime(t->left);
		listPrime(t->right);
	}
}


int main()
{
	Tree T = NULL;
	inputTree(T);
	LNR(T);

	return 0;
}