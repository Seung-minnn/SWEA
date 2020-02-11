#include<stdio.h>
#include<iostream>
#include<queue>
#include<string.h>

#define MAX 101
using namespace std;

int map[MAX][MAX];
int visited[MAX];

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		int temp, start;
		scanf("%d %d", &temp, &start);

		memset(map, 0, sizeof(map));
		memset(visited, -1, sizeof(visited));
		for (int i = 0; i < temp / 2; i++) {
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			map[t1][t2] = 1; //t1->t2 간선 존재
			visited[t1] = 0;
			visited[t2] = 0; 
		}


		//printf("ㄱ");
		queue<int> q;
		q.push(start);
		int cnt = 1;
		visited[start] = cnt;
		while (!q.empty()) {
			int s = q.front();
			q.pop();
			cnt = visited[s];
			cnt++;
			for (int i = 1; i < MAX; i++) {
				if (visited[i] == 0 && map[s][i] == 1) {
					q.push(i);
					visited[i] = cnt;
				}
			}
			/*
			for (int i = 1; i < MAX; i++) {
				printf("(%d,%d)", i, visited[i]);
			}
			printf("\n");
			*/
		}
		//printf("ㄴ");
		int tmax = -1;
		int ans;
		for (int i = 1; i < MAX; i++) {
			if (visited[i] >= tmax) {
				tmax = visited[i];
				ans = i;
			}
		}
		printf("#%d %d\n", tc, ans);
		//printf("ㄷ");
	}
	system("pause");
	return 0;
}