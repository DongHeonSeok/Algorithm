#include <cstdio>

using namespace std;

int gcd(int x, int y)
{
	if(y==0) {
		return x;
	}
	else {
		return gcd(y, x%y);
	}
}
int main()
{
	int T;
	int data[101] = {0, };
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		int sum = 0;
		int g = 0;
		for(int i=0; i<N; i++) {
			scanf("%d", &data[i]);
		}

		for(int i=0; i<N-1; i++) {
			for(int j=i+1; j<N; j++) {

				int g = gcd(data[i], data[j]);
				sum += g;

			}
		}


		printf("%d\n", sum);

		for(int i=0; i<N; i++) {
			data[i] = 0;
		}


	}

	return 0;
}
