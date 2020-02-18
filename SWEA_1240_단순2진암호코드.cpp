#include<stdio.h>
#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<cstring>

using namespace std;

char map[51][101];
queue<int> k;

int main() {
	int tc;
	bool temp=false;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		int n, m;
		scanf("%d %d ", &n, &m);
		int ex, ey;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char tmp;
				scanf(" %c", &tmp);
				map[i][j] = tmp - '0';
				if (map[i][j] == 1) {
					temp = true;
					ex = i;
					ey = j;
				}
			}
		}

		//뒤에서부터 거꾸로 출력
		for (int i = ey; i > ey - 56; i--) {
			k.push(map[ex][i]);
			//printf("%d", map[ex][i]);
		}
		//printf("\n");

		string numberList[10] = { "1011000","1001100","1100100","1011110","1100010","1000110","1111010","1101110","1110110","1101000" };
		
		int ans=-1;
		vector<int> ansList;
		while (!k.empty()) {
			int tempRound=-1;

			int t1[7];
			for (int i = 0; i < 7; i++) {
				t1[i] = k.front();
				//printf("%d ", t1[i]);
				k.pop();
			}
			//printf("\n");

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 7; j++) {
					if (t1[j] != numberList[i][j]-'0') {
						break;
					}
					if (j == 6) {
						tempRound = i;
						break;
					}
				}
			}
			//printf("%d\n", tempRound);
			if (tempRound == -1) {
				int ans = 0;
				break;
			}
			
			
			ansList.push_back(tempRound);
		}
		
		if (ans == 0) {
			printf("#%d %d\n", t, ans);
		}
		else {
			int makeAnswer=0;
			for (int i = 1; i < ansList.size(); i++) {
				if (i % 2 == 1) {
					makeAnswer = makeAnswer + ansList[i] * 3;
				}
				else {
					makeAnswer += ansList[i];
				}
			}
			makeAnswer %= 10;
			ans = 0;
			if (ansList[0] == 10 - makeAnswer || makeAnswer==0) {
				for (int i = 0; i < 8; i++) {
					ans += ansList[i];
				}
			}
			printf("#%d %d\n", t, ans);
		}
		
		ansList.clear();
		memset(map, 0, sizeof(map));
	}
	//system("pause");
	return 0;
}