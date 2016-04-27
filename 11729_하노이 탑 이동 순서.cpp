#include <cstdio>
using namespace std;
void solve(int N, int x, int y)
{
	if (N == 0)
		return;
	solve(N - 1, x, 6 - x - y);
	printf("%d %d\n", x, y);
	solve(N - 1, 6 - x - y, y);
}
int main()
{
	int N;
	scanf("%d", &N);
	int total = (1 << N) - 1;
	printf("%d\n", total);
	solve(N, 1, 3);

	return 0;
}