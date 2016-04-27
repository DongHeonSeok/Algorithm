#include <cstdio>
#include <algorithm>
using namespace std;
int M[10100];
int P[10100];
int main()
{
	int N, m = 0, p = 0, zero = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		if (x > 0) {
			P[p] = x;
			p++;
		}
		else if (x < 0) {
			M[m] = x;
			m++;
		}
		else
			zero++;
	}
	sort(P, P + p);
	sort(M, M + m);
	int ans = 0;
	int tmp = 0;
	bool exist = false;
	for (int i = p - 1; i >= 0; i--) {
		if (P[i] == 1)
			ans += 1;
		else {
			if (exist) {
				ans += P[i] * tmp;
				tmp = 0;
				exist = false;
			}
			else {
				tmp = P[i];
				exist = true;
			}
		}
	}
	if (tmp)
		ans += tmp;
	tmp = 0, exist = false;
	for (int i = 0; i < m; i++) {
		if (exist) {
			ans += M[i] * tmp;
			tmp = 0;
			exist = false;
		}
		else {
			tmp = M[i];
			exist = true;
		}
	}
	if (tmp) {
		if (zero <= 0)
			ans += tmp;
	}
	printf("%d", ans);
	
	return 0;
}
