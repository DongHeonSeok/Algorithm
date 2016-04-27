#include <iostream>
#include <cstdio>
#include <string.h>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	string A = "";
	string B = "";

	cin >> A;
	cin >> B;

	int c_A = A.length();
	int c_B = B.length();

	if (c_A < c_B) {
		cout << "no" << endl;
	}
	else {
		cout << "go" << endl;
	}





	return 0;
}