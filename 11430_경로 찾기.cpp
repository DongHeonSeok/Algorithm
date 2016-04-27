#include <cstdio>
using namespace std;
int m[110][110];
int a[110][110];

void floyd(int N)
{
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (m[i][k] != 0 && m[k][j] != 0) {
					if (m[i][j] == 0 || m[i][j] > m[i][k] + m[k][j]) {
						m[i][j] = m[i][k] + m[k][j];
					}
				}
			}
		}
	}
}
int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &m[i][j]);

	floyd(N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (m[i][j] >= 1)
				printf("1 ");
			else
				printf("0 ");
		}
		printf("\n");
	}
	return 0;
}
