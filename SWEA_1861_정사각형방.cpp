#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

int map[1001][1001];
int dist[1000001];

int n;
int moving;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
void dfs(int x, int y, int temp) {
	moving = temp;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (map[nx][ny] == map[x][y] + 1) {
				dfs(nx, ny, temp + 1);
			}
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		scanf("%d", &n);
		
		memset(map, 0, sizeof(map));
		memset(dist, 0, sizeof(dist));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {				
				scanf("%d", &map[i][j]);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dfs(i, j, 0);
				//printf("%d %d %d\n", i, j, cnt);
				dist[map[i][j]] = moving;
			}
		}
		
		int door; int max = -1;
		for (int i = 1000000; i >= 0; i--) {
			if (max <= dist[i]) {
				max = dist[i];
				door = i;
			}
		}
		printf("#%d %d %d\n", t, door, max+1);
	}

	system("pause");
	return 0;
}
