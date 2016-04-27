#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
string a;
string d[1010];
bool cmp(string d)
{
	string t = d;
	int len = t.length();
	reverse(t.begin(), t.end());

	return strcmp(t.c_str(), d.c_str());
}
int main()
{
	cin >> a;
	int min = 0x7fffffff;
	int len = a.length();
	d[0] += a;
	if (cmp(d[0])==0) {
		if (min > d[0].length())
			min = d[0].length();
	}
	for (int i = 0; i < len; i++) {
		d[i+1] += a;
		for (int j = i; j >= 0; j--) {
			d[i+1] += a[j];
		}
		if (cmp(d[i + 1]) == 0) {
			if (min>d[i + 1].length())
				min = d[i + 1].length();
		}
	}
	cout << min << endl;
	return 0;
}