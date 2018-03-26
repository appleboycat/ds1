#include <stdio.h>
#include <stdlib.h>

typedef struct bnode
{
	int data;
	struct bnode* l;
	struct bnode* r;
}bnode, *btree;

#define MKNODE(nd)\
	bnode* nd = (bnode*)malloc(sizeof(bnode));	\
	nd->data = -1;								\
	nd->l = NULL;								\
	nd->r = NULL;
	
btree BuildTree(int n);
void InsertNode(btree tr, bnode *nd);
int CompTree(btree t1, btree t2);

int CompTree(btree t1, btree t2)
{
	if((t1 == NULL)&&(t2 == NULL))
	{
		return 1;
	}else if((t1 != NULL)&&(t2 != NULL))
	{
		if(t1->data == t2->data)
			return (CompTree(t1->l, t2->l) && CompTree(t1->r, t2->r));
		else return 0;
	}else
		return 0;
}
void InsertNode(btree tr, bnode *nd)
{
	bnode *pre = tr;
	if(nd->data < pre->data)
	{
		if(pre->l != NULL)
		{
			InsertNode(pre->l, nd);
		}else
		{
			pre->l = nd;
		}
	}else if(nd->data > pre->data)
	{
		if(pre->r != NULL)
		{
			InsertNode(pre->r, nd);
		}else
		{
			pre->r = nd;
		}
	}
}
btree BuildTree(int n)
{
	btree tr= (btree)malloc(sizeof(btree));
	for(int k = 0; k < n; k++)
	{
		MKNODE(nd);
		if(k == 0)
			tr = nd;
		scanf("%d", &(nd->data));
		InsertNode(tr, nd);
	}
	return tr;
	
}
void PrintTree(bnode* p)
{
	if(p != NULL)
	{
		PrintTree(p->l);
		printf("%d ", p->data);
		PrintTree(p->r);
	}else
		return;
}



int main()
{
	freopen("7-4-data.in", "r", stdin);
	int n, l;
	scanf("%d", &n);
	while(n != 0)
	{
		scanf(" %d\n", &l);
		btree* trary = (btree*)malloc(sizeof(btree) * (l+1));
		
		for(int j = 0; j <= l; j++)
		{
			trary[j] = BuildTree(n);
		}
		for(int j = 1; j <= l; j++)
		{
			if(CompTree(trary[0], trary[j]))
				printf("Yes\n");
			else
				printf("No\n");
		}
		scanf("%d", &n);
	}
	fclose(stdin);
	return 0;
}
