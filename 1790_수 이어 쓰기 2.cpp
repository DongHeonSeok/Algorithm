#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

int length(int N)
{
	int ret = 0;
	while(1) {
		if(N==0) 
			break;
		N /= 10;
		ret++;
	}
	return ret;
}
int main()
{
	int N, k;
	int len = 0;
	scanf("%d %d", &N, &k);
	int temp = 0;
	len = length(N);
	int total = 0;
	for(int i=0; i<len-1; i++) {
		total += (9 * pow((double)10, i)) * (i+1);
	}
	temp = pow((double)10, len-1);

	temp = N - temp + 1;

	total = total + (temp * len);

	if(total<k)
		printf("-1\n");
	else {
		int diff = total-k;
		int ans = 0;
		len = length(N);
		int check = pow((double)10, len-1);
		for(int i=N; i>=1; i--) {
			if(i%check == i) {
				len--;
				check = pow((double)10, len-1);
			}
				
			if(diff>=len) {
				diff -= len;
			}
			else if(diff<len) {
				while(diff!=-1) {
					ans = i % 10;
					i = i/10;
					diff--;
				}
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
