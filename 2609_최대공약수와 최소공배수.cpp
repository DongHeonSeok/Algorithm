#include <cstdio>

using namespace std;

int gcd(int x, int y)
{
	if(y==0) {
		return x;
	}
	else {
		return gcd(y, x%y);
	}
}
int main()
{
	int N, M;

	scanf("%d %d", &N, &M);

	int g = gcd(N, M);
	int l = g*(N/g)*(M/g);

	printf("%d %d\n", g, l);

	return 0;
}
