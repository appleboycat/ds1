#include <stdio.h>

typedef struct node{
    int parents;
    int l;
    int r;
    char data;
}node;

typedef struct tree{
    node* nodelist;
    int   nodenum;
    int   root;
}tree;

#define MKTREE(tr)							\
	tree *tr = (tree*)malloc(sizeof(tree));	\
	tr->nodelist = NULL;					\
	tr->nodenum = 0;						\
	tr->root = -1;
	
int isomorphic(tree* T1, tree* T2);
int ism(node* l1, node* l2, int n1, int n2);

tree* ReadTree()
{
	MKTREE(tr);
	scanf("%d\n", &(tr->nodenum));
	int n = tr->nodenum;
	if(n == 0)
	{
	    return tr;
	}else
	{
	    int i = 0;
	    tr->nodelist = (node*)malloc(sizeof(node) * n);
	    for(i = 0; i < n; i++)
	    {
			node *p = &(tr->nodelist[i]);
			p->parents = -2;
	    }
	    for(i = 0; i < n; i++)
	    {
	        node *p = &(tr->nodelist[i]);
	    
	        scanf("%c ", &(p->data));
	        scanf("%c ", &(p->l));
	        scanf("%c\n", &(p->r));
			int *q;
	        if(p->l != '-')
			{
				p->l -= 48;
				q = &(tr->nodelist[p->l].parents);
				*q = i;
			}else
			{
				p->l = -1;
			}
			if(p->r != '-')
			{	
				p->r -= 48;
				q = &(tr->nodelist[p->r].parents);
				*q = i;
			}else
	        {
				p->r = -1;
	        }
	    }
		
	    for(i = 0; i < n; i++)
	    {
	        if(tr->nodelist[i].parents == -2)
			{
				tr->root = i;
				break;
			}
	    }
		return tr;
	}
	
}
void PrintTree(tree* t)
{
	int n = t->nodenum;
	node* nl = t->nodelist;
	int i = 0;
	while(i < n)
	{
		printf("%c %d %d\tparents:%d\t%p\n", nl[i].data, nl[i].l, nl[i].r, nl[i].parents, &(nl[i]));
		i++;
	}
}
		
int isomorphic(tree* T1, tree* T2)
{
    if(T1->nodenum != T2->nodenum)
    {
		return 0;
    }else
    {
		node *l1 = T1->nodelist, *l2 = T2->nodelist;
		int n1 = T1->root, n2 = T2->root;
		return ism(l1, l2, n1, n2);
    }
}
int ism(node* l1, node* l2, int n1, int n2)
{
    //printf("Enter %s\n", __func__);
	//printf("Root %d %d\n", n1, n2);
	if((n1 == -1)&&(n2 == -1))
	{
		return 1;
	}
	
	node *p1 = &(l1[n1]), *p2 = &(l2[n2]);
	//printf("%p %p n1 %c %d (%d %d)\n", l1, &(l1[n1]), p1->data, p1->data, p1->l, p1->r);
	//printf("%p %p n2 %c %d (%d %d)\n", l2, &(l2[n2]), p2->data, p2->data, p2->l, p2->r);
	if(p1->data != p2->data)
	{
		return 0;
	}else
	{	
		if(ism(l1, l2, p1->l, p2->l))
		{
			return ism(l1, l2, p1->r, p2->r);
		}
		else if(ism(l1, l2, p1->l, p2->r))
		{	
			return ism (l1, l2, p1->r, p2->l);
		}
		else
		{
			return 0;
		}
	}
}
    
	
int main()
{
	freopen("7-3-data.in", "r", stdin);
	tree* T1 = ReadTree();
	tree* T2 = ReadTree();
	if(isomorphic(T1, T2))
		printf("Yes");
	else
		printf("No");
	fclose(stdin);
	return 0;
}	
