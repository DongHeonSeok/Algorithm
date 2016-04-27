#include <cstdio>
using namespace std;
int a[50];
int d[50];
int main()
{
	d[0] = 1, d[1] = 1;
	for (int i = 2; i <= 40; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}
	for (int i = 1; i <= 40; i++) {
		a[i] = i;
	}
	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int x;
		scanf("%d", &x);
		a[x] = 0;
	}
	int cnt = 0;
	int ans = 1;
	for (int i = 1; i <= N; i++) {
		if (a[i] != 0)
			cnt++;
		else {
			ans *= d[cnt];
			cnt = 0;
		}
		if (i == N)
			ans *= d[cnt];
	}
	printf("%d", ans);

	return 0;
}