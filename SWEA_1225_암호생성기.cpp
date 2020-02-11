#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		int n;
		int cnt = 1;
		queue<int> q;

		scanf("%d", &n);
		for (int i = 0; i < 8; i++) {
			int temp;
			scanf("%d", &temp);
			q.push(temp);
		}

		while (1) {
			if (cnt == 6) {
				cnt = 1;
			}
			int tmp = q.front();
			//printf("%d->", tmp);
			q.pop();
			tmp -= cnt++;
			//printf("%d\n", tmp);
			if (tmp <= 0) {
				tmp = 0;
				q.push(0);
				break;
			}
			q.push(tmp);
		}

		printf("#%d ", n);
		for (int i = 0; i < 8; i++) {
			printf("%d ", q.front());
			q.pop();
		}
		printf("\n");
	}
	//system("pause");
	return 0;
}