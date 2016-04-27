#include <iostream>
#include <cstdio>

using namespace std;

long long A[100001];
long long B[100001];
int main()
{
	int N;
	scanf("%d", &N);

	for(int i=1; i<=N; i++) {
		scanf("%lld", &A[i]);
	}
	for(int i=1; i<N; i++) {
		scanf("%lld", &B[i]);
	}

	long long x = 1;
	long long y = 0;

	for(int i=1; i<=N; i++) {
		long long xx = (x*A[i] + x*B[i-1] + y * A[i] + (B[i-1]-1) * y) % 1000000007;
		long long yy = (x*B[i] + y*B[i]) % 1000000007;
		x = xx;
		y = yy;
	}
	printf("%lld\n", x);

	return 0;
}