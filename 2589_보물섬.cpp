#include <cstdio>
using namespace std;

char m[51][51];
int c[51][51];
int q[4000][2];
int N, M;
void func(int y, int x)
{
	int front = 0;
	int rear = 0;
	q[front][0] = y;
	q[front][1] = x;
	c[y][x] = 1;
	while (front <= rear) {
		int ypos = q[front][0];
		int xpos = q[front][1];

		if (ypos > 0 && m[ypos - 1][xpos] == 'L' && c[ypos - 1][xpos] == 0) {
			rear++;
			q[rear][0] = ypos - 1;
			q[rear][1] = xpos;
			c[ypos - 1][xpos] = c[ypos][xpos] + 1;
		}
		if (ypos < N - 1 && m[ypos + 1][xpos] == 'L' &&c[ypos + 1][xpos] == 0) {
			rear++;
			q[rear][0] = ypos + 1;
			q[rear][1] = xpos;
			c[ypos + 1][xpos] = c[ypos][xpos] + 1;
		}
		if (xpos > 0 && m[ypos][xpos - 1] == 'L' && c[ypos][xpos - 1] == 0) {
			rear++;
			q[rear][0] = ypos;
			q[rear][1] = xpos - 1;
			c[ypos][xpos - 1] = c[ypos][xpos] + 1;
		}
		if (xpos < M - 1 && m[ypos][xpos + 1] == 'L' && c[ypos][xpos + 1] == 0) {
			rear++;
			q[rear][0] = ypos;
			q[rear][1] = xpos + 1;
			c[ypos][xpos + 1] = c[ypos][xpos] + 1;
		}

		front++;
	}
}
int check()
{
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j<M; j++) {
			if (c[i][j]>ret)
				ret = c[i][j];
			c[i][j] = 0;
		}
	}
	for (int i = 0; i < 4000; i++) {
		q[i][0] = 0;
		q[i][1] = 0;
	}
	return ret;
}
int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %1c", &m[i][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (m[i][j] == 'L') {
				func(i, j);
				int val = check();
				if (val > ans)
					ans = val;
			}
		}
	}
	printf("%d\n", ans-1);

	return 0;
}