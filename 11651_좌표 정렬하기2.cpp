#include <iostream>
#include <cstdio>

using namespace std;
int num;
int x[100000];
int y[100000];

void quick(int start, int end, int arr[], int arr2[])
{
	int p = arr[(start + end)/2];
	int s = start;
	int e = end;

	while(s<=e) {
		while(arr[s]<p && s<=e) s++;
		while(p<arr[e] && s<=e) e--;

		if(s<=e) {
			int tmp = arr[s];
			arr[s] = arr[e];
			arr[e] = tmp;

			tmp = arr2[s];
			arr2[s] = arr2[e];
			arr2[e] = tmp;
			s++;
			e--;
		}
	}
	if(start<e)
		quick(start, e, arr, arr2);
	if(s<end)
		quick(s, end, arr, arr2);


}
int main()
{

	scanf("%d", &num);

	for(int i=0; i<num; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	quick(0, num-1, y, x);
	int same = 0;

	for(int i=0; i<num; i++) {
		if(y[i] == y[i+1])
			same++;
		else if(same!=0) {
			quick(i-same, i, x, y);
			same = 0;
		}
	}

	for(int i=0; i<num; i++) {
		printf("%d %d\n", x[i], y[i]);
	}
	return 0;
}