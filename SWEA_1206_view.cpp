#include<stdio.h>
#include<iostream>

#define GARO 1000
using namespace std;

int build_count(int num, int b[]) {
	int ans = 0;
	for (int i = 2; i < num - 2; i++) {
		int cnt = 0;
		if (b[i - 1] <= b[i] && b[i - 2] <= b[i]) {
			if (b[i] >= b[i + 1] && b[i] >= b[i + 2]) {
				// Ã¹¹øÂ° ºôµù
				if (i == 2) {
					int t1 = (b[i + 1] >= b[i + 2]) ? b[i + 1] : b[i + 2];
					cnt = b[i] - t1;
				}
				//¸¶Áö¸· ºôµù
				else if (i == num - 3) {
					int t1 = (b[i - 1] >= b[i - 2]) ? b[i - 1] : b[i - 2];
					cnt = b[i] - t1;
				}
				else {
					int t1, t2, t3, t4;
					t1 = b[i - 2];
					t2 = b[i - 1];
					t3 = b[i + 1];
					t4 = b[i + 2];
					int x, y, z;
					x = (t1 >= t2) ? t1 : t2;
					y = (t3 >= t4) ? t3 : t4;
					z = (x >= y) ? x : y;
					cnt = b[i] - z;
				}
			}
		}
		ans += cnt;
	}
	return ans;
}
int main() {
	int t = 10;
	int cnt = 0;
	while (t--) {
		cnt++;
		int	building;
		int b_list[GARO] = { 0, };
		scanf("%d", &building);
		for (int i = 0; i < building; i++) {
			int temp;
			scanf("%d", &temp);
			b_list[i] = temp;
		}
		int ans = build_count(building, b_list);
		printf("#%d %d\n", cnt, ans);
	}
	return 0;
}