#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
vector<int> v[10010];
int c[10010];
int t[10010];
int a[10010];
int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		int n, idx;
		scanf("%d", &t[i]);
		scanf("%d", &n);
		if (n != 0) {
			for (int j = 0; j < n; j++) {
				int x;
				scanf("%d", &x);
				v[x].push_back(i);
				c[i]++;
			}
		}
	}
	queue<int> q;
	for (int i = 1; i <= N; i++) {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
		if (c[i] == 0) {
			q.push(i);
			a[i] = t[i];
		}
	}
	for (int i = 1; i <= N; i++) {
		int x = q.front();
		q.pop();
		
		for (int j = 0; j < (int)v[x].size(); j++) {
			int y = v[x][j];
			c[y]--;
			if (c[y] == 0){
				q.push(y);
			}
			if (a[x] + t[y] > a[y]) {
				a[y] = a[x] + t[y];
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (a[i] > ans)
			ans = a[i];
	}
	printf("%d\n", ans);
	return 0;
}