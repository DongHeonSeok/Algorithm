#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;
char first[1000001];
char second[46];
int main()
{
	
	//string first = "";
	//string second = "";

	vector<char> v;
	scanf("%s", first);
	scanf("%s", second);
	//cin >> first;
	//cin >> second;

	int pos = 0;
	//int first_len = first.length();
	//int sec_len = second.length();
	int first_len = strlen(first);
	int sec_len = strlen(second);
	char endpoint = second[sec_len - 1];
	
	while (pos<=first_len) {
		if (v.empty()) {
			v.push_back(first[pos]);
			pos++;
		}
		else if (v.back() == endpoint && (int)v.size()>=sec_len) {
			int len = v.size();
			bool possible = true;
			int count = sec_len-1;
			if (len >= sec_len) {
				for (int i = len - 1; i >= len - sec_len && count >= 0; i--) {
					possible = false;
					if (v[i] == second[count]) {
						count--;
						possible = true;
					}
				}
				if (possible && count == -1) {
					for (int i = len - 1; i >= len - sec_len; i--) {
						v.pop_back();
					}
				}
				else {
					v.push_back(first[pos]);
					pos++;
				}
			}
		}
		else {
			v.push_back(first[pos]);
			pos++;
		}
	}
	if ( (int)v.size() == 1 && v[0] == '\0') {
		printf("FRULA\n");
	}
	else {
		for (int i = 0; i < (int)v.size()-1; i++) {
			printf("%c", v[i]);
		}
		printf("\n");
	}
	
	return 0;
}