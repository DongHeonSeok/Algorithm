#include <cstdio>
using namespace std;

int x[110];
int y[110];
int d[110];

void quick(int start, int end, int arr1[], int arr2[])
{
	int p = arr1[(start + end) / 2];
	int s = start;
	int e = end;

	while (s <= e) {
		while (arr1[s] < p && s <= e) s++;
		while (p < arr1[e] && s <= e) e--;

		if (s <= e) {
			int tmp = arr1[s];
			arr1[s] = arr1[e];
			arr1[e] = tmp;

			tmp = arr2[s];
			arr2[s] = arr2[e];
			arr2[e] = tmp;

			s++, e--;
		}
	}
	if (start < e)quick(start, e, arr1, arr2);
	if (s < end) quick(s, end, arr1, arr2);
}

bool CHK(int a, int b)
{
	if (x[a] <= x[b] && y[a] <= y[b])
		return true;
	else if (x[a] <= y[b] && y[a] <= x[b])
		return true;
	else
		return false;
}
int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a > b) {
			x[i] = a;
			y[i] = b;
		}
		else {
			x[i] = b;
			y[i] = a;
		}
	}
	quick(0, N - 1, x, y);
	
	int same = 0;
	for (int i = 0; i < N; i++) {
		if (x[i] == x[i + 1])
			same++;
		else if (same != 0) {
			quick(i - same, i, y, x);
			same = 0;
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		d[i] = 1;
		for (int j = 0; j <i; j++) {
			if (CHK(j, i) && d[j] + 1 > d[i]) {
				d[i] = d[j] + 1;
				if (d[i]>ans)
					ans = d[i];
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}