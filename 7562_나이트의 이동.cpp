#include <cstdio>
#include <queue>
using namespace std;
int m[310][310];
int c[310][310];
struct pos
{
	int x;
	int y;
};
queue<pos> q;
int sx, sy;
int fx, fy;
int N;
void init(int N)
{
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			m[i][j] = c[i][j] = 0;
		}
	}
	while (!q.empty()) {
		q.pop();
	}
}
void bfs(int y, int x)
{
	pos p;
	p.x = x;
	p.y = y;
	q.push(p);
	
	while (!q.empty()) {
		pos temp;
		temp.x = q.front().x;
		temp.y = q.front().y;
		q.pop();
		if (temp.y == fy && temp.x == fx)
			break;
		if ((temp.x - 2 >= 0 && temp.y - 1 >=0) && c[temp.y - 1][temp.x - 2] == 0) {
			p.x = temp.x - 2;
			p.y = temp.y - 1;
			q.push(p);
			c[temp.y - 1][temp.x - 2] = c[temp.y][temp.x] + 1;
		}
		if ((temp.x - 1 >= 0 && temp.y - 2 >=0) && c[temp.y - 2][temp.x - 1] == 0) {
			p.x = temp.x - 1;
			p.y = temp.y - 2;
			q.push(p);
			c[temp.y - 2][temp.x - 1] = c[temp.y][temp.x] + 1;
		}
		if ((temp.x + 2 < N && temp.y - 1 >= 0) && c[temp.y - 1][temp.x + 2] == 0) {
			p.x = temp.x + 2;
			p.y = temp.y - 1;
			q.push(p);
			c[temp.y - 1][temp.x + 2] = c[temp.y][temp.x] + 1;
		}
		if ((temp.x + 1 < N && temp.y - 2 >= 0) && c[temp.y - 2][temp.x + 1] == 0) {
			p.x = temp.x + 1;
			p.y = temp.y - 2;
			q.push(p);
			c[temp.y - 2][temp.x + 1] = c[temp.y][temp.x] + 1;
		}
		if ((temp.x - 2 >= 0 && temp.y + 1 < N) && c[temp.y + 1][temp.x - 2] == 0) {
			p.x = temp.x - 2;
			p.y = temp.y + 1;
			q.push(p);
			c[temp.y + 1][temp.x - 2] = c[temp.y][temp.x] + 1;
		}
		if ((temp.x - 1 >= 0 && temp.y + 2 < N) && c[temp.y + 2][temp.x - 1] == 0) {
			p.x = temp.x - 1;
			p.y = temp.y + 2;
			q.push(p);
			c[temp.y + 2][temp.x - 1] = c[temp.y][temp.x] + 1;
		}
		if ((temp.x + 1 < N && temp.y + 2 < N) && c[temp.y + 2][temp.x + 1] == 0) {
			p.x = temp.x + 1;
			p.y = temp.y + 2;
			q.push(p);
			c[temp.y + 2][temp.x + 1] = c[temp.y][temp.x] + 1;
		}
		if ((temp.x + 2 < N && temp.y + 1 < N) && c[temp.y + 1][temp.x + 2] == 0) {
			p.x = temp.x + 2;
			p.y = temp.y + 1;
			q.push(p);
			c[temp.y + 1][temp.x + 2] = c[temp.y][temp.x] + 1;
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		scanf("%d %d", &sx, &sy);
		scanf("%d %d", &fx, &fy);

		bfs(sy, sx);
		printf("%d\n", c[fy][fx]);
		init(N);
	}
	return 0;
}