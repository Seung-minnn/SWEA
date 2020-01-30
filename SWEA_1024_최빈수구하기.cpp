#include<stdio.h>
#include<iostream>

#define STU 1000
using namespace std;

int max(int a[]) {
	int max=-1;
	int ans = 0;
	for (int i = 0; i <= 100 ; i++) {
		if (max <= a[i]) {
			max = a[i];
			ans = i;
		}
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int round;
		int s_list[102] = {0,};
		scanf("%d", &round);
		for (int i = 0; i < STU; i++) {
			int temp;
			scanf("%d", &temp);
			s_list[temp]++;
		}
		printf("#%d %d\n", round, max(s_list));
	}
	return 0;
}