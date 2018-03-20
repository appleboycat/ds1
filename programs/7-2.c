#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int coef;
	int index;
	struct node *next;
}node,*list;

#define MKNODE(ptr)                    	    \
	node* ptr=(node*)malloc(sizeof(node));  \
	ptr->next = NULL;
#define CPNODE(p1,p2)						\
	MKNODE(p2);								\
	p2->coef = p1->coef;					\
	p2->index = p1->index;

list ReadList();
list AddList(list L1, list L2);
list MultiList(list L1, list L2);
void InsertList(list L, node* p);

list ReadList()
{
	MKNODE(L);
	scanf("%d", &(L->index));
	node *pre = L;
	int n = L->index;
	while(n)
	{
		MKNODE(p);
		pre->next = p;
		scanf("%d %d", &(p->coef), &(p->index));
		pre = p;
		n--;
	}
	return L;
}

void PrintList(list L)
{
	node *p = L->next;
	if(p == NULL)
	{
		printf("0 0");
		return;
	}
	int count = 0;
	while(p != NULL)
	{
		if(count != 0)
			printf(" ");
		printf("%d %d", p->coef, p->index);
		count++;
		p = p->next;
	}
}

int main()
{
	//freopen("7-2-data.in", "r", stdin);
	node *L1, *L2;
	L1 = ReadList();
	L2 = ReadList();
	node *Lm = MultiList(L1, L2);
	PrintList(Lm);
	printf("\n");
	node *La = AddList(L1, L2);
	PrintList(La);
	//fclose(stdin);
	return 0;
}
list AddList(list L1, list L2)
{
	MKNODE(L);
	node *pre = L;
	node *p = L1->next, *q = L2->next;
	while((p != NULL) && (q != NULL))
	{
		if(p->index > q->index)
		{
			CPNODE(p,t);
			pre->next = t;
			pre = t;
			p = p->next;

		}
		else if(p->index < q->index)
		{
			CPNODE(q,t);
			pre->next = t;
			pre = t;
			q = q->next;
		}
		else if(p->index == q->index)
		{
			if((p->coef + q->coef)!=0)
			{
				CPNODE(p,t);
				t->coef += q->coef;
				pre->next = t;
				pre = t;
				p = p->next;
				q = q->next;
			}
			else
			{
				p = p->next;
				q = q->next;
			}
		}
	}
	while(p != NULL)
	{
		CPNODE(p,t);
		pre->next = t;
		pre = t;
		p = p->next;
	}
	while(q != NULL)
	{
		CPNODE(q,t);
		pre->next = t;
		pre = t;
		q = q->next;
	}
	return L;
}
list MultiList(list L1, list L2)
{
	MKNODE(L);
	node *p, *q;
	for(p = L1->next; p != NULL; p = p->next)
	{
		for(q = L2->next; q != NULL; q = q->next)
		{
			MKNODE(t);
			t->coef = p->coef * q->coef;
			t->index = p->index + q->index;	
			InsertList(L, t);
		}
	}
	return L;
}

void InsertList(list L, node* p)
{
	node* pre = L;
	int found = 0;
	if(pre->next == NULL)
	{
		p->next = NULL;
		pre->next = p;
		found = 1;
	}
	while((pre->next != NULL)&&(found == 0))
	{
		if(pre->next->index > p->index)
		{
			pre = pre->next;
		}else if(pre->next->index == p->index)
		{
			pre->next->coef += p->coef;
			if(pre->next->coef == 0)
			{
				node* tmp = pre->next;
				pre->next = pre->next->next;
				free(tmp);
			}
			found = 1;
		}else if(pre->next->index < p->index)
		{
			found = 1;
			p->next = pre->next;
			pre->next = p;
			found = 1;
		}
	}
	if(found == 0)
	{
		p->next = NULL;
		pre->next = p;
		found = 1;
	}
	return L;
}
		
	
	
	