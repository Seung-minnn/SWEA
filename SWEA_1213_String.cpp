#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>

using namespace std;

int main() {
	

	for (int t = 0; t < 10; t++) {
		int n;
		int ans = 0;
		
		scanf("%d", &n);
		
		char find[11] = {};
		char search[1001] = {};
		scanf("%s", find);
		scanf("%s", search);

		int find_length = strlen(find);
		int search_length = strlen(search);

		for (int i = 0; i < search_length - find_length + 1; i++) {
			if (search[i] == find[0]) {
				for (int j = 0; j < find_length; j++) {
					if (search[i + j] != find[j]) {
						break;
					}
					if (j == find_length - 1) {
						ans++;
					}
				}
			}
		}
		printf("#%d %d\n", n, ans);
	}
	//system("pause");
	return 0;
}