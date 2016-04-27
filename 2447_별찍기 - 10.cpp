#include <cstdio>
using namespace std;
char m[3000][3000];
void solve(int y, int x, int N, int type)
{
	if (type == 0) {
		for (int i = y; i < y + N; i++) {
			for (int j = x; j < x + N; j++) {
				m[i][j] = ' ';
			}
		}
	}
	else {
		if (N == 1)
			m[y][x] = '*';
		else {
			type = 1;
			int c = N / 3;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (i == 1 && j == 1) type = 0;
					else type = 1;
					solve(y + i*c, x + j*c, c, type);
				}
			}
		}
	}
}
int main()
{
	int N;
	scanf("%d", &N);

	solve(0, 0, N, 1);
	
	for (int i = 0; i < N; i++) {
		printf("%s\n", m[i]);
	}
	return 0;
}