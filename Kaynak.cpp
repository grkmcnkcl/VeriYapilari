#include<iostream>

using namespace std;

struct nodetype {
	int info;
	struct nodetype *left;
	struct nodetype *right;
};
typedef struct nodetype *NODEPTR;

NODEPTR getnode(void)
{
	NODEPTR p;
	p = (NODEPTR)malloc(sizeof(struct nodetype));
	return(p);
}

NODEPTR maketree(int x) {
	NODEPTR p;
	p = getnode();
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return(p);
}

void setleft(NODEPTR p, int x)
{
	if (p == NULL)
		printf("void insertion\n");
	else if (p->left != NULL)
		printf("invalid insertion\n");
	else
		p->left = maketree(x);

}

void setright(NODEPTR p, int x)
{
	if (p == NULL)
		printf("void insertion\n");
	else if (p->right != NULL)
		printf("invalid insertion\n");
	else
		p->right = maketree(x);

}

void pretrav(NODEPTR p)
{
	if (p != NULL)
	{
		pretrav(p->left);
		pretrav(p->right);

		printf("%d\n", p->info);
	}
}

NODEPTR mergetree(NODEPTR a, NODEPTR b) {

	NODEPTR p, q;
	p = q = a;
	int x = b->info;
	do {
		while (x != p->info && q != NULL)
		{
			p = q;
			if (x < p->info)
				q = p->left;
			else
				q = p->right;

		}
		if (x == p->info);

		else if (x < p->info)
			setleft(p, x);
		else
			setright(p, x);

		pretrav(b->left);
		x = b->info;
		pretrav(b->right);

	} while (x != p->info && q != NULL);

	return (a);
}

int main()
{
	NODEPTR ptree, ptree2;
	NODEPTR p, q;
	int number, number2;
	cin>>number;
	
	ptree = maketree(number);

	while (number != EOF) {
		p = q = ptree;
		while (number != p->info && q != NULL)
		{
			p = q;
			if (number < p->info)
				q = p->left;
			else
				q = p->right;

		}
		if (number == p->info);
			
		else if (number < p->info)
			setleft(p, number);
		else
			setright(p, number);

		cin >> number;

	}
	cin >> number2;
	ptree2 = maketree(number2);
	while (number2 != EOF) {
		p = q = ptree2;
		while (number2 != p->info && q != NULL)
		{
			p = q;
			if (number2 < p->info)
				q = p->left;
			else
				q = p->right;

		}
		if (number2 == p->info);

		else if (number2 < p->info)
			setleft(p, number2);
		else
			setright(p, number2);

		cin >> number2;

	}
	ptree = mergetree(ptree, ptree2);
	pretrav(ptree);
	system("PAUSE");
	return 0;
}