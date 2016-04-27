#include <cstdio>
using namespace std;
int m[110][110];
int t[110][110];
int N, M;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
void update(int y, int x)
{
	if (m[y][x] != 1) {
		for (int i = 0; i < 4; i++) {
			int ypos = y + dy[i];
			int xpos = x + dx[i];
			if (ypos < 0 || ypos >= N || xpos < 0 || xpos >= M) continue;
			if (m[ypos][xpos] != 0) continue;
			m[ypos][xpos] = 2;
			update(ypos, xpos);
		}
	}
}
int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &m[i][j]);
		}
	}
	int sum = 0;
	int time = 1;
	while(1) {
		update(0, 0);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (m[i][j] == 1) {
					int count = 0;
					if (i > 0 && m[i - 1][j] == 2) count++;
					if (i < N - 1 && m[i + 1][j] == 2) count++;
					if (j > 0 && m[i][j - 1] == 2) count++;
					if (j < M - 1 && m[i][j + 1] == 2) count++;

					if (count >= 2) {
						t[i][j] = 0;
						m[i][j] = 0;
					}
					else {
						t[i][j] = 1;
					}
				}
			}
		}
		sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				m[i][j] = t[i][j];
				sum += t[i][j];
			}
		}
		if (sum == 0)
			break;
		time++;
	}
	printf("%d\n", time);
	return 0;
}