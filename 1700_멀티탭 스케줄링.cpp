#include <iostream>
#include <cstdio>
int data[101];
int plug[101][2];
int count = 0;
void init(int N, int K)
{
	int top = 0;
	for(int i=0; i<K; i++) {
		bool exist = false;
		if(top==N)
			break;
		else {
			int val = data[i];
			
			for(int j=0; j<top; j++) {
				if(plug[j][0] == val)
					exist = true;
			}
			if(!exist) {
				plug[top][0] = data[i];
				plug[top][1] = i;
				top++;
			}
		}
	}
}
bool check(int val, int index, int N, int K)
{
	for(int i=0; i<N; i++) {
		if(plug[i][0] == val)
			return true;
	}
	return false;
}
void update(int val, int index, int N, int K)
{
	bool exist = false;
	for(int i=0; i<N; i++) {
		exist = false;
		for(int j=index+1; j<=K; j++) {
			if(plug[i][0] == data[j]) {
				plug[i][1] = j;
				exist = true;
				break;
			}
		}
		if(!exist)
			plug[i][1] = K;
	}
	int max = 0;
	int pos = 0;
	for(int i=0; i<N; i++) {
		if(plug[i][1]>max) {
			max = plug[i][1];
			pos = i;
		}
	}
	plug[pos][0] = val;
	count++;

}
int main()
{
	int N, K;

	scanf("%d %d", &N, &K);

	for(int i=0; i<K; i++) {
		scanf("%d", &data[i]);
	}

	init(N, K);
	for(int i=N; i<K; i++) {
		int val = data[i];
		if(check(val, i, N, K))
			continue;
		else {
			update(val, i, N, K);
		}
	}

	printf("%d\n", count);
	return 0;
}