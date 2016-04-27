#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
	int start, end, cost;
	bool operator < (const Edge &other) const {
		return cost < other.cost;
	}
};
int p[1010];
int Find(int x) {
	if (x == p[x]) return x;
	else return p[x] = Find(p[x]);
}
void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	p[y] = x;
}
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		p[i] = i;
	}
	vector<Edge> a(M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a[i].start, &a[i].end, &a[i].cost);
	}
	sort(a.begin(), a.end()); //cost별 정렬
	int ans = 0;
	for (int i = 0; i<M; i++) {
		Edge e = a[i];
		int x = Find(e.start);
		int y = Find(e.end);
		if (x != y) {//부모 노드를 찾아서 다르면 합치고 cost 더한다.
			Union(e.start, e.end);
			ans += e.cost;
		}
	}
	printf("%d\n", ans);
	return 0;
}