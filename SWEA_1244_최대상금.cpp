#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
using namespace std;

int chg;
int ans;
string inf;
vector<int> v;

void search_dfs(int c, int idx) {
	if (c == chg) {
		int tmp = v[0];
		for (int i = 1; i < v.size(); i++) {
			tmp = tmp * 10 + v[i];
		}
		if (ans <= tmp) {
			ans = tmp;
		}
		return;
	}

	for (int i = idx; i < v.size() - 1; i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (v[i] > v[j]) {
				continue;
			}

			int temp;
			temp = v[i];
			v[i] = v[j];
			v[j] = temp;

			c++;
			search_dfs(c, i);
			c--;

			temp = v[i];
			v[i] = v[j];
			v[j] = temp;
		}
	}
}
int main() {
	int tc;
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		cin >> inf >> chg;

		int tmp;
		for (int i = 0; i < inf.length(); i++) {
			tmp = (inf.at(i) - '0');
			v.push_back(tmp);
		}

		tmp = v[0];
		for (int i = 1; i < v.size() ; i++) {
			tmp = tmp * 10 + v[i];
		}
		ans = tmp;
		search_dfs(0, 0);

		printf("#%d %d\n", t,ans);

		v.clear();
	}
	//system("pause");
	return 0;
}