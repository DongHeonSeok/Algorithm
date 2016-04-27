#include <cstdio>
using namespace std;
int X[510];
int Y[510];
int D[510];
void quick(int start, int end, int X[], int Y[])
{
	int p = X[(start + end) / 2];
	int s = start;
	int e = end;
	while (s <= e) {
		while (X[s]<p && s <= e) s++;
		while (p<X[e] && s <= e) e--;
		if (s <= e) {
			int tmp = X[s];
			X[s] = X[e];
			X[e] = tmp;

			tmp = Y[s];
			Y[s] = Y[e];
			Y[e] = tmp;

			s++;
			e--;
		}
	}
	if (start<e) quick(start, e, X, Y);
	if (s<end) quick(s, end, X, Y);
}
int main()
{
	int N;
	scanf("%d", &N);
	int ans = N;
	for (int i = 0; i<N; i++) {
		scanf("%d %d", &X[i], &Y[i]);
	}
	quick(0, N - 1, X, Y);
	int max = 0;
	for (int i = 0; i<N; i++) {
		D[i] = 1;
		for (int j = 0; j<i; j++) {
			if (Y[i]>Y[j] && D[j] + 1 > D[i])
				D[i] = D[j] + 1;
		}
		if (D[i]>max)
			max = D[i];
	}
	printf("%d", N - max);
	return 0;
}