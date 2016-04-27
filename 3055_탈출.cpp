#include <cstdio>
#include <queue>
using namespace std;
struct pos
{
	int x;
	int y;
	int cost;
};

char m[60][60];
int v[60][60];
int w[60][60];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
queue <pos> q; //°í½¿µµÄ¡

int R, C;
void water(int step)
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (m[i][j] == '*' && w[i][j]!=step) {
				for (int k = 0; k < 4; k++) {
					int x = dx[k] + j;
					int y = dy[k] + i;
					if (x < 0 || y < 0 || x >= C || y >= R) continue;
					if (m[y][x] == '.') {
						m[y][x] = '*';
						w[y][x] = step;
					}
				}
			}
		}
	}
}
int main()
{
	scanf("%d %d ", &R, &C);
	int x, y, cost;
	int fx, fy;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%1c ", &m[i][j]);
			if (m[i][j] == 'S') {
				x = j;
				y = i;
			}
			if (m[i][j] == 'D') {
				fx = j;
				fy = i;
			}
		}
	}
	pos p;
	p.x = x;
	p.y = y;
	p.cost = 0;
	q.push(p);
	int step = 1;
	int check = 0;
	int ans = -1;
	while (!q.empty()) {

		p = q.front();
		x = p.x;
		y = p.y;
		cost = p.cost;
		q.pop();
		
		if (x == fx && y == fy) {
			ans = cost;
			break;
		}
		for (int i = 0; i < 4; i++) {
			if (m[y][x] == '*') break;
			int xpos = x + dx[i];
			int ypos = y + dy[i];
			if (xpos < 0 || ypos < 0 || xpos >= C || ypos >= R) continue;
			if ((m[ypos][xpos] == '.' || m[ypos][xpos] == 'D') && v[ypos][xpos] == 0) {
				v[ypos][xpos] = 1;
				p.x = xpos;
				p.y = ypos;
				p.cost = cost + 1;
				q.push(p);
			}
		}
		if (q.front().cost != check) {
			water(step);
			step++;
			check++;
		}
		if (q.empty())
			break;
	}
	if (ans == -1)
		printf("KAKTUS");
	else
		printf("%d", ans);
	return 0;
}