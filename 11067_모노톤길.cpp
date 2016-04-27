#include <cstdio>
using namespace std;
int x[100010];
int y[100010];
int idx[100010][2];
const int init = 0x7fffffff;
void quick1(int start, int end, int arr1[], int arr2[])
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

			s++; e--;
		}
	}
	if (start < e) quick1(start, e, arr1, arr2);
	if (s < end) quick1(s, end, arr1, arr2);
}
void quick2(int start, int end, int arr1[], int arr2[])
{
	int p = arr1[(start + end) / 2];
	int s = start;
	int e = end;
	while (s <= e) {
		while (arr1[s] > p && s <= e) s++;
		while (p > arr1[e] && s <= e) e--;

		if (s <= e) {
			int tmp = arr1[s];
			arr1[s] = arr1[e];
			arr1[e] = tmp;

			tmp = arr2[s];
			arr2[s] = arr2[e];
			arr2[e] = tmp;
			s++; e--;
		}
	}
	if (start < e) quick2(start, e, arr1, arr2);
	if (s < end) quick2(s, end, arr1, arr2);
}
void find(int N)
{
	for (int i = 0; i < N; i++) {
		if (idx[x[i]][0] == init)
			idx[x[i]][0] = y[i];
		else if (idx[x[i]][0] > y[i])
			idx[x[i]][0] = y[i];

		if (idx[x[i]][1] == init)
			idx[x[i]][1] = y[i];
		else if (idx[x[i]][1] < y[i])
			idx[x[i]][1] = y[i];
	}
}
void sort(int N)
{
	int same = 0, pos = 0;
	bool flag = false;
	for (int i = 0; i < N; i++) {
		if (x[i] == x[i + 1]) {
			if (!flag)
				pos = i;
			flag = true;
			same++;
		}
		else if (same != 0) {
			if (idx[x[i]][0] == y[pos - 1])
				quick1(i - same, i, y, x);
			else if (idx[x[i]][1] == y[pos - 1])
				quick2(i - same, i, y, x);
			same = 0;
			flag = false;
		}
	}
}
void output(int m)
{
	int z;
	for (int i = 0; i < m; i++) {
		scanf("%d", &z);
		printf("%d %d\n", x[z - 1], y[z - 1]);
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		for (int i = 0; i < 100010; i++) {
			idx[i][0] = idx[i][1] = init;
		}
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &x[i], &y[i]);
		}

		quick1(0, N - 1, x, y);
		find(N);
		sort(N);

		int m;
		scanf("%d", &m);
		output(m);
	}
	return 0;
}