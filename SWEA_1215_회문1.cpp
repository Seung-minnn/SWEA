#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>

using namespace std;

int main() {
	for (int t = 0; t < 10; t++) {
		int find;
		int ans = 0;
		scanf("%d ", &find);

		char map[9][9];

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
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
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8 - find + 1; j++) {
				for (int k = 0; k < find / 2; k++) {
					if (map[i][j + k] != map[i][(j + find - 1) - k]) {
						break;
					}
					if (k == find / 2 - 1) {
						ans++;
					}
				}
			}
		}

		//세로검사
		for (int j = 0; j < 8; j++) {
			for (int i = 0; i < 8; i++) {
				for (int k = 0; k < find / 2; k++) {
					if (map[i + k][j] != map[(i + find - 1) - k][j]) {
						break;
					}
					if (k == find / 2 - 1) {
						ans++;
					}
				}
			}
		}
		printf("#%d %d\n", t + 1, ans);
	}
	//system("pause");
	return 0;
}