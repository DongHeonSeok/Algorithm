#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int c[500010];
int main()
{
	int N; 
	scanf("%d", &N);
	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());
	int M;
	scanf("%d", &M);
	vector<int> b(M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &b[i]);
	}

	int count = 0;
	while (count != M) {
		int left = 0;
		int right = N - 1;
		int mid = 0;
		while (left <= right) {
			mid = (left + right) / 2;
			if (a[mid] == b[count]) {
				for (int i = mid; i<=right; i++) {
					if (a[i] == b[count])
						c[count]++;
					else if(a[i]>b[count])
						break;
				}
				for (int i = left; i < mid; i++) {
					if (a[i] == b[count])
						c[count]++;
					else if(a[i]>b[count])
						break;
				}
				break;
			}
			else if (a[mid]>b[count]) {
				right = mid - 1;
			}
			else if (a[mid] < b[count]) {
				left = mid + 1;
			}
		}
		count++;

	}
	for (int i = 0; i < M; i++) {
		printf("%d ", c[i]);
	}



	return 0;
}