/*

VCPP, GPP에서 사용

*/

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int z;
	scanf("%d", &z);
	
	for(int k = 0; k<11; k++) {
		int N; 
		scanf("%d", &N);
		int ans = 0;

		for (int i = 0; i < N; i++) {
			int val;
			scanf("%d", &val);
			int t = 1;
			int a = val / 10;
			int b = val % 10;
			for (int j = 1; j <= b; j++) {
				t = a * t;
			}
			ans += t;
		}
		cout << "#testcase" << (k + 1) << endl;
		printf("%d\n", ans);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}

