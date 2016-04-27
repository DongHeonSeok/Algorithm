#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
	int N, M;
	int arr[11] = { 0, };
	int ans = 0;
	scanf("%d", &N);

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int x;
		scanf("%d", &x);
		arr[x] = 1;
	}
	ans = N - 100;
	if (ans < 0) {
		ans = -ans;
	}
	int min_len = 0;
	for (int i = 1;  i <= 1000000; i++) {
		int len = 0;
		bool ok = true;
		int num = i;
		while (num > 0) {
			if (arr[num % 10] == 1) {
				ok = false;
				break;
			}
			num /= 10;
			len++;
		}
		if (ok) {
			num = N - i >= 0 ? N - i : -(N - i);
			num = num + len;
			if (num < ans) {
				ans = num;
			}
		}
	}
	
	if (arr[0] == 0) {
		if (ans > N + 1) {
			ans = N + 1;
		}
	}
	printf("%d\n", ans);
	


	return 0;
}



