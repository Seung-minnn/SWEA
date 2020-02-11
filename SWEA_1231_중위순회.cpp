#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

struct NODE
{
	char name;
	int left;
	int right;
};
NODE n[101];

void inorder_traverse(int n1) {
	if (n[n1].name != NULL) {
		inorder_traverse(n[n1].left);
		printf("%c", n[n1].name);
		inorder_traverse(n[n1].right);
	}
}

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		int number;
		scanf("%d", &number);

		memset(n, NULL, sizeof(n));
		for (int i = 1; i <= number; i++) {
			int t1;
			scanf("%d", &t1);
			if (i * 2 + 1 <= number) {
				scanf(" %c %d %d", &n[t1].name, &n[t1].left, &n[t1].right);
			}
			else if(i * 2 == number) {
				scanf(" %c %d", &n[t1].name, &n[t1].left);
			}
			else {
				scanf(" %c", &n[t1].name);
			}
		}
		/*
		printf("%c %d %d\n", n[9].name, n[9].left, n[9].right);
		if (n[9].name == NULL) {
			printf("yes\n");
		}
		else
			printf("no\n");
		*/
		printf("#%d ", tc);
		inorder_traverse(1);
		printf("\n");
	}

	//system("pause");
	return 0;
}