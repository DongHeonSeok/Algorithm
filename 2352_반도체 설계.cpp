#include <cstdio>
#include <algorithm>
using namespace std;
int A[40010];
int D[40010];
int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	int max = 0;
	int idx = 0;
	D[0] = A[0];
	for (int i = 1; i < N; i++) {
		if (D[idx] < A[i]) {
			idx++;
			D[idx] = A[i];
			continue;
		}
		int pos = lower_bound(D, D + idx, A[i])-D;
		D[pos] = A[i];
	}
	printf("%d", idx + 1);
	int ac = 1;
	
	return 0;
}