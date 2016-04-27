#include <cstdio>
#include <iostream>
using namespace std;

long long gcd(long long x, long long y)
{
	if(y==0) {
		return x;
	}
	else {
		return gcd(y, x%y);
	}
}

int main()
{

	long long a, b;
    cin >> a >> b;
    long long g = gcd(a, b);
    for (int i=0; i<g; i++) {
        cout << '1';
    }
    cout << '\n';
    return 0;
	
}