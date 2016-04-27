#include <cstdio>
using namespace std;

int main()
{
	int A, B, C, D, P;
	scanf("%d %d %d %d %d", &A, &B, &C, &D, &P);
	int a = P*A;
	int b = 0;
	if (P <= C) 
		b = B;
	else 
		b += (B + (P-C)*D);
	
	if (a > b)
		printf("%d", b);
	else
		printf("%d", a);

	return 0;
}