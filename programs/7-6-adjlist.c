#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 10
#define MAXQ 10

typedef int vtype;
typedef struct arcnode
{
	int				vidx;
	struct arcnode *next;
}arcnode;
typedef struct vexnode
{
	arcnode		*firstarc;
}vexnode, Adjlist[MAXV];
typedef struct graph
{	
	int			vexnum, arcnum;
	Adjlist		vertices;
}ALgraph;
void DFS(ALgraph *al, int *visit, int start)
{
	if(visit[start] != 0)
		return;
	else
	{
		visit[start] = 1;
		printf(" %d", start);
		for(arcnode *p = al->vertices[start].firstarc; p != NULL; p = p->next)
		{
			if(visit[p->vidx] == 0)
				DFS(al, visit, p->vidx);
		}
	}
}
	
void BFS(ALgraph *al, int *visit, int start)
{
	if(visit[start] != 0)
		return;
	printf(" %d", start);
	visit[start] = 1;
	int	que[MAXQ];
	int front = 0, rear = 0;
	que[rear] = start;
	rear = (rear + 1) % MAXQ;
	while( rear != front)
	{
		int tmp = que[front];
		front = (front + 1) % MAXQ;
		for(arcnode *p = al->vertices[tmp].firstarc; p != NULL; p = p->next)
		{
			if(visit[p->vidx] == 0)
			{
				printf(" %d", p->vidx);
				visit[p->vidx] = 1;
				//if(((rear + 1) % MAXQ) != front)
				//{
					que[rear] = p->vidx;  
					rear = (rear + 1) % MAXQ;
				//}
				//else
			    //	printf("Error: que is full!!\n");
			}
		}			
	}
}
		

int main()
{
	freopen("7-6-data.1", "r", stdin);
	ALgraph *al = (ALgraph*)malloc(sizeof(ALgraph));
	scanf("%d %d\n", &(al->vexnum), &(al->arcnum));
	int an = al->arcnum;
	int vn = al->vexnum;
	for(int i = 0; i < vn; i++)
		al->vertices[i].firstarc = NULL;
	while(an --)
	{
		int i, j;
		scanf("%d %d", &i, &j);

		arcnode *tmp = (arcnode*)malloc(sizeof(arcnode));
		tmp->vidx = j;
		tmp->next = NULL;
		arcnode *p = al->vertices[i].firstarc;
		if(p == NULL)
		{
			al->vertices[i].firstarc = tmp;
		}
		else
		{
			while(p->next != NULL)p = p->next;
			p->next = tmp;
		}

		arcnode *tmp2 = (arcnode*)malloc(sizeof(arcnode));
		tmp2->vidx = i;
		tmp2->next = NULL;

		arcnode *p2 = al->vertices[j].firstarc;
		if(p2 == NULL)
		{
			al->vertices[j].firstarc = tmp2;
		}
		else
		{
			while(p2->next != NULL)p2 = p2->next;
			p2->next = tmp2;
		}
	}

	int visit[MAXQ] = {0};
	for(int i = 0; i < al->vexnum; i++)
	{	
		if(visit[i] == 0)
		{
			printf("{");
			DFS(al, visit, i);
			printf(" }\n");
		}
	}
	
	memset(visit, 0, (MAXQ * sizeof(int)));
	for(int i = 0; i < al->vexnum; i++)
	{
		if(visit[i] == 0)
		{
			printf("{");
			BFS(al, visit, i);
			printf(" }\n");
		}
	}

	fclose(stdin);
	return 0;
}
