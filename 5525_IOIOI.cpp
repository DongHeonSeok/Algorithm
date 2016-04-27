#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string s;
string a;
int idx[1000100];
int main()
{
	int N, S;
	cin >> N >> S;
	cin >> s;
	
	a += "IOI";

	for (int i = 1; N >= 2 && i < N; i++) {
		a += "OI";
	}
	int pos = 0;
	for (int i = 2; i < s.length(); i++) {
		if (s[i - 2] == 'I' && s[i - 1] == 'O' && s[i] == 'I') {
			idx[pos] = i - 2;
			pos++;
		}
	}
	pos = 0;
	int x = 0;
	int len = 2 * N + 1;
	int count = 0;
	while (1) {
		if (idx[pos] == 0)
			break;
		bool possible = true;
		x = 0;
		for (int i = idx[pos]; i < idx[pos] + len; i++) {
			if (s[i] != a[x]) {
				possible = false;
				break;
			}
			x++;
		}
		if (possible)
			count++;
		pos++;
	}
	cout << count;

	return 0;
}