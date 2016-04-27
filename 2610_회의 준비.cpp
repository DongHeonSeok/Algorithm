#include <cstdio>
#include <algorithm>
using namespace std;
int d[110][110];
int a[110];
int s[110];
int r[110];
int p[110][3];
void floyd(int N)
{
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j<=N; j++) {
				if (d[i][k] != 0 && d[k][j] != 0) {
					if (i == j) continue;
					if (d[i][j] == 0 || d[i][j] > d[i][k] + d[k][j])
						d[i][j] = d[i][k] + d[k][j];
					
				}
			}
		}
	}
}
int Find(int x)
{
	if (x == a[x]) return x;
	else return a[x] = Find(a[x]);
}
void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	//if (x == y) return;
	if (r[x] > r[y]) swap(x, y);
	a[x] = y;
	if (r[x] == r[y]) r[y]++; //많이 가중치를 가진 인덱스를 중심으로 연결
}
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		a[i] = i;
		p[i][0] = 0x7fffffff;
	}
	for (int i = 0; i < M; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		d[x][y] = d[y][x] = 1;
		Union(x, y);
	}
	for (int i = 1; i <= N; i++) {
		Find(i);
	}
	floyd(N);

	for (int i = 1; i <= N; i++) {
		int idx = a[i];
		int sum = 0;
		int max = 0;
		for (int j = 1; j <= N; j++) {
			sum += d[i][j];	
		}
		if (p[idx][0] > sum) {
			p[idx][0] = sum;
			p[idx][1] = i;
		}
	}
	
	int idx = 0;
	for (int i = 1; i <= N; i++) {
		if (p[i][0] != 0x7fffffff) {
			s[idx] = p[i][1];
			idx++;
		}
	}	
	if (idx == 1) {
		printf("1\n3\n");
	}
	else{
		sort(s, s + idx);
		int ac = 1;
		printf("%d\n", idx);
		for (int i = 0; i < idx; i++) {
			printf("%d\n", s[i]);
		}
	}
	return 0;
}