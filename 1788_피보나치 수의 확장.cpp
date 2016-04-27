#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int a = 0, b = 1, c=0, n, t=0;
    scanf("%d", &n);
    if (n > 0) t = 1;
    if (n < 0) {
        n *= -1;
        if (n % 2 == 0) t = -1;
        else t = 1;
         
    }
    for (int i = 2; i <= n; i++) {
        c = (a + b) % 1000000000;
        a = b; b = c;
    }
    if (n == 1) c = 1;
    if (n == 0) c = 0;
    printf("%d\n%d\n",t,c);
    return 0;
}