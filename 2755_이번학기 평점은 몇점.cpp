#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

int main()
{
	int N;

	string str[101];
	scanf("%d", &N);
	cin.ignore();
	double ans = 0;
	double score = 0;
	double sum = 0;
	for (int i = 0; i < N; i++) {
		string a;
		int b;
		string c;
		cin >> a;
		cin >> b;
		cin >> c;
		score += b;
		double val = 0;
		if (c[0] == 'A') {
			if (c[1] == '+') {
				val = 4.3;

			}
			else if (c[1] == '0') {
				val = 4.0;

			}
			else if (c[1] == '-') {
				val = 3.7;

			}
		}
		else if (c[0] == 'B') {
			if (c[1] == '+') {
				val = 3.3;

			}
			else if (c[1] == '0') {
				val = 3.0;

			}
			else if (c[1] == '-') {
				val = 2.7;

			}
		}
		else if (c[0] == 'C') {
			if (c[1] == '+') {
				val = 2.3;

			}
			else if (c[1] == '0') {
				val = 2.0;

			}
			else if (c[1] == '-') {
				val = 1.7;

			}
		}
		else if (c[0] == 'D') {
			if (c[1] == '+') {
				val = 1.3;

			}
			else if (c[1] == '0') {
				val = 1.0;

			}
			else if (c[1] == '-') {
				val = 0.7;

			}
		}
		else {
			val = 0.0;
		}

		sum += (double)(val * b);


	}

	ans = sum / score + 0.001;
	printf("%.2f\n", ans);

	return 0;
}

