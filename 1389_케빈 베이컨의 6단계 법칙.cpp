#include <cstdio>
using namespace std;
int d[110][110];
int a[110];
void floyd(int N)
{
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j<=N; j++) {
				if (i == j) continue;
				if (d[i][k] != 0 && d[k][j] != 0) {
					if (d[i][j] == 0 || d[i][j]>d[i][k] + d[k][j])
						d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
}
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		d[x][y] = d[y][x] = 1;
	}
	floyd(N);
	int min = 0x7fffffff;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			a[i] += d[i][j];
		}
		if (min>a[i])
			min = a[i];
	}
	for (int i = 1; i <= N; i++) {
		if (a[i] == min) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}