#include<iostream>
#include<stdio.h>
#include<stack>

using namespace std;

int main() {
	for (int t = 1; t <= 10; t++) {
		int length, ans=1;
		scanf("%d ", &length);

		stack<char> s;

		char munja[100000];
		scanf("%s", munja);

		
		for (int i = 0; i < length; i++) {
			char c = munja[i];
			//printf("i:%d ", i);
			if (c == '{' || c == '[' || c == '(' || c == '<') {
				s.push(c);
			}
			else if (s.size() == 0) {
				ans = 0;
			}
			else {
				char temp = s.top();
				s.pop();
				switch (temp) {
				case '{':
					if (c != '}') {
						ans = 0;
					}
					break;
				case '[':
					if (c != ']') {
						ans = 0;
					}
					break;
				case '(':
					if (c != ')') {
						ans = 0;
					}
					break;
				case '<':
					if (c != '>') {
						ans = 0;
					}
					break;
				default:
					break;
				}
			}
			
			if (ans == 0) {
				break;
			}
		}
		printf("#%d %d\n", t, ans);
	
	}
	//system("pause");
	return 0;
}