#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> a;
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}
	for (int i = 0; i < M; i++) {
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < (int)a.size(); i++) {
		printf("%d ", a[i]);
	}
	return 0;
}