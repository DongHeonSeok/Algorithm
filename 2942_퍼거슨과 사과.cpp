#include <cstdio>
using namespace std;
int p[1000];
int gcd(int x, int y)
{
	if (y == 0) {
		return x;
	}
	else {
		return gcd(y, x%y);
	}
}
int main()
{
	int R, G;
	scanf("%d %d", &R, &G);
	int g = gcd(R, G);
	int idx = 0;
	for (int i = 1; i*i <= g; i++) {
		if (g%i == 0) {
			p[idx] = i;
			idx++;
			if (g / i != i) {
				p[idx] = g / i;
				idx++;
			}
		}
	}
	for (int i = 0; i < idx; i++) {
		printf("%d %d %d\n", p[i], R / p[i], G / p[i]);
	}
	return 0;
}