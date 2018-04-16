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
		for(arcnode *p = al->vertices[start].firstarc; p != NULL ; p = al->vertices[p->vidx].firstarc)
		{
			if(visit[p->vidx] == 0)
			{
				DFS(al, visit, p->vidx);
				//	break;
			}
		}
	}
}
	
/*void BFS(ALgraph *al, int *visit, int start)
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
		for(int i = 0; i < al->vexnum; i++)
		{
			if((visit[i] == 0) && (m->edge[tmp][i] == 1))
			{
				printf(" %d", i);
				visit[i] = 1;
				//if(((rear + 1) % MAXQ) != front)
				//{
					que[rear] = i;  
					rear = (rear + 1) % MAXQ;
				//}
				//else
			    //	printf("Error: que is full!!\n");
			}
		}			
	}
}*/
		

int main()
{
	freopen("7-6-data.1", "r", stdin);
	ALgraph *al = (ALgraph*)malloc(sizeof(ALgraph));
	printf("sizeof graph:%d\n", sizeof(ALgraph));
	//for(int i = 0; i < MAXV; i++)
	scanf("%d %d\n", &(al->vexnum), &(al->arcnum));
	int acn = al->arcnum;
	for(int i = 0; i < acn; i++)
		al->vertices[i].firstarc = NULL;
	while(acn --)
	{
		int i, j;
		scanf("%d %d", &i, &j);
		arcnode *p = al->vertices[i].firstarc->next;

		arcnode *tmp = (arcnode*)malloc(sizeof(arcnode));
		tmp->next = NULL;
			printf("tmp %p\n", tmp); 
			printf("al  %p\n", al->vertices[i].firstarc);
			printf("p   %p\n", p); 
			printf("p   %d\n", p); 

		if(p == NULL)
		{
			printf("after:\n"); 
			al->vertices[i].firstarc = tmp;
			printf("%p\n", al->vertices[i].firstarc);
			printf("%p\n", p); 
		}
		else
		{
			while(p->next != NULL)p = p->next;
			p->next = tmp;
		}
	}

	int visit[MAXQ] = {0};
	for(int i = 0; i < al->arcnum; i++)
	{	
		if(visit[i] == 0)
		{
			printf("{");
			DFS(al, visit, i);
			printf(" }\n");
		}
	}
	
	memset(visit, 0, (MAXQ * sizeof(int)));
	/*for(int i = 0; i < al->arcnum; i++)
	{
		if(visit[i] == 0)
		{
			printf("{");
			//BFS(m, visit, i);
			printf(" }\n");
		}
	}*/

	fclose(stdin);
	return 0;
}
