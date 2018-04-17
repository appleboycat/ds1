#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 100

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
static int depth = 0;
void DFS(ALgraph *al, int *visit, int start)
{
	if((visit[start] != 0)||(depth > 6))
	{
		depth --;
		return;
	}
	else
	{
		visit[start] = 1;
		printf(" %d(%d)", start, depth);
		for(arcnode *p = al->vertices[start].firstarc; p != NULL; p = p->next)
		{
			depth ++;
			if(visit[p->vidx] == 0)
			{
				DFS(al, visit, p->vidx);
			}
		}
	}
}
int main()
{
	freopen("7-7-data.in", "r", stdin);
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

	int visit[MAXV] = {0};
	int reach[MAXV] = {0};
	for(int i = 1; i <= vn; i++)
	{	
		depth = 0;
		printf("\n");
		DFS(al, visit, i);
		printf("\n");
		
		for(int j = 1; j < vn; j++)
			if(visit[j] > 0)
				reach[i] ++;
		printf("reach[%d]=%d\n", i, reach[i]);
		printf("depth=%d\n", depth);
		memset(visit, 0, (MAXV * sizeof(int)));
	}

	

	fclose(stdin);
	return 0;
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
	int depth = 1;
	while( (rear != front)&&(depth < 6))
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
		depth ++;
	}
}*/
		

