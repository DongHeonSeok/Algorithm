#include <iostream>
#include <cstdio>

using namespace std;
int arr[1000001];
int b[1000002];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		b[arr[i]] = i;
	}

	int count = 1;
	int max = 0;
	for (int i = 0; i < N; i++) {
		int num = arr[i];
		int next = 0;
		while (1) {
			if (num>N || b[num] > b[num + 1]) {
				break;
			}
			num = num + 1;
			count++;
		}
		if (max < count)
			max = count;
		count = 1;
	}
	
	printf("%d", N - max);
	return 0;
}