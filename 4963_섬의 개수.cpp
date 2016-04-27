#include <cstdio>
using namespace std;

int N, M;
int m[51][51];
int c[51][51];
int q[3000][2];
void init()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			m[i][j] = 0;
			c[i][j] = 0;
		}
	}
}
void calc(int y, int x, int count)
{
	int front = 0;
	int rear = 0;
	q[front][0] = y;
	q[front][1] = x;
	c[y][x] = count;
	while (front <= rear) {
		int ypos = q[front][0];
		int xpos = q[front][1];

		if (ypos>0 && m[ypos - 1][xpos] == 1 && c[ypos - 1][xpos] == 0) {
			rear++;
			q[rear][0] = ypos - 1;
			q[rear][1] = xpos;
			c[ypos - 1][xpos] = count;
		}
		if (xpos > 0 && m[ypos][xpos - 1] == 1 && c[ypos][xpos - 1] == 0) {
			rear++;
			q[rear][0] = ypos;
			q[rear][1] = xpos - 1;
			c[ypos][xpos - 1] = count;
		}
		if (ypos < N - 1 && m[ypos + 1][xpos] == 1 && c[ypos + 1][xpos] == 0) {
			rear++;
			q[rear][0] = ypos + 1;
			q[rear][1] = xpos;
			c[ypos + 1][xpos] = count;
		}
		if (xpos < M - 1 && m[ypos][xpos + 1] == 1 && c[ypos][xpos + 1] == 0) {
			rear++;
			q[rear][0] = ypos;
			q[rear][1] = xpos + 1;
			c[ypos][xpos + 1] = count;
		}
		if (ypos > 0 && xpos > 0 && m[ypos - 1][xpos - 1] == 1 && c[ypos - 1][xpos - 1] == 0) {
			rear++;
			q[rear][0] = ypos - 1;
			q[rear][1] = xpos - 1;
			c[ypos - 1][xpos - 1] = count;
		}
		if (ypos > 0 && xpos < M - 1 && m[ypos - 1][xpos + 1] == 1 && c[ypos - 1][xpos + 1] == 0) {
			rear++;
			q[rear][0] = ypos - 1;
			q[rear][1] = xpos + 1;
			c[ypos - 1][xpos + 1] = count;
		}
		if (ypos < N - 1 && xpos>0 && m[ypos + 1][xpos - 1] == 1 && c[ypos + 1][xpos - 1] == 0) {
			rear++;
			q[rear][0] = ypos + 1;
			q[rear][1] = xpos - 1;
			c[ypos + 1][xpos - 1] = count;
		}
		if (ypos < N - 1 && xpos < M - 1 && m[ypos + 1][xpos + 1] == 1 && c[ypos + 1][xpos + 1] == 0) {
			rear++;
			q[rear][0] = ypos + 1;
			q[rear][1] = xpos + 1;
			c[ypos + 1][xpos + 1] = count;
		}
		front++;
	}
}
int main()
{
	while (1) {
		scanf("%d %d", &M, &N);
		if (M == 0 && N == 0)
			break;
		init();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &m[i][j]);
			}
		}
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (m[i][j] == 1 && c[i][j] == 0) {
					count++;
					calc(i, j, count);
				}
			}
		}
		printf("%d\n", count);
	}

	return 0;
}