#include <iostream>
#include <cstdio>
using namespace std;

int a[4010];

void quick(int start, int end,int arr[])
{
    int p = arr[(start + end)/2];
    int s = start;
    int e = end;
     
    while (s<=e)
    {
        while (arr[s] < p && s <= e)s++;
        while (p < arr[e] && s <= e)e--;
 
        if (s <= e)
        {
            int tmp = arr[s];
            arr[s] = arr[e];
            arr[e] = tmp;
 
            s++; e--;
        }
    }
 
    if (start < e)quick(start,e,arr);
    if (s < end)quick(s, end, arr);
}
int main()
{
	int T, A, S, B;
	scanf("%d %d %d %d", &T, &A, &S, &B);
	for(int i=0; i<A; i++) {
		scanf("%d", &a[i]);
	}
	quick(0, A-1, a);
	
	for (int i = 0; i < (1 << (A)); i++) {
        for (int j = 0; j < A; j++) {
            if (i & (1 << j)){
                printf("%d ", a[j]);
            }
		}
        printf("\n");
    }

	return 0;
}