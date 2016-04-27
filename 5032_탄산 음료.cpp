#include <iostream>

using namespace std;

int main()
{
	int e, f, c;

	cin >> e >> f >> c;

	int sum = e + f;

	int temp = sum;
	int count = 0;

	while (sum != 0) {

		count += sum / c;

		sum = sum / c + sum % c;
		if (sum < c)
			sum = 0;

	}

	cout << count << endl;

	return 0;
}
