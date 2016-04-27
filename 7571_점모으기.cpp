#include <iostream>
#include <cstdio>
#include <stdlib.h>
int cmp(const void * a, const void * b)
{
	if (*(int*)a <  *(int*)b) return -1;
	if (*(int*)a == *(int*)b) return 0;
	if (*(int*)a >  *(int*)b) return 1;
}
int main()
{
	int n, m;
	int x[100001];
	int y[100001];
	int i, j;
	int px, py;
	scanf("%d%d", &n, &m);
	for (i = 0; i<m; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
	}
	qsort(x, m, 4, cmp);
	qsort(y, m, 4, cmp);
	px = x[m / 2];
	py = y[m / 2];
	int t;
	int s;
	for (s = i = 0; i<m; i++)
	{
		s += abs(px - x[i]) + abs(py - y[i]);
	}
	printf("%d", s);

	return 0;
}