#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

char str[110];

int main()
{
	scanf("%s", str);

	int max = 0;
	int len = strlen(str);
	int R, C;
	for(R=1; R<=len; R++) {
		if(len%R==0) {
			int C = len/R;
			if(R<=C) {
				if(R>max)
					max = R;
			}
			else
				break;
		}
	}
	R = max;
	C = len/R;

	int index = 0;
	for(int i=0; i<R; i++) {
		index = i;
		while(1) {
			if(index>len-1)
				break;
			printf("%c", str[index]);
			index += R;
		}
	}

	return 0;
}