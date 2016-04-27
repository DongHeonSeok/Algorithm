#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int N;
	scanf("%d ", &N);
	while(N--) {
		char curr = '\0';
		char prev = '\0';
		while(scanf("%c", &curr)!=-1) {
			if(curr=='\n')
				break;
			prev = curr;
		}
		if((prev - '0')%2==0)
			printf("even\n");
		else
			printf("odd\n");
	}
	return 0;
}