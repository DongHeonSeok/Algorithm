#include <cstdio>
using namespace std;
int a[50];
int main()
{
	int n;
	scanf("%d", &n);

	a[0] = 0;
	a[1] = 1;

	for (int i = 2; i <= n; i++) {
		a[i] = a[i - 1] + a[i - 2];
	}

	printf("%d\n", a[n]);



	return 0;
}