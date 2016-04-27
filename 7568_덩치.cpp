#include <iostream>
#include <cstdio>

using namespace std;


int main()
{
	int N;
	int arr[51][3];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
		arr[i][2] = N;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				if (arr[i][0] >= arr[j][0] || arr[i][1] >= arr[j][1]) {
					arr[i][2] -= 1;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i][2]);
	}

	
	
	return 0;
}