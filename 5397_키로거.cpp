#include <iostream>
#include <cstdio>

using namespace std;
char L[1000001];
char A[2000001];
char B[2000001];
int main()
{
	int T;
	scanf("%d", &T);

	while(T--) {
		scanf("%s", L);

		int index = 0;
		int atop = -1;
		int btop = -1;
		char word = 0;
		while(L[index]!='\0') {
			word = L[index];

			if( (word>='0' && word<='9') || (word>='a' && word<='z') || (word>='A' && word<='Z') ) {
				A[++atop] = L[index];
			}
			else if(word=='>') {
			
				if(btop>=0) {
					A[++atop] = B[btop];
					B[btop] = '\0';
					btop--;
				}
			}
			else if(word=='<') {
				if(atop>=0) {
					B[++btop] = A[atop];
					A[atop] = '\0';
					atop--;
				}
			}
			else if(word=='-') {
				if(atop>=0) {
				atop--;
				}
			}
			index++;
		}
		if(btop!=-1) {
			for(int i=btop; i>=0; i--) {
				A[++atop] = B[i];
			}
		}
		for(int i=0; i<atop+1; i++) {
			if(A[i]!='\0')
				printf("%c", A[i]);
		}
		printf("\n");
		for(int i=0; i<index; i++) {
			A[i] = '\0';
			B[i] = '\0';
		}
	}
	return 0;
}