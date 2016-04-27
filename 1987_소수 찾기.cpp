#include <iostream>
#include <cstdio>

using namespace std;

bool check[1000000] = {0, };

int main()
{
	check[1] = true;
	for(int i=2; i<=1000000; i++) {
		if(check[i] == false) {
			for(int j=2*i; j<=1000000; j+=i) {
				check[j] = true;
			}
		}
	}
	int N, M;;

	scanf("%d %d", &N, &M);

	for(int i=N; i<=M; i++) {
		if(check[i]==false)
			printf("%d\n", i);
	}
	return 0;
}