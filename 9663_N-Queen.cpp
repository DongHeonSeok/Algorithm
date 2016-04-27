#include <iostream>
#include <cstdio>

using namespace std;
int m[16][16];
int N;
int cnt = 0;
int dy[3] = {1, 1, 1};
int dx[3] = {-1, 0, 1};
void queen(int col)
{
	for(int i=1; i<=N; i++) {
		if(m[col][i]) continue;

		for(int j=0; j<3; j++) {
			int ypos = col;
			int xpos = i;
			while(1) {
				ypos += dy[j];
				xpos += dx[j];
				if(ypos<=N && xpos >=1 && xpos<=N) {
					m[ypos][xpos]++;
				}
				else
					break;
			}
		}
		if(col==N) cnt++;
		else queen(col+1);

		for(int j=0; j<3; j++) {
			int ypos = col;
			int xpos = i;
			while(1) {
				ypos += dy[j];
				xpos += dx[j];

				if(ypos<=N && xpos>=1 && xpos<=N) {
					m[ypos][xpos]--;
				}
				else
					break;
			}
		}
	}
}
int main()
{
	scanf("%d", &N);
	queen(1);
	printf("%d\n", cnt);
	return 0;
}
