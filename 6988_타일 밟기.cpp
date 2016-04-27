#include <iostream>
#include <cstdio>

using namespace std;
int data[3001];
int check[1000001];
int main()
{
	int N;
	int max = 0;
	int fin = 0;
	scanf("%d", &N);

	for(int i=0; i<N; i++) {
		scanf("%d", &data[i]);
		check[data[i]] = 1;
	}
	fin = data[N-1];
	int count = 0;
	int sum = 0;
	for(int i=0; i<N-1; i++) {
		int val = data[i];
		for(int j=i+1; j<N; j++) {
			int diff = data[j] - data[i];
			sum = 0;
			count = 0;
			for(int k=val; k<=fin; k+=diff) {
				if(check[k] != 0 && k<=fin) {
					count++;
					sum += k;
				}
				else {
					break;
				}
			}
			if(count>=3) {
				if(sum>max)
					max = sum;
			}
		}
	}
	printf("%d\n", max);

	return 0;
}