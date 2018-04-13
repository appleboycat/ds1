#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 10
#define MAXQ 10

typedef int vtype;
typedef struct adjnode
{
	int			vidx;
	struct adjnode *next;
}adjnode;
typedef struct vexnode
{
	adjnode		*firstarc;
}vexnode, Adjlist[MAXV];
typedef struct graph
{	
	int			vexnum, arcnum;
	Adjlist		vertices;
}ALgraph;
	
void BFS(Mgraph *m, int *visit, int start)
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
		for(int i = 0; i < m->vxnum; i++)
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
}
		
void DFS(Mgraph *m, int *visit, int start)
{
	if(visit[start] != 0)
		return;
	else
	{
		visit[start] = 1;
		printf(" %d", start);
		for(int i = 0; i < m->vxnum; i++)
		{
			if((m->edge[start][i] == 1)&&(visit[i] == 0))
			{
				DFS(m, visit, i);
				//	break;
			}
		}
	}
}

int main()
{
	freopen("7-6-data.1", "r", stdin);
	ALgraph *al = (ALgraph*)malloc(sizeof(ALgraph));
	scanf("%d %d\n", &(al->vexnum), &(al->arcnum));
	int acn = al->arcnum;
	while(acn --)
	{
		int i, j;
		scanf("%d %d", &i, &j);
		arcnode *p = al->vertices[i].firstarc;
		if(p != NULL)
			while(p->next != NULL)p = p->next;
		arcnode *tmp = (arcnode*)malloc(sizeof(arcnode));
		tmp->next = NULL:
		p->next = tmp;
	}

	int visit[MAXQ] = {0};
	for(int i = 0; i < m->vxnum; i++)
	{	
		if(visit[i] == 0)
		{
			printf("{");
			DFS(m, visit, i);
			printf(" }\n");
		}
	}
	
	memset(visit, 0, (MAXQ * sizeof(int)));
	for(int i = 0; i < m->vxnum; i++)
	{
		if(visit[i] == 0)
		{
			printf("{");
			BFS(m, visit, i);
			printf(" }\n");
		}
	}

	fclose(stdin);
	return 0;
}
