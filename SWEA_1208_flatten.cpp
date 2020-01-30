#include<stdio.h>
#include<iostream>

#define GARO 100
using namespace std;

int dumping(int x, int d[]) {
	for (int i = 0; i < x+1; i++) {
		if (i == x) {
			int min = 101;
			int max = 0;
			int t1, t2;
			for (int j = 0; j < GARO; j++) {
				if (min >= d[j]) {
					min = d[j];
					t1 = j;
				}
				if (max <= d[j]) {
					max = d[j];
					t2 = j;
				}
			}
			int height = max - min;
			return height;
		}

		int min = 101;
		int max = 0;
		int t1, t2;

		for (int j = 0; j < GARO; j++) {
			if (min >= d[j]) {
				min = d[j];
				t1 = j;
			}
			if (max <= d[j]) {
				max = d[j];
				t2 = j;
			}
		}
		if (d[t1] + 1 < 1000) {
			d[t1]++;
		}
		if (d[t2] - 1 > 1) {
			d[t2]--;
		}
	}
}
int main() {
	for (int i = 1; i <= 10; i++) {
		int dump;
		scanf("%d", &dump);

		int d_list[GARO] = {0,};
		for (int j = 0; j < GARO; j++) {
			scanf("%d", &d_list[j]);
		}
		
		int ans = 0;
		ans = dumping(dump, d_list);
		printf("#%d %d\n", i, ans);
	}
	return 0;
}

