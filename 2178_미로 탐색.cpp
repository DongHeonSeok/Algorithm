#include <iostream>
#include <cstdio>
using namespace std;
char map[101][101] = { 0, };
int check[101][101] = { 0, };
int N, M;
struct queue
{
	int x;
	int y;
};

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &map[i][j]);
		}
	}

	queue q[10001];

	int front = 0;
	int rear = 0;
	q[front].x = 0;
	q[front].y = 0;
	check[0][0] = 1;
	while (front <= rear) {
		int x = q[front].x;
		int y = q[front].y;

		if (x == M - 1 && y == N - 1) {
			break;
		}

		if (x - 1 >= 0 && map[y][x - 1] == '1' && check[y][x - 1] == 0) {
			check[y][x-1] = check[y][x] + 1;
			rear++;
			q[rear].x = x - 1;
			q[rear].y = y;
		}

		if (y - 1 >= 0 && map[y - 1][x] == '1' && check[y - 1][x] == 0) {
			check[y - 1][x] = check[y][x] + 1;
			rear++;
			q[rear].x = x;
			q[rear].y = y - 1;
		}
		if (x + 1 <= M-1 && map[y][x + 1] == '1' && check[y][x + 1] == 0) {
			check[y][x + 1] = check[y][x] + 1;
			rear++;
			q[rear].x = x + 1;
			q[rear].y = y;
		}
		if (y + 1 <= N-1 && map[y + 1][x] == '1' && check[y + 1][x] == 0) {
			check[y + 1][x] = check[y][x] + 1;
			rear++;
			q[rear].x = x;
			q[rear].y = y + 1;
		}

		front++;
	}
	
	cout << check[N - 1][M - 1] << endl;
	


	return 0;
}