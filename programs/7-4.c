#include <stdio.h>

typedef struct bnode
{
	int data;
	bnode* l;
	bnode* r;
}bnode, *btree;

void InsertNode(tree tr, node *nd);

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

int main()
{
	int n, i;
	scanf("%d", &n);
	i = n;
	if(n != 0)
	{
		scanf(" %d\n", &l);
		btree *tary = (btree*)malloc(sizeof(btree*) * (l+1));
		for(int j = 0; j <= l; j++)
		{
			tary[j] = BuildTree();
		}
	}

			
	return 0;
}

void InsertNode(tree tr, node *nd)
{
	node *pre = tr;
	if(nd->data < pre->data)
	{
		if(pre->l != NULL)
		{
			InsertNode(pre->l, nd);
		}else
		{
			pre->l = nd;
		}
	}else
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
