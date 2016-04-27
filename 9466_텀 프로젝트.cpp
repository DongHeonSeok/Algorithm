#include <cstdio>
#include <stack>
using namespace std;
int A[100100];
int V[100100];
void init(int N)
{
	for (int i = 0; i <= N; i++) {
		A[i] = V[i] = 0;
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		stack <int> s;
		int N;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
		}
		int step = 1;
		int ans = 0;
		for (int i = 1; i <= N; i++) {
			if (V[i] == -1) continue;
			int idx = i;
			V[idx] = step;
			s.push(idx);
			while (!s.empty()) {
				int x = A[s.top()];
				if (idx == x) {
					while (!s.empty()) {
						ans++;
						V[s.top()] = -1;
						s.pop();
					}
					break;
				}
				if (V[x] == step || V[x] == -1) {
					V[idx] = -1;
					break;
				}
				V[x] = step;
				s.push(x);
			}
			while (!s.empty())
				s.pop();
			step++;
		}
		printf("%d\n", N - ans);
		init(N);
	}
	return 0;
}