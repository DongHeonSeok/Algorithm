#include <cstdio>
#include <string.h>
#include <math.h>
using namespace std;

int main()
{
	char str[1001];
	int B;

	scanf("%s %d", str, &B);

	int len = strlen(str);
	int sum = 0;
	
	for(int i=0; i<len; i++) {
		if(str[i]>=48 && str[i]<=57) {
			sum += pow((double)B, len-1-i) * (str[i]-'0');
		}
		else {
			sum += pow((double)B, len-1-i) * (str[i]-55);
		}
	}
	printf("%d\n", sum);

	return 0;
}
