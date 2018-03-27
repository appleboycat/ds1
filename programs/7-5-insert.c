#include <stdio.h>
#include <stdlib.h>

typedef int data;
void Read(data* H, int n, int *T, int m);
void InitHeap(data* H, int n);
//void sift(data* H, int s, int end);	
void InsertHeap(data* H, int i);	
int main()
{
	freopen("7-5-data.in", "r", stdin);
	int n, m;
	scanf("%d %d\n", &n, &m);
	data* H = (data*)malloc(sizeof(data) * (n+1));	
	int* T = (int*)malloc(sizeof(int) * m);	
	Read(H, n, T, m);
	
	for(int i = 0; i < m; i ++)
	{
		for(int k = T[i]; k > 0; k/=2)
		{
			if(k == 1)
				printf("%d", H[k]);
			else
				printf("%d ", H[k]);
		}
		printf("\n");
	}
	fclose("stdin");
	return 0;
}


void Read(data* H, int n, int *T, int m)
{
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &(H[i]));
	}
	for(int i = 0; i < m; i ++)
	{
		scanf("%d", &(T[i]));
	}
	InitHeap(H, n);
}
void InitHeap(data* H, int n)
{
	//for(int i = n/2; i > 0; i--)
	//{
	//	sift(H, i, n);	
	//}	
	for(int i = 1; i <= n; i++)
	{
		//printf("Insert H[%d]=%d\n", i, H[i]);
		InsertHeap(H, i);	
	}	
}
void InsertHeap(data* H, int i)	
{
	for(int j = i/2; j > 0; i /= 2, j = i/2)
	{
		if(H[j] > H[i])
		{
			//printf("switch H[%d]=%d H[%d]=%d\n", i, H[i], j, H[j]);
			data tmp = H[i];
			H[i] = H[j];
			H[j] = tmp;
		}else
			break;
			
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
