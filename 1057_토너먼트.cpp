#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int N, a, b, i;

	scanf("%d %d %d", &N, &a, &b);

	for(i=0; a!=b; i++) {
		a = a - a/2;
		b = b - b/2;
	}
	printf("%d\n", i);
	return 0;
}