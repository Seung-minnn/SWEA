#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>

using namespace std;
int map[5][5];
int check[10000000];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void dfs(int x, int y, int n, int cnt) {
	if (cnt == 7) {
		check[n] = 1;
		//printf("b0: (%d,%d) %d %d\n",x,y, n, cnt);
		return;
	}
	else {
		n *= 10;
		n += map[x][y];
		//printf("b1: (%d,%d) %d %d\n", x, y, n, cnt);
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			//printf("b2");
			if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {
				//printf("b2: (%d,%d) %d %d\n", nx, ny, n, cnt);
				dfs(nx, ny, n, cnt+1);
				//printf("b3: (%d,%d) %d %d\n", nx, ny, n, cnt);
			}
		}
	}
}
int main() {
	int tc;
	scanf("%d", &tc);

	for (int i = 1; i <= tc; i++) {
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				scanf("%d", &map[x][y]);
			}
		}

		memset(check, 0, sizeof(check));
		for (int x = 0; x < 4; x++) {
			for (int y = 0; y < 4; y++) {
				//printf("a1 %d %d\n",x,y);
				dfs(x, y, 0, 0);
				//printf("a2\n");
			}
		}
		//printf("a3\n");
		int ans = 0;
		for (int i = 0; i < 10000000; i++) {
			if (check[i] == 1) {
				ans++;
			}
		}
		//printf("a4\n");
		printf("#%d %d\n", i, ans);
	}
	//system("pause");
	return 0;
}