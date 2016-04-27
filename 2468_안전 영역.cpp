#include <cstdio>
using namespace std;
int N;
int m[110][110];
int c[110][110];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
void depth(int a)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (m[i][j] <= a)
				m[i][j] = 0;
		}
	}
}
void check(int y, int x, int count)
{
	if (m[y][x] != 0) {
		for (int i = 0; i < 4; i++) {
			int ypos = y + dy[i];
			int xpos = x + dx[i];
			if (ypos < 0 || ypos >= N || xpos < 0 || xpos >= N) continue;
			if(c[ypos][xpos] != 0 || m[ypos][xpos] == 0) continue;
			c[ypos][xpos] = count;
			check(ypos, xpos, count);
		}
	}
}
void update()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			c[i][j] = 0;
		}
	}
}
int main()
{
	int max = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &m[i][j]);
			if (m[i][j]>max)
				max = m[i][j];
		}
	}
	int count = 0;
	int ans = 0;
	for (int i = 0; i <= max; i++) {
		depth(i);
		update();
		if (count > ans)
			ans = count;
		count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (m[i][j] != 0 && c[i][j]==0) {
					count++;
					check(i, j, count);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}