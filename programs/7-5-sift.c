#include <stdio.h>
#include <stdlib.h>

typedef int data;
void ReadHeap(data* H, int n);
void InitHeap(data* H, int n);
void sift(data* H, int s, int end);	
int main()
{
	freopen("7-5-data.in", "r", stdin);
	int n, m;
	scanf("%d %d\n", &n, &m);
	data* H = (data*)malloc(sizeof(data) * (n+1));	
	ReadHeap(H, n);
	fclose("stdin");
	return 0;
}

void ReadHeap(data* H, int n)
{
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &(H[i]));
	}
	printf("before:\n");
	for(int i = 1; i <= n; i++)
	{
		printf("%d ", H[i]);
	}
	printf("\n");
	InitHeap(H, n);
	printf("after:\n");
	for(int i = 1; i <= n; i++)
	{
		printf("%d ", H[i]);
	}
	printf("\n");
}
void InitHeap(data* H, int n)
{
	for(int i = n/2; i > 0; i--)
	{
		sift(H, i, n);	
	}	
}
void sift(data* H, int s, int end)	
{
	printf("%s\n", __func__);
	int i = s;
	int j = s*2;
	while(j < end)
	{
		if(H[j+1] < H[j])
		{
			j++;
		}
		if(H[j] < H[i])
		{
			printf("switch H[%d]=%d H[%d]=%d\n", i, H[i], j, H[j]);
			int tmp = H[j];
			H[j] = H[i];
			H[i] = tmp;
			i = j;
			j = i * 2;
		}else
			break;
	}
}
