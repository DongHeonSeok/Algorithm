#include <iostream>
#include <cstdio>

using namespace std;

struct queue
{
	int x;
	int y;
};


int map[3][3];
bool check[3][3];
int val[3][3];
int a[100];
int b[100];
int search[3][3];
int main()
{
	int x, y;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) {
				x = j;
				y = i;
			}
		}
	}
	queue q[1000];
	
	int front = 0;
	int rear = 0;
	q[front].x = x;
	q[front].y = y;
	check[y][x] = true;
	bool possible = false;
	a[x] = 0;
	b[y] = 0;
	//0을 옮겨서 (2,2)까지 돌려서 최소 횟수 찾기
	while (front <= rear) {
		int pos_x = q[front].x;
		int pos_y = q[front].y;
		if (pos_x == 2 && pos_y == 2) {
			break;
		}
		if (pos_y - 1 >= 0 && check[pos_y - 1][x] == false) {
			rear++;
			q[rear].y = pos_y - 1;
			q[rear].x = pos_x;
			check[pos_y - 1][pos_x] = true;
			val[pos_y - 1][pos_x] = val[pos_y][pos_x] + 1;
			int ret = val[pos_y - 1][pos_x];
			a[ret] = pos_x;
			b[ret] = pos_y;
			
		}
		if (pos_y + 1 < 3 && check[pos_y + 1][x] == false) {
			rear++;
			q[rear].y = pos_y + 1;
			q[rear].x = pos_x;
			check[pos_y + 1][pos_x] = true;
			val[pos_y + 1][pos_x] = val[pos_y][pos_x] + 1;
			int ret = val[pos_y + 1][pos_x];
			a[ret] = pos_x;
			b[ret] = pos_y;
		}
		if (pos_x - 1 >= 0 && check[pos_y][pos_x - 1] == false) {
			rear++;
			q[rear].y = pos_y;
			q[rear].x = pos_x - 1;
			check[pos_y][pos_x - 1] = true;
			val[pos_y][pos_x - 1] = val[pos_y][pos_x] + 1;
			int ret = val[pos_y][pos_x-1];
			a[ret] = pos_x;
			b[ret] = pos_y;
		}
		if (pos_x + 1 < 3 && check[pos_y][pos_x + 1] == false) {
			rear++;
			q[rear].y = pos_y;
			q[rear].x = pos_x + 1;
			check[pos_y][pos_x + 1] = true;
			val[pos_y][pos_x + 1] = val[pos_y][pos_x] + 1;
			int ret = val[pos_y][pos_x+1];
			a[ret] = pos_x;
			b[ret] = pos_y;
		}

		front++;
	}
	a[val[2][2] + 1] = 2;
	b[val[2][2] + 1] = 2;

	for (int i = 1; i < val[2][2] + 1; i++) {
		int temp = map[b[i]][a[i]];
		map[b[i]][a[i]] = map[b[i + 1]][a[i + 1]];
		map[b[i + 1]][a[i + 1]] = temp;


	}
	int ac = 1;
	return 0;
}