#include <iostream>
#include <vector>
using namespace std;
int lotto[50] = { 0, };
int N;

void go(int n, vector<int>& ans, int index)
{
	if (n == 0) {
		for (int i = 0; i < (int)ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
		return;
	}
	
	if (index >= N)
		return;

	ans.push_back(lotto[index]);
	go(n - 1, ans, index+1);
	ans.pop_back();
	go(n, ans, index + 1);
	
}
int main()
{
	

	while (1) {
		
		cin >> N;

		if (N == 0) {
			break;
		}
		for (int i = 0; i < N; i++) {
			cin >> lotto[i];
		}
		vector<int> ans;
		go(6, ans, 0);
		cout << endl;
		for (int i = 0; i < 50; i++) {
			lotto[i] = '\0';
		}
	}


	return 0;
}