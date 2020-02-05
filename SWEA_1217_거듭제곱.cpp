#include<stdio.h>
#include<iostream>

using namespace std;

int gegob(int x, int y) {
	if (y == 0) return 1;
	y--;

	return x * gegob(x, y);
}
int main() {
	for (int t = 0; t < 10; t++) {
		int n; int ans;
		scanf("%d", &n);

		int x, y;
		scanf("%d %d", &x, &y);

		ans = gegob(x, y);
		printf("#%d %d\n", n, ans);
	}
	//system("pause");
	return 0;
}