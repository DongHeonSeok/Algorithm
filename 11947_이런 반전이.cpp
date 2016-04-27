#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

long long inv(long long num)
{
	long long temp = 0;
	long long ret = 0;
	long long pos = 0;
	long long len = 0;
	while(num!=0) {
		
		len = pow((double)10, pos);

		temp = num%10;
		
		ret += (9-temp)*len;
		pos++;
		num = num/10;
		

	}
	return ret;

}
int first(long long num)
{
	int ret = 0;

	while(num!=0) {
		ret = num%10;
		num = num/10;
	}
	return ret;
}
int len(long long num)
{
	int ret = 0;
	while(num!=0) {
		ret++;
		num = num/10;
	}
	return ret;
}
int main()
{
	int T;
	scanf("%d", &T);

	while(T--) {
		long long N;
		scanf("%lld", &N);
		
		long long max = 0;
		
		int num = first(N);
		if(num<=4) {
			printf("%lld\n", N * inv(N));
		}
		else {
			long long half = 5 * pow((double)10, len(N)-1);
			printf("%lld\n", half * inv(half));
		}	
	}

	return 0;
}
