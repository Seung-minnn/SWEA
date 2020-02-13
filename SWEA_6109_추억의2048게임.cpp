#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<string.h>

using namespace std;

int map[21][21];

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		int n;
		string s;
		cin >> n >> s;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		if (s == "up") {
			for (int j = 0; j < n; j++) {
				queue<int> q;
				for (int i = 0; i < n; i++) {
					if (map[i][j] == 0) {
						continue;
					}
					q.push(map[i][j]);
				}

				if (q.empty()) {
					continue;
				}

				int cnt = 0;
				int t1 = q.front();
				q.pop();

				/*
				printf("%d열 검사", j);
				for (int l = 0; l < n; l++) {
					printf("%d ", map[l][j]);
				}
				printf("\n");
				*/
				while (cnt != n) {
					//printf("남은 q수: %d\n", q.size());
					if (q.empty()) {
						if (t1 != 0) {
							map[cnt++][j] = t1;
							t1 = 0;
						}
						else {
							map[cnt++][j] = 0;
						}
						continue;
					}
					int t2 = q.front();
					if (q.size() != 1) {
						//printf("t2: %d", t2);
						while (t2 == 0) {
							q.pop();
							t2 = q.front();
							//printf("->%d", t2);
						}
					}
					//printf("\n");
					//printf("%d %d\n", t1, t2);
					if (t1 == 0) {
						t1 = t2;
						q.pop();
					}
					else if (t1 == t2) {
						//printf("cnt %d:%d->", cnt, map[cnt][j]);
						map[cnt++][j] = t1 * 2;
						//printf("%d\n", map[cnt - 1][j]);
						q.pop();
						t1 = 0;
						if (!q.empty()) {
							t1 = q.front();
							q.pop();
						}
					}
					else if (t1 != t2) {
						//printf("cnt %d:%d->", cnt, map[cnt][j]);
						map[cnt++][j] = t1;
						//printf("%d\n", map[cnt - 1][j]);
						t1 = t2;
						q.pop();
					}
					/*
					for (int l = 0; l < n; l++) {
						printf("%d ", map[l][j]);
					}
					printf("\n");
					printf("%d %d\n", t1, t2);
					*/
				}
				/*
				printf("-----------%d열------------\n",j);
				for (int l = 0; l < n; l++) {
					for (int m = 0; m < n; m++) {
						printf("%d ", map[l][m]);
					}
					printf("\n");
				}
				printf("---------------------------\n");
				*/
			}
		}

		if (s == "down") {
			for (int j = 0; j < n; j++) {
				queue<int> q;
				for (int i = n - 1; i >= 0; i--) {
					if (map[i][j] == 0) {
						continue;
					}
					q.push(map[i][j]);
				}

				if (q.empty()) {
					continue;
				}

				int cnt = n-1;
				int t1 = q.front();
				q.pop();

				/*
				printf("%d열 검사", j);
				for (int l = 0; l < n; l++) {
					printf("%d ", map[l][j]);
				}
				printf("\n");
				*/
				while (cnt != -1) {
					//printf("남은 q수: %d\n", q.size());
					if (q.empty()) {
						if (t1 != 0) {
							map[cnt--][j] = t1;
							t1 = 0;
						}
						else {
							map[cnt--][j] = 0;
						}
						continue;
					}
					int t2 = q.front();
					if (q.size() != 1) {
						//printf("t2: %d", t2);
						while (t2 == 0) {
							q.pop();
							t2 = q.front();
							//printf("->%d", t2);
						}
					}
					//printf("\n");
					//printf("%d %d\n", t1, t2);
					if (t1 == 0) {
						t1 = t2;
						q.pop();
					}
					else if (t1 == t2) {
						//printf("cnt %d:%d->", cnt, map[cnt][j]);
						map[cnt--][j] = t1 * 2;
						//printf("%d\n", map[cnt - 1][j]);
						q.pop();
						t1 = 0;
						if (!q.empty()) {
							t1 = q.front();
							q.pop();
						}
					}
					else if (t1 != t2) {
						//printf("cnt %d:%d->", cnt, map[cnt][j]);
						map[cnt--][j] = t1;
						//printf("%d\n", map[cnt - 1][j]);
						t1 = t2;
						q.pop();
					}
					/*
					for (int l = 0; l < n; l++) {
						printf("%d ", map[l][j]);
					}
					printf("\n");
					printf("%d %d\n", t1, t2);
					*/
				}
				/*
				printf("-----------%d열------------\n",j);
				for (int l = 0; l < n; l++) {
					for (int m = 0; m < n; m++) {
						printf("%d ", map[l][m]);
					}
					printf("\n");
				}
				printf("---------------------------\n");
				*/
			}
		}

		if (s == "left") {
			for (int i = 0; i < n; i++) {
				queue<int> q;
				for (int j = 0; j < n; j++) {
					if (map[i][j] == 0) {
						continue;
					}
					q.push(map[i][j]);
				}

				if (q.empty()) {
					continue;
				}

				int cnt = 0;
				int t1 = q.front();
				q.pop();

				/*
				printf("%d행 검사", i);
				for (int l = 0; l < n; l++) {
					printf("%d ", map[i][l]);
				}
				printf("\n");
				*/
				while (cnt != n) {
					//printf("남은 q수: %d\n", q.size());
					if (q.empty()) {
						if (t1 != 0) {
							map[i][cnt++] = t1;
							t1 = 0;
						}
						else {
							map[i][cnt++] = 0;
						}
						continue;
					}
					int t2 = q.front();
					if (q.size() != 1) {
						//printf("t2: %d", t2);
						while (t2 == 0) {
							q.pop();
							t2 = q.front();
							//printf("->%d", t2);
						}
					}
					//printf("\n");
					//printf("%d %d\n", t1, t2);
					if (t1 == 0) {
						t1 = t2;
						q.pop();
					}
					else if (t1 == t2) {
						//printf("cnt %d:%d->", cnt, map[i][cnt]);
						map[i][cnt++] = t1 * 2;
						//printf("%d\n", map[cnt][cnt-1]);
						q.pop();
						t1 = 0;
						if (!q.empty()) {
							t1 = q.front();
							q.pop();
						}
					}
					else if (t1 != t2) {
						//printf("cnt %d:%d->", cnt, map[i][cnt]);
						map[i][cnt++] = t1;
						//printf("%d\n", map[cnt][cnt-1]);
						t1 = t2;
						q.pop();
					}
					/*
					for (int l = 0; l < n; l++) {
						printf("%d ", map[l][cnt]);
					}
					printf("\n");
					printf("%d %d\n", t1, t2);
					*/
					
				}
				/*
				printf("-----------%d행------------\n",i);
				for (int l = 0; l < n; l++) {
					for (int m = 0; m < n; m++) {
						printf("%d ", map[l][m]);
					}
					printf("\n");
				}
				printf("---------------------------\n");
				*/
			}
		}

		if (s == "right") {
			for (int i = 0; i < n; i++) {
				queue<int> q;
				for (int j = n - 1; j >= 0; j--) {
					if (map[i][j] == 0) {
						continue;
					}
					q.push(map[i][j]);
				}

				if (q.empty()) {
					continue;
				}

				int cnt = n-1;
				int t1 = q.front();
				q.pop();

				/*
				printf("%d열 검사", j);
				for (int l = 0; l < n; l++) {
					printf("%d ", map[l][j]);
				}
				printf("\n");
				*/
				while (cnt != -1) {
					//printf("남은 q수: %d\n", q.size());
					if (q.empty()) {
						if (t1 != 0) {
							map[i][cnt--] = t1;
							t1 = 0;
						}
						else {
							map[i][cnt--] = 0;
						}
						continue;
					}
					int t2 = q.front();
					if (q.size() != 1) {
						//printf("t2: %d", t2);
						while (t2 == 0) {
							q.pop();
							t2 = q.front();
							//printf("->%d", t2);
						}
					}
					//printf("\n");
					//printf("%d %d\n", t1, t2);
					if (t1 == 0) {
						t1 = t2;
						q.pop();
					}
					else if (t1 == t2) {
						//printf("cnt %d:%d->", cnt, map[cnt][j]);
						map[i][cnt--] = t1 * 2;
						//printf("%d\n", map[cnt - 1][j]);
						q.pop();
						t1 = 0;
						if (!q.empty()) {
							t1 = q.front();
							q.pop();
						}
					}
					else if (t1 != t2) {
						//printf("cnt %d:%d->", cnt, map[cnt][j]);
						map[i][cnt--] = t1;
						//printf("%d\n", map[cnt - 1][j]);
						t1 = t2;
						q.pop();
					}
					/*
					for (int l = 0; l < n; l++) {
						printf("%d ", map[l][j]);
					}
					printf("\n");
					printf("%d %d\n", t1, t2);
					*/
				}
				/*
				printf("-----------%d열------------\n",j);
				for (int l = 0; l < n; l++) {
					for (int m = 0; m < n; m++) {
						printf("%d ", map[l][m]);
					}
					printf("\n");
				}
				printf("---------------------------\n");
				*/
			}
		}

		printf("#%d\n", t);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
		memset(map, 0, sizeof(map));
	}
	//system("pause");
	return 0;
}