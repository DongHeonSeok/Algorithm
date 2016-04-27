#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	char str[1000] = {0, };
	char alpha[27] = {0, };
	int N, B;
	scanf("%d %d", &N, &B);
	int pos = 0;
	for(int i=0; i<26; i++) {
		alpha[i] = 'A' + i;
	}
	while(1) {
		if(N==0) {
			break;
		}
		int val = N%B;
		if(val>=10) {
			str[pos] = alpha[val-10];
		}
		else {
			str[pos] = val + '0';
		}
		N = N/B;
		pos++;

	}
	for(int i=pos-1; i>=0; i--) {
		printf("%c", str[i]);
	}

	return 0;
}