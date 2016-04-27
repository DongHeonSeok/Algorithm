#include <iostream>

using namespace std;
int num[300001] = { 0, };
int d[300002] = { 0, };

int main()
{
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	int pos = num[0];
	int count = 1;

	for (int i = 1; i<N; i++) {
		if (pos<num[i])
			count++;
	}
	if (count == N) {
		cout << N << endl;
	}
	else {
		cout << N - count << endl;
	}
	return 0;
}