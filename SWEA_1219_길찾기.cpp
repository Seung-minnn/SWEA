#include<stdio.h>
#include<iostream>
#include<stack>

#define MAX 100
using namespace std;

int main() {
	for (int t = 0; t < 10; t++) {
		int map[MAX];
		int map2[MAX];
		memset(map, -1, sizeof(map));
		memset(map2, -1, sizeof(map2));

		int n, ans=0, branch;
		scanf("%d %d", &n, &branch);

		for (int i = 0; i < branch; i++) {
			int t1, t2;
			scanf("%d %d", &t1, &t2);

			if (map[t1] == -1) {
				map[t1] = t2;
			}
			else if (map2[t1] == -1) {
				map2[t1] = t2;
			}
		}

		stack<int> s;
		s.push(0);
		while (!s.empty()) {
			int temp = s.top();
			//printf("temp: %d\n", temp);
			if (temp == 99) {
				ans = 1;
				break;
			}

			if (map[temp] != -1) {
				s.push(map[temp]);
				map[temp] = -1;
			}
			else if (map2[temp] != -1) {
				s.push(map2[temp]);
				map2[temp] = -1;
			}
			else {
				s.pop();
			}
		}

		printf("#%d %d\n", n, ans);
	}
	
	

	
	system("pause");
	return 0;
}