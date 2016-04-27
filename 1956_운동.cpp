#include <cstdio>
using namespace std;

int d[410][410];
void floyd(int N)
{
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) continue;
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
	int V, E;
	scanf("%d %d", &V, &E);
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (i == j) d[i][j] = 0;
			else d[i][j] = 987654321;
		}
	}
	for (int i = 0; i < E; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		d[x][y] = z;
	}
	floyd(V);
	
	int min = 987654321;
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (i != j)
				if (min>d[i][j] + d[j][i]) 
					min = d[i][j] + d[j][i];
		}
	}
	if (min == 987654321)
		printf("-1\n");
	else
		printf("%d\n", min);

	return 0;
}

