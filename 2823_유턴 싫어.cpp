#include <iostream>
#include <cstdio>

using namespace std;
char map[11][11];

int main()
{
	int R, C;
	scanf("%d %d", &R, &C);

	for(int i=0; i<R; i++) {
		for(int j=0; j<C; j++) {
			scanf(" %c", &map[i][j]);
		}
	}
	int count = 0;
	bool possible = true;
	for(int i=0; i<R; i++) {
		count = 0;
		for(int j=0; j<C; j++) {
			count = 0;
			if(map[i][j]=='.') {
				if(i>0 && map[i-1][j] == '.')
					count++;
				if(i<R-1 && map[i+1][j] == '.')
					count++;
				if(j>0 && map[i][j-1] == '.') 
					count++;
				if(j<C-1 && map[i][j+1] == '.')
					count++;
				if(count<=1) {
					printf("1\n");
					return 0;
				}
			}
		}
	}
	
	printf("0\n");
	
	return 0;
}