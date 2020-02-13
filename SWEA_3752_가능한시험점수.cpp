#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int a[101];
int ans_list[10001];

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		int n;
		scanf("%d", &n);

		int sum = 0;
		for (int i = 0; i < n; i++) {
			int temp;
			scanf("%d", &temp);
			sum += temp;
			a[i] = temp;
		}

		ans_list[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = sum; j >= 0; j--) {
				if (ans_list[j] == 1) {
					ans_list[j + a[i]] = 1;
				}
			}
		}

		int ans = 0;
		for (int j = sum; j >= 0; j--) {
			if (ans_list[j] == 1) {
				ans++;
			}
		}

		printf("#%d %d\n", t, ans);
		memset(a, 0, sizeof(a));
		memset(ans_list, 0, sizeof(ans_list));
	}
	//system("pause");
	return 0;
}