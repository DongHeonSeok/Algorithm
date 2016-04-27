#include <cstdio>
using namespace std;
int m[310][310];
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &m[i][j]);
		}
	}

	int K;
	scanf("%d", &K);

	for (int a = 0; a < K; a++) {
		int i, j, x, y;
		scanf("%d %d %d %d", &i, &j, &x, &y);

		int sum = 0;
		for (int q = i; q <= x; q++) { 
			for (int r = j; r <= y; r++) {
				sum += m[q][r];
			}
		}
		printf("%d\n", sum);
	}

	return 0;
}