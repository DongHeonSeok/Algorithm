#include <iostream>
#include <cstdio>
using namespace std;
int map[2010][2010];
int N;
bool seed(int y, int x, int d) 
{
	int sum = 0;
	for(int i= y-d; i<=y+d; i++) {
		for(int j = x-d; j<=x+d; j++) {
			sum += map[i][j];
		}
	}
	if(4*d + 1 == sum) return true;
	else return false;
}
int main()
{
	int ans = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(i>0 || i<=N-2 || j>0 || j<=N-2) {
				if(map[i][j] && map[i-1][j] && map[i+1][j] && map[i][j+1] && map[i][j-1]) {
					for (int d = 1; d <= N/2; d++) {
						if(seed(i, j, d))
							ans++;
						else break;
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}