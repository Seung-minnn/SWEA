#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n; 
vector<pair<int, int>> v;
vector<int> v2;

int main() {
	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%d", &n);
		int sx, sy, ex, ey;
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
		for (int i = 0; i < n; i++) {
			int t1, t2;
			scanf(" %d %d", &t1, &t2);
			v.push_back({ t1, t2 });
			v2.push_back(i);
		}

		//next_permutation: 오름차순으로 정렬되어 있어야함.
		//do {
		//	for (int i = 0; i < n; i++) {
		//		printf("%d %d\n", v[v2[i]].first, v[v2[i]].second);
		//	}
		//	printf("--------------------\n");
		//} while (next_permutation(v2.begin(), v2.end()));

		int ans = 987654321;
		do {
			int temp = 0;
			temp += (abs(v[v2[0]].first - sx) + abs(v[v2[0]].second - sy));
      
			for (int i = 0; i < n-1; i++) {
				temp += (abs(v[v2[i + 1]].first - v[v2[i]].first) + abs(v[v2[i + 1]].second - v[v2[i]].second));
			}
      
			temp += (abs(ex - v[v2[v2.size() - 1]].first) + abs(ey - v[v2[v2.size() - 1]].second));
      
			if (ans >= temp) {
				ans = temp;
			}
      
		} while (next_permutation(v2.begin(), v2.end()));
		
		printf("#%d %d\n", t, ans);
		v.clear();
		v2.clear();
	}
	//system("pause");
	return 0;
}
