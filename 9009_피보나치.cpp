#include <iostream>
#include <cstdio>

using namespace std;
int fibo[100];
int ans[100];
int main()
{
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		int idx = 0;
		scanf("%d", &n);
		int a = 0,b=1;
		for(int i=0; i<100; i++) {
			if(a>n)
				break;
			fibo[i] = a;
			int temp = a+b;
			a = b;
			b = temp;
			idx = i;
		}
		int sum = n;
		int pos = 0;
		bool end = false;
		for(int i=idx; i>=1; i--) {
			sum -= fibo[i];
			ans[pos] = fibo[i];
			for(int j = i-1; j>=0; j--) {
				sum -= fibo[j];
				if(sum<0) {
					sum += fibo[j];
				}
				else if(sum>0) {
					pos++;
					ans[pos] = fibo[j];
				}
				else if(sum==0) {
					pos++;
					ans[pos] = fibo[j];
					end = true;
					break;
				}
			}
			if(end)
				break;
		}
		for(int i=pos; i>=0; i--) {
			if(ans[i]!=0) {
				printf("%d ", ans[i]);
			}
		}
		printf("\n");
	}
	return 0;
}