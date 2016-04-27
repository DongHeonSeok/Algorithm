#include <cstdio>
using namespace std;
int m[3000][3000];
int cnt[4];
bool same(int y, int x, int N)
{
	for (int i = y; i < y + N; i++) {
		for (int j = x; j < x + N; j++) {
			if (m[y][x] != m[i][j])
				return false;
		}
	}
	return true;
}
void solve(int y, int x, int N)
{
	if (same(y, x, N)) {
		cnt[m[y][x] + 1]++;
		return;
	}
	int M = N / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			solve(y + i * M, x + j * M, M);
		}
	}
}
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &m[i][j]);
		}
	}
	solve(0, 0, N);

	for (int i = 0; i < 3; i++) {
		printf("%d\n", cnt[i]);
	}

	return 0;
}