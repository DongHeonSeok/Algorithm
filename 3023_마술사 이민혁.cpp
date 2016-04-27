#include <iostream>
#include <cstdio>

using namespace std;

char map[110][110];

void right(int R, int C)
{
	for(int i=0; i<R; i++) {
		for(int j=0; j<C; j++) {
			map[i][2*C - j - 1] = map[i][j];
		}
	}
}
void down(int R, int C)
{
	for(int i=0; i<R; i++) {
		for(int j=0; j<2*C; j++) {
			map[2*R-1-i][j] = map[i][j];
		}
	}
}
int main()
{
	int R, C;

	scanf("%d %d", &R, &C);

	for(int i=0; i<R; i++) {
		for(int j=0; j<C; j++) {
			scanf(" %c", &map[i][j]);
		}
	}
	int A, B;

	scanf("%d %d", &A, &B);

	right(R, C);
	down(R, C);
	
	if(map[A-1][B-1] == '.')
		map[A-1][B-1] = '#';
	else
		map[A-1][B-1] = '.';
	
	
	for(int i=0; i<2*R; i++) {
		for(int j=0; j<2*C; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
