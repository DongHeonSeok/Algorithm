#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int num[100001] = { 0, };

int check[3000] = { 0, };
int ans[3000] = { 0, };
int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		
		if (x < 0) {
			check[1000 + x] = 1;
		}
		else {
			check[1000 + x] = 1;
		}
	}
	int count = 0;
	int pos = 0;
	while (pos<3000) {
		if (check[pos] != 0) {
			int num = pos - 1000;
			if (pos < 1000) {
				ans[count] = (1000 - pos) * -1;
			}
			else {
				ans[count] = pos - 1000;
			}
			
			count++;
		}
		pos++;
	}

	sort(ans, ans + count);

	for (int i = 0; i < count; i++) {
		printf("%d ", ans[i]);
	}
	


	return 0;
}