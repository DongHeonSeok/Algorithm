/*

VCPP, GPP에서 사용

*/

#include <iostream>
#include <cstdio>

using namespace std;
int d[21];
int m[21];
int a[22][22];
int main()
{
	int z;
	cin >> z;
	
	for(int bi=0; bi<3; bi++) {
		int N, M;
		scanf("%d %d", &N, &M);

		for (int i = 0; i < 21; i++) {
			d[i] = 0;
			m[i] = 0;
		}
		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < 21; j++) {
				a[i][j] = 0;
			}
		}
		for (int i = 0; i < M; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			a[x][y] = a[y][x] = 1;
		}
		int tmp = 2;
		int total = 1;
		for (int i = 1; i <= N; i++) {
			total = total * tmp;
		}

		for (int i = 0; i < N; i++) {
			d[i] = i + 1;
		}
		int pos = 0;
		int ans = 0;
		for (int i = 0; i < (1 << N) && M != 0; i++) {
			pos = 0;
			for (int j = 0; j < N; j++) {
				if (i&(1 << j)) {
					printf("%d ", d[j]);
					m[pos] = d[j];
					pos++;
					
				}
			}
			printf("\n");
			bool possible = true;
			if (pos >= 2) {
				for (int k = 0; k < pos-1; k++) {
					for (int l = k + 1; l < pos; l++) {
						if (a[m[k]][m[l]] == 1) {
							possible = false;
							ans++;
							break;
						}
					}
					if (!possible)
						break;
				}
				
			}		
		}
		cout << "#testcase" << (bi + 1) << endl;
		printf("%d\n", total-ans);
	}
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}
