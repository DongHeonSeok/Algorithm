#include <iostream>
#include <cstdio>

using namespace std;
bool check[1000001] = {0, };

int main()
{
	for(int i=2; i<=1000000; i++) {
		if(check[i] == false) {
			for(int j=2*i; j<=1000000; j+=i) {
				check[j] = true;
			}
		}
	}
	
	while(1) {
		int num;
		scanf("%d", &num);

		if(num==0)
			break;

		for(int i=num; i>=2; i--) {
			if(check[i]==false && i%2!=0) {
				int val = num-i;
				if(val==1) 
					continue;
				if(check[val]== false && val%2!=0) {
					printf("%d = %d + %d\n", num, val, i);
					break;
				}
			}
		}
	}
	return 0;
}