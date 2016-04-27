#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {

	int N, K;
	int sum = 0;
	int mid = 0;
	int left = 0;
	int right = 0;

	cin >> K >> N;

	vector <long long> a(K);

	for (int i = 0; i < K; i++) {
		cin >> a[i];
		if (sum < a[i]) {
			sum = a[i];
		}
	}
	long long answer = 0LL;
	right = sum;
	left = 0;
	long long count = 0LL;
	while (left <= right) {
		mid = (left + right) / 2;

		for (int i = 0; i < K; i++) {
			count += a[i] / mid;
		}

		if (count >= N) {
			if (answer < mid)
				answer = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
		count = 0;
	}

	cout << answer << endl;
	return 0;
}