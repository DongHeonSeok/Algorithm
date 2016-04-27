#include <iostream>
#include <cstdio>
#include <math.h>
 
using namespace std;
 
int f(int N, int c, int r) {
    if (N == 0) {
        return 0;
    }
    if (c < pow(2, N-1)) {
        if (r < pow(2, N-1)) {
            return f(N-1, c, r);
        } else {
            return pow(2, 2*N-2) + f(N-1, c, r - pow(2, N-1));
        }
    } else {
        if (r < pow(2, N-1)) {
            return pow(2, 2*N-1) + f(N-1, c - pow(2, N-1), r);
        } else {
            return 3 * pow(2, 2*N-2) + f(N-1, c - pow(2, N-1), r - pow(2, N-1));
        }
    }
}
 
int main() {
    int N, c, r;
    while(cin >> N >> c >> r) {
        cout << f(N, c, r) << endl;
    }
 
    return 0;
}