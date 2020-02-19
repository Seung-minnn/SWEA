#include<stdio.h>
#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<cstring>

using namespace std;

char map[2001][2001];
int code[5][5][5];
queue<int> k;
int ans;

int main() {
	int tc;
	bool temp = false;
	scanf("%d", &tc);
	
	memset(code, -1, sizeof(code));
	code[2][1][1] = 0;
	code[2][2][1] = 1;
	code[1][2][2] = 2;
	code[4][1][1] = 3;
	code[1][3][2] = 4;
	code[2][3][1] = 5;
	code[1][1][4] = 6;
	code[3][1][2] = 7;
	code[2][1][3] = 8;
	code[1][1][2] = 9;

	for (int t = 1; t <= tc; t++) {
		int n, m;
		scanf("%d %d ", &n, &m);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char tmp;
				scanf(" %c", &tmp);
				int tmp2;
				switch (tmp) {
				case 'A': tmp2 = 10; break;
				case 'B': tmp2 = 11; break;
				case 'C': tmp2 = 12; break;
				case 'D': tmp2 = 13; break;
				case 'E': tmp2 = 14; break;
				case 'F': tmp2 = 15; break;
				default: tmp2 = tmp - '0'; break;
				}
				int a[4];
				for (int k = 3; k >= 0; k--) {
					a[k] = tmp2 % 2;
					tmp2 /= 2;
				}
				for (int k = 0; k < 4; k++) {
					map[i][j * 4 + k] = a[k];
				}
			}
		}
/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m * 4; j++) {
				printf("%d", map[i][j]);
			}
			printf("\n");
		}
*/
		
		ans = 0;
		for (int i = 1; i < n; i++) {
			int idx = 7;
			int arr[8] = { 0, };
			for (int j = m * 4 - 1; j >= 0; j--) {
				int part[3] = { 0,0,0 };
				if (map[i][j] == 1 && map[i - 1][j] == 0) {
					while (map[i][j] == 1) {
						part[2]++; j--;
					}
					while (map[i][j] == 0) {
						part[1]++; j--;
					}
					while (map[i][j] == 1) {
						part[0]++; j--;
					}
					j++;

					//for (int k = 0; k < 3; k++) {
					//	printf("part[%d]=%d ", k, part[k]);
					//}
				    //printf("\n");

					int min = part[2];
					for (int k = 0; k < 2; k++) {
						if (part[k] < min) {
							min = part[k];
						}
					}
					//printf("min %d, (%d,%d)\n", min, i, j);

					for (int k = 0; k < 3; k++) {
						part[k] /= min;
					//	printf("part[%d]=%d ", k, part[k]);
					}
					//printf("\n");

					arr[idx--] = code[part[0]][part[1]][part[2]];
					//printf("arr[%d]=%d\n", idx + 1, arr[idx + 1]);
					if (arr[idx + 1] == -1) {
						ans = 0;
						break;
					}
					if (idx == -1) {
						int value = (arr[0] + arr[2] + arr[4] + arr[6]) * 3 + arr[1] + arr[3] + arr[5] + arr[7];
						if (value % 10 == 0) {
							for (int k = 0; k < 8; k++) {
								ans += arr[k];
								//printf("Current ans: %d (%d,%d)\n", ans, i, j);
							}
						}
						idx = 7;
						//memset(arr, 0, sizeof(arr));
					}
				}
			}

			//if (ans == 0) {
			//	break;
			//}
		}

		printf("#%d %d\n", t, ans);
		//ansList.clear();
		memset(map, 0, sizeof(map));
	}
	//system("pause");
	return 0;
}
