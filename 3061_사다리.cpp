#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int T;
	int line[1001] = { 0, };
	int check[1001] = { 0, };
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int N;
		
		for (int j = 0; j < 1001; j++) {
			line[j] = 0;
			check[j] = 0;
		}

		scanf("%d", &N);

		for (int j = 0; j < N; j++) {
			scanf("%d", &line[j]);
		}

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < j; k++) {
				if (line[j] < line[k]) {
					check[j]++;
				}
			}
		}

		int sum = 0;
		for (int j = 0; j < N; j++) {
			if (check[j] != 0) {
				sum += check[j];
			}
		}

		printf("%d\n", sum);

	}


	return 0;
}