#include <stdio.h>
#define MAXV 10

typedef int vtype;
typedef struct Mgraph
{	
	int		vxnum;
	int		egnum;
	int		edge[MAXV][MAXV];
	vtype	vertex[MAXV];
}Mgraph;

int main()
{
	freopen("7-6-data.in", "r", stdin);
	Mgraph *m = (Mgraph*)malloc(sizeof(Mgraph));
	scanf("%d %d\n", &(m->vxnum), &(m->egnum));
	int vn = m->vxnum;
	while(vn --)
	{
		int i, j;
		scanf("%d %d", &i, &j);
		m->edge[i][j] = 1;
	}



	fclose(stdin);

	return 0;
}

