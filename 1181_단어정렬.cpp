#include <iostream>
#include <cstdio>

using namespace std;

char data[20001][51];
int len[20001];
int pos[20001];
void swap(int index1, int index2)
{
	int temp = pos[index1];
	pos[index1] = pos[index2];
	pos[index2] = temp;
}

int L(int index)
{
	int ret = 0;
	int pos = 0;
	while(data[index][pos]!='\0') {
		ret++;
		pos++;
	}

	return ret;
}
int C(int index1, int index2)
{
	int pos = 0;
	bool check = false;
	while(data[index1][pos]!='\0') {
		if(data[index1][pos] > data[index2][pos]) {
			return 1;
		}
		else if(data[index1][pos] < data[index2][pos]) {
			return 0;
		}
		pos++;
	}
	return 2;
}

void quick(int start, int end, int arr[], int arr2[])
{
	int p = arr[(start + end)/2];
	int s = start;
	int e = end;

	while(s<=e) {
		while(arr[s]<p && s<=e) s++;
		while(p<arr[e] && s<=e) e--;

		if(s<=e) {
			int tmp = arr[s];
			arr[s] = arr[e];
			arr[e] = tmp;

			tmp = arr2[s];
			arr2[s] = arr2[e];
			arr2[e] = tmp;
			s++;
			e--;
		}
	}
	if(start<e)
		quick(start, e, arr, arr2);
	if(s<end)
		quick(s, end, arr, arr2);
}
int main()
{
	int N;
	scanf("%d", &N);

	for(int i=0; i<N; i++) {
		scanf("%s", data[i]);
		len[i] = L(i);
		pos[i] = i;
	}

	quick(0, N-1, len, pos);

	int same = 0;
	for(int i=0; i<N; i++) {
		if(len[i] == len[i+1]) {
			same++;
		}
		else if(same!=0) {
			for(int j=i-same; j<=i-1; j++) {
				for(int k=j+1; k<=i; k++) {
					if(pos[j] == 20001)
						continue;
					int check = C(pos[j], pos[k]);
					if(check==1) {
						swap(j,k);
					}
					else if(check==2) {
						pos[j] = 20001;
					}
				}
			}
			same = 0;
		}
	}
	for(int i=0; i<N; i++) {
		int index = pos[i];
		if(index == 20001)
			continue;
		printf("%s\n", data[index]);
	}

	return 0;
}
