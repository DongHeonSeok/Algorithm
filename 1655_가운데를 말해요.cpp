#include <iostream>
#include <cstdio>

using namespace std;
int A[20001];
int ans[100001];
int main()
{
	int N;
	int count = 0;
	int index = -1;
	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		int num;
		int j;
		scanf("%d", &num);
		A[num+10000]++;
		for(count=0, j=0; j<=20000; j++) {
			count += A[j];
			if(count > i/2) {
				ans[++index] = j-10000;
				break;
			}
		}
		//printf("%d\n", j-10000);
	}
	for(int i=0; i<=index; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}

