#include <cstdio>
using namespace std;
int m[60][60];
int c[60][60];
int q[100000][2];
int N;

int main()
{
	scanf("%d ", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%1d ", &m[i][j]);
		}
	}

	int front = 0;
	int rear = 0;
	q[front][0] = 1;
	q[front][1] = 1;
	c[1][1] = 1;

	while (front <= rear) {
		int ypos = q[front][0];
		int xpos = q[front][1];

		if (xpos + 1 <= N && (c[ypos][xpos + 1] == 0 || c[ypos][xpos + 1] > c[ypos][xpos])) {
			if (m[ypos][xpos + 1] == 0) {
				c[ypos][xpos + 1] = c[ypos][xpos] + 1;
			}
			else
				c[ypos][xpos + 1] = c[ypos][xpos];
			rear++;
			q[rear][0] = ypos;
			q[rear][1] = xpos + 1;
		}
		if (ypos - 1 > 0 && (c[ypos - 1][xpos] == 0 || c[ypos - 1][xpos] > c[ypos][xpos])) {
			if (m[ypos - 1][xpos] == 0) {
				c[ypos - 1][xpos] = c[ypos][xpos] + 1;
			}
			else
				c[ypos - 1][xpos] = c[ypos][xpos];
			rear++;
			q[rear][0] = ypos - 1;
			q[rear][1] = xpos;
		}
		if (xpos - 1 > 0 && (c[ypos][xpos - 1] == 0 || c[ypos][xpos - 1] > c[ypos][xpos])) {
			if (m[ypos][xpos - 1] == 0) {
				c[ypos][xpos - 1] = c[ypos][xpos] + 1;
			}
			else
				c[ypos][xpos - 1] = c[ypos][xpos];
			rear++;
			q[rear][0] = ypos;
			q[rear][1] = xpos - 1;
		}
		if (ypos + 1 <= N && (c[ypos + 1][xpos] == 0 || c[ypos + 1][xpos] > c[ypos][xpos])) {
			if (m[ypos + 1][xpos] == 0) {
				c[ypos + 1][xpos] = c[ypos][xpos] + 1;
			}
			else
				c[ypos + 1][xpos] = c[ypos][xpos];
			rear++;
			q[rear][0] = ypos + 1;
			q[rear][1] = xpos;
		}
		front++;
	}
	printf("%d\n", c[N][N]-1);
	return 0;
}