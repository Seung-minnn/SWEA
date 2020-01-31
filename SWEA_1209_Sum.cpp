#include<stdio.h>
#include<iostream>

#define MAX 100
using namespace std;

int find_max(int a[MAX][MAX]) {
	int max = 0;
	for (int i = 0; i < MAX; i++) {
		int t1 = 0;
		for (int j = 0; j < MAX; j++) {
			t1 += a[i][j];
		}
		max = (max >= t1) ? max : t1;
	}
	for (int j = 0; j < MAX; j++) {
		int t2 = 0;
		for (int i = 0; i < MAX; i++) {
			t2 += a[i][j];
		}
		max = (max >= t2) ? max : t2;
	}
	for (int k = 0; k < 100; k++) {
		int t3 = 0, t4 = 0;
		t3 += a[k][k];
		t4 += a[100 - (k + 1)][100 - (k + 1)];
		max = (max >= t3) ? max : t3;
		max = (max >= t4) ? max : t4;
	}
	return max;
}

int main() {
	int round;
	for (int t = 0; t < 10; t++) {
		int a[MAX][MAX] = { {0,}, };
		scanf("%d", &round);
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		int ans;
		ans = find_max(a);
		printf("#%d %d\n", round, ans);
	}
	return 0;
}


