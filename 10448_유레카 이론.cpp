#include <cstdio>

int N;
int T[101];

int f(int n, int s)
{
	if (n == 0) {
		if (s == 0) return 1;
		return 0;
	}

	if (s <= 0) {
		return 0;
	}

	for (int i = 1; i <= 100; i++) {
		if (f(n - 1, s - T[i])) return 1;
	}

	return 0;
}

int main()
{

	for (int i = 1; i <= 100; i++) {
		T[i] = i*(i + 1) / 2;
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &N);
		printf("%d\n", f(3, N));
	}

	return 0;
}