#include<stdio.h>
int n, k;
int main(){
	scanf("%d %d", &n, &k);
	int s = 0;
	for (;;){
		int cnt = 0;
		
		for (int i = n; i; i -= i&-i) 
			cnt++;
		if (cnt <= k) break;
		s += n&-n;
		n += n&-n;
	}
	printf("%d", s);
	return 0;
}