#include <cstdio>
using namespace std;
int x[100100];
int y[100100];
void quick(int start, int end, int x[], int y[])
{
	int p = x[(start + end) / 2];
	int s = start;
	int e = end;
	while (s <= e) {
		while (x[s] < p && s <= e) s++;
		while (p < x[e] && s <= e) e--;
		if (s <= e) {
			int tmp = x[s];
			x[s] = x[e];
			x[e] = tmp;

			tmp = y[s];
			y[s] = y[e];
			y[e] = tmp;

			s++;
			e--;
		}
	}
	if (start < e) quick(start, e, x, y);
	if (s < end) quick(s, end, x, y);
}
int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	quick(0, N - 1, y, x);
	
	int same = 0;
	for (int i = 0; i < N; i++) {
		if (y[i] == y[i + 1])
			same++;
		else if (same != 0) {
			quick(i - same, i, x, y);
			same = 0;
		}
	}
	int idx = 0;
	int ans = 0;
	int val = -1;
	while (idx < N) {
		if (x[idx] >= val) {
			val = y[idx];
			ans++;
		}
		idx++;
	}
	printf("%d", ans);
	return 0;
}