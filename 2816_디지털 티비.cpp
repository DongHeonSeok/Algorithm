#include <iostream>
#include <vector>
#include <string>
using namespace std;
void go(vector<string> &a, string channel, int goal, int &cur) {
	while (a[cur] != channel) {
		cout << '1';
		cur += 1;
	}
	while (cur != goal) {
		swap(a[cur], a[cur - 1]);
		cout << '4';
		cur -= 1;
	}
}
int main() {
	int n;
	cin >> n;
	vector<string> a(n);
	for (int i = 0; i<n; i++) {
		cin >> a[i];
	}
	int cur = 0;
	go(a, "KBS1", 0, cur);
	go(a, "KBS2", 1, cur);
	cout << '\n';
	return 0;
}