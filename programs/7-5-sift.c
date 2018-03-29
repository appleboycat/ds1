#include <stdio.h>
#include <stdlib.h>

typedef int data;
void HeapAdjust(data* H, int s, int end);
void HeapSort(data* H, int n);

void ReadHeap(data* H, int n);
int main()
{
	freopen("7-5-sift-data.in", "r", stdin);
	int n;
	scanf("%d\n", &n);
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
	HeapSort(H, n);
	printf("after:\n");
	for(int i = 1; i <= n; i++)
	{
		printf("%d ", H[i]);
	}
	printf("\n");
}
void HeapSort(data* H, int n)
{
	for(int i = n/2; i > 0; i--)
	{
		HeapAdjust(H, i, n);	
	}	

	for(int i = n; i > 1; i--)
	{
		data tmp = H[i];
		H[i] = H[1];
		H[1] = tmp;
		HeapAdjust(H, 1, i-1);
	}
}

void HeapAdjust(data* H, int s, int end)
{
	printf("%s\n", __func__);
	data x = H[s];
	for(int j = s*2; j <= end; j = s*2)
	{
		if((H[j+1] < H[j])&&(j < end))
			j++;
		printf("H[%d]=%d  H[%d]=%d\n", s, H[s], j, H[j]);
		if(x < H[j])
			break;
		H[s] = H[j];
		s = j;
		printf("switch H[%d]=%d  H[%d]=%d\n", s, H[s], j, H[j]);
	}
	H[s] = x;
}
/*void sift(data* H, int s, int end)	
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
*/
