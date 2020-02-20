#include<stdio.h>
#include<iostream>
#include<cstring>

using namespace std;

int n;
double position[10];
double weight[10];

int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		scanf("%d", &n);
		for (int i = 0; i < n * 2; i++) {
			double temp;
			scanf("%lf", &temp);
			if (i >= n) {
				weight[i - n] = temp;
			}
			else {
				position[i] = temp;
			}
		}

		printf("#%d ", t);
		double ans;
		for (int i = 0; i < n - 1; i++) {
			double l = position[i];
			double r = position[i + 1];
			ans = 0;

			for (int j = 0; j < 100; j++) {
				double mid = (l + r) / 2;
				double temp = 0;
				for (int k = 0; k <= i; k++) {
					temp += weight[k] / ((mid - position[k])*(mid - position[k]));
				}
				for (int k = i + 1; k < n; k++) {
					temp -= weight[k] / ((mid - position[k])*(mid - position[k]));
				}
				if (temp > 0) {
					l = mid;
				}
				else {
					ans = mid;
					r = mid;
				}
			}
			printf("%.10lf ", ans);
		}
		printf("\n");

		memset(position, 0, sizeof(position));
		memset(weight, 0, sizeof(position));
	}
	//system("pause");
	return 0;
}