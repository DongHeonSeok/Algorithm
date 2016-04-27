#include <cstdio>
using namespace std;
char m[60][60];
int cnt = 1;
int max = 0;
int N;
void swap(int y, int x)
{
	cnt = 1;
	if (x - 1 >= 0) {
		cnt = 1;
		char c = m[y][x];
		m[y][x] = m[y][x - 1];
		m[y][x - 1] = c;
		for (int i = 0; i < N; i++) {
			cnt = 1;
			for (int j = i + 1; j < N; j++) {
				if (m[y][i] == m[y][j]) {
					cnt++;
				}
				else
					break;
			}
			if (cnt > max)
				max = cnt;
		}
		cnt = 1;
		for (int i = 0; i < N; i++) {
			cnt = 1;
			for (int j = i + 1; j < N; j++) {
				if (m[i][x - 1] == m[j][x - 1]) {
					cnt++;
				}
				else
					break;
			}
			if (cnt > max)
				max = cnt;
		}
		c = m[y][x];
		m[y][x] = m[y][x - 1];
		m[y][x - 1] = c;
	}
	if (x + 1 < N) {
		cnt = 1;
		char c = m[y][x];
		m[y][x] = m[y][x + 1];
		m[y][x + 1] = c;
		for (int i = 0; i < N; i++) {
			cnt = 1;
			for (int j = i + 1; j < N; j++) {
				if (m[y][i] == m[y][j]) {
					cnt++;
				}
				else
					break;
			}
			if (cnt > max)
				max = cnt;
		}
		cnt = 1;
		for (int i = 0; i < N; i++) {
			cnt = 1;
			for (int j = i + 1; j < N; j++) {
				if (m[i][x + 1] == m[j][x + 1]) {
					cnt++;
				}
				else
					break;
			}
			if (cnt > max)
				max = cnt;
		}
		c = m[y][x];
		m[y][x] = m[y][x + 1];
		m[y][x + 1] = c;
	}
	if (y + 1 < N) {
		cnt = 1;
		char c = m[y][x];
		m[y][x] = m[y+1][x];
		m[y+1][x] = c;
		for (int i = 0; i < N; i++) {
			cnt = 1;
			for (int j = i + 1; j < N; j++) {
				if (m[y+1][i] == m[y+1][j]) {
					cnt++;
				}
				else
					break;
			}
			if (cnt > max)
				max = cnt;
		}
		cnt = 1;
		for (int i = 0; i < N; i++) {
			cnt = 1;
			for (int j = i + 1; j < N; j++) {
				if (m[i][x] == m[j][x]) {
					cnt++;
				}
				else
					break;
			}
			if (cnt > max)
				max = cnt;
		}
		c = m[y][x];
		m[y][x] = m[y + 1][x];
		m[y + 1][x] = c;
	}
	if (y - 1 >=0) {
		cnt = 1;
		char c = m[y][x];
		m[y][x] = m[y-1][x];
		m[y-1][x] = c;
		for (int i = 0; i < N; i++) {
			cnt = 1;
			for (int j = i + 1; j < N; j++) {
				if (m[y - 1][i] == m[y - 1][j]) {
					cnt++;
				}
				else
					break;
			}
			if (cnt > max)
				max = cnt;
		}
		cnt = 1;
		for (int i = 0; i < N; i++) {
			cnt = 1;
			for (int j = i + 1; j < N; j++) {
				if (m[i][x] == m[j][x]) {
					cnt++;
				}
				else
					break;
			}
			if (cnt > max)
				max = cnt;
		}
		c = m[y][x];
		m[y][x] = m[y - 1][x];
		m[y - 1][x] = c;
	}
}
int main()
{
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1c ", &m[i][j]);
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			swap(i, j);

		}
	}
	
	printf("%d\n", max);
	return 0;
}