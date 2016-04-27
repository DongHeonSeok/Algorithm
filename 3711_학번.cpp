#include <iostream>

using namespace std;

int human[301] = { 0, };
int check[1000001] = { 0, };
int main()
{
	int T;

	cin >> T;

	while (T--) {
		int N; 
		cin >> N;

		
		for (int i = 0; i < N; i++) {
			cin >> human[i];
		}
		bool possible = true;
		for (int m = 1; m < 1000000; m++) {
			possible = true;

			for (int i = 0; i < N; i++) {
				int val = human[i] % m;

				if (check[val]) {
					possible = false;
					break;
				}
				else {
					check[val] = 1;
				}
			}

			if (possible) {
				cout << m << endl;
				for (int i = 0; i < N; i++) {
					check[human[i] % m] = 0;
				}
				break;
			}
			else {
				for (int i = 0; i < N; i++) {
					check[human[i] % m] = 0;
				}
			}
		}
	}

	return 0;
}