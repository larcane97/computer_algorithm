// 2018068622_¿”πÆ∞Ê_12838
#define _CRT_SECURE_NO_WARNINGS
#define inf 100000000;
#include <stdio.h>
#include <stdlib.h>

void print_optimal_parens(int**arr, int** s, int i, int j) {
	static int num = 1;
	if (i == j)
		printf("%d ", num++);
	else {
		printf("( ");
		print_optimal_parens(arr, s, i, s[i][j]);
		print_optimal_parens(arr, s, s[i][j] + 1, j);
		printf(") ");
	}
}


int main() {
	int n;
	scanf("%d", &n);
	int i,j,k,l;
	int* p = (int*)malloc(sizeof(int)*(n + 1));
	int** arr = (int**)malloc(sizeof(int) * n);
	int** s = (int**)malloc(sizeof(int) * n);
	for (i = 0; i <= n; i++)
		scanf("%d", &p[i]);

	for (i = 0; i < n; i++)
		arr[i] = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		s[i] = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		arr[i][i] = 0;
		s[i][i] = 0;
	}

	for (k = 0; k < n-1; k++) {
		j = k + 1;
		for (i = 0; i < n - k - 1; i++) {
			arr[i][j] = inf;
			for (l = i; l < j; l++) {
				if (arr[i][j] > arr[i][l] + arr[l + 1][j] + (p[i] * p[l + 1] * p[j + 1])) {
					arr[i][j] = arr[i][l] + arr[l + 1][j] + (p[i] * p[l + 1] * p[j + 1]);
					s[i][j] = l;
				}
			}
			j++;
		}
	}

	printf("%d\n", arr[0][n-1]);
	print_optimal_parens(arr, s, 0, n - 1);

}