#include <iostream>
#include <cstdio>

using namespace std;

char map[51][51];
int x[51];
int y[51];
int main()
{
	int N, M;
	int xcnt = 0, ycnt = 0; 
	scanf("%d %d", &N, &M);
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			scanf(" %c", &map[i][j]);
		}
	}

	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			char c = map[i][j];
			if(c == 'X') {
				if(x[j] == 0) {
					xcnt++;
				}
				if(y[i] == 0) {
					ycnt++;
				}
				x[j]++;
				y[i]++;
			}
		}
	}

	if(N-ycnt>M-xcnt) {
		printf("%d\n", N-ycnt);
	}
	else {
		printf("%d\n", M-xcnt);
	}



	return 0;
}