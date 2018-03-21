#include <stdio.h>

typedef struct node{
	int 	parents;
	char 	data;
	int 	l;
	int 	r;
}node;

typedef struct Tree{
	node*	nodelist;
	int 	nodenum;
	int 	root;
}Tree;
	
#define MKTREE(tr)						\
	Tree* tr = (Tree*)malloc(sizeof(Tree));	\
	tr->nodelist = NULL;				\
	tr->nodenum = -1;					\
	tr->root = -1;
	
Tree* ReadTree()
{
	MKTREE(tr);
	int n;
	scanf("%d\n", &n);
	tr->nodenum = n;
	if(n != 0)
	{
		tr->nodelist = (node*)malloc(sizeof(node) * n);
	}
	int i = 0;
	while(i < n)
	{
		node *p = &(tr->nodelist[i]);
		
		scanf("%c ", &(p->data));

		scanf("%c ", &(p->l));
		scanf("%c\n", &(p->r));
		printf("i=%d: p=%p\n", i, p);
		printf(" %c，%d\n", p->data, p->data);
		if(p->l != '-')
		{
			tr->nodelist[p->l].parents = i;
			p->l -= 48;
		}else
		{
			p->l = -1;
		}
		if(p->r != '-')
		{
			tr->nodelist[p->r].parents = i;
			p->r -= 48;
		}else
		{
			p->l = -1;
		}

		i++;
	}
	for(i = 0; i < n; i++)
	{
		if(tr->nodelist[i].parents == -1)
		{
			tr->root = i;
			break;
		}
	}
	return tr;
}
void PrintTree(Tree* t)
{
	int n = t->nodenum;
	node* nl = t->nodelist;
	int i = 0;
	while(i < n)
	{
		//printf("%c \n", nl[i].data);
		printf("%c %d %d\n", nl[i].data, nl[i].l, nl[i].r);
		i++;
	}
}
		
//int isomorphic(Tree T1, Tree T2);
int main()
{
	freopen("7-3-data.in", "r", stdin);
	Tree* T1 = ReadTree();
	Tree* T2 = ReadTree();
	PrintTree(T1);
	PrintTree(T2);
	fclose(stdin);
	return 0;
}	