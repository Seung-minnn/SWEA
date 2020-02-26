#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

int ticket[4]; //1day, 1month, 3month, 1year
int month[12];

queue<pair<int, int>> q;
int main() {
	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		for (int i = 0; i < 4; i++) {
			scanf(" %d", &ticket[i]);
		}
		for (int i = 0; i < 12; i++) {
			scanf(" %d", &month[i]);
		}

		int ans = 987654321;
		q.push({ 0, 0 });
		while (!q.empty()) {
			int m = q.front().first;
			int n = q.front().second;
			q.pop();

			if (m > 11) {
				if (ans > n) {
					ans = n;
				}
				continue;
			}

			//1day
			int temp= ticket[0]*month[m];
			q.push({ m + 1,n + temp });
			
			//1month
			q.push({ m + 1,n + ticket[1] });

			//3month
			q.push({ m + 3,n + ticket[2] });

			//1year
			q.push({ m + 12,n + ticket[3] });
		}
		
		printf("#%d %d\n", t, ans);
	}
	system("pause");
	return 0;
}
