#include <iostream>
#include <cstdio>

using namespace std;
int data[1001][3];
int memo[1001][3];

int m(int a, int b)
{
	if(a<b)
		return a;
	else
		return b;
}
int main()
{
	int N;
	scanf("%d", &N);

	for(int i=0; i<N; i++) {
		scanf("%d %d %d", &data[i][0], &data[i][1], &data[i][2]);
	}
	memo[0][0] = data[0][0];
	memo[0][1] = data[0][1];
	memo[0][2] = data[0][2];

	for(int i=1; i<N; i++) {
		memo[i][0] = m(memo[i-1][1], memo[i-1][2]) + data[i][0];
		memo[i][1] = m(memo[i-1][0], memo[i-1][2]) + data[i][1];
		memo[i][2] = m(memo[i-1][0], memo[i-1][1]) + data[i][2];
	}
	int min = 0x7fffffff;

	for(int i=0; i<3; i++) {
		if(min>memo[N-1][i])
			min = memo[N-1][i];
	}

	printf("%d\n", min);
			



	return 0;
}