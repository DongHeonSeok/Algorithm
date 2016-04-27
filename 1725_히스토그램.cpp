#include <cstdio>
#include <stack>
using namespace std;
stack <long long> s;

int main()
{
	
		long long A[100010];
		int N;
		scanf("%d", &N);
		
		for (int i = 0; i < N; i++) {
			scanf("%lld", &A[i]);
		}
		int i = 0;
		long long max = 0LL;
		long long val = 0LL;
		long long left = 0LL;
		for (i = 0; i < N; i++) {

			while (!s.empty() && A[s.top()] > A[i]) {
				long long idx = s.top();
				s.pop();
				if (!s.empty()) left = s.top();
				else left = -1;
				val = A[idx] * (i - left - 1);
				if (val > max)
					max = val;
			}
			s.push(i);
		}
		while (!s.empty()) {
			long long idx = s.top();
			s.pop();
			if (!s.empty()) left = s.top();
			else left = -1;
			val = A[idx] * (i - left - 1);
			if (val > max)
				max = val;
		}
		printf("%lld\n", max);
	
	return 0;
}