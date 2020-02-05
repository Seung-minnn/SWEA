#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>

using namespace std;

int main() {
	for (int t = 0; t < 10; t++) {
		int n;
		int ans = -1;
		scanf("%d ", &n);

		char map[101][101];

		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				scanf(" %c", &map[i][j]);
			}
		}
		/*
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
		*/

		//가로검사
		for (int find = 100; find >= 1; find--) {
			for (int i = 0; i < 100; i++) {
				for (int j = 0; j < 100 - find + 1; j++) {
					for (int k = 0; k < find / 2; k++) {
						//printf("find:%d i:%d j:%d k:%d\n", find, i, j, k);
						if (map[i][j + k] != map[i][(j + find - 1) - k]) {
							break;
						}
						if (k == find / 2 - 1) {
							//printf("ans_후보:%d\n", find);
							if (ans < find) {
								ans = find;
							}
						}
					}
				}
			}
		}

		//세로검사
		for (int find = 100; find >= 1; find--) {
			for (int j = 0; j < 100; j++) {
				for (int i = 0; i < 100 - find + 1; i++) {
					for (int k = 0; k < find / 2; k++) {
						if (map[i + k][j] != map[(i + find - 1) - k][j]) {
							break;
						}
						if (k == find / 2 - 1) {
							if (ans < find) {
								ans = find;
							}
						}
					}
				}
			}
		}
		printf("#%d %d\n", n, ans);
	}
	//system("pause");
	return 0;
}