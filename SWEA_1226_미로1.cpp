#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;
int ans;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int map[17][17];
int map2[17][17]; //0 안지남 1 지남.

void find_ans(int x, int y) {
	//printf("x,y: %d %d\t", x, y);
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < 16 && ny >= 0 && ny < 16) {
			if (map2[nx][ny] != 1 && map[nx][ny] != 1) {
				if (map[nx][ny] == 3) {
					ans = 1;
					return;
				}
				map2[nx][ny] = 1;
				//printf("nx,ny: %d %d\n", nx, ny);
				find_ans(nx, ny);
			}
		}
		
	}
}
int main() {
	for (int i = 0; i < 10; i++) {
		int n;
		scanf("%d", &n);
		
		int sx, sy;
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) {
				scanf("%1d", &map[i][j]);
				if (map[i][j] == 0) {
					map2[i][j] = 0;
				}
				else if (map[i][j] == 1) {
					map2[i][j] = 1;
				}
				else if (map[i][j] == 2) {
					map2[i][j] = 1;
					sx = i; sy = j;
				}
				else if (map[i][j] == 3) {
					map2[i][j] = 0;
				}
			}
		}

		ans = 0;
		find_ans(sx, sy);
		printf("#%d %d\n", n, ans);

	}
	//system("pause");
	return 0;
}