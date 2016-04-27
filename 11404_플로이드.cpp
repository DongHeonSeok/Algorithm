#include <cstdio>
using namespace std;
int d[110][110];
void floyd(int N)
{
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j)continue;
				if (d[i][k] != 0 && d[k][j] != 0) {
					if (d[i][j] == 0 || d[i][j] > d[i][k] + d[k][j])
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
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);

		if (d[x][y] != 0 && d[x][y]>z)
			d[x][y] = z;
		else if(d[x][y] == 0)
			d[x][y] = z;
	}

	floyd(N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}


	return 0;
}