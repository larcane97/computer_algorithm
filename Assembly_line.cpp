// 2018068622_¿”πÆ∞Ê_12838
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	int e[2];
	int x[2];
	int a[2][n];
	int s[2][n];
	int t[2][n];
	int l[2][n];
	int i, j,min,minIdx;
	
	scanf("%d %d", &e[0], &e[1]);
	scanf("%d %d", &x[0], &x[1]);
	for (i = 0; i < n; i++)
		scanf("%d", &a[0][i]);
	for (i = 0; i < n; i++)
		scanf("%d", &a[1][i]);
	for (i = 0; i < n-1; i++)
		scanf("%d", &t[0][i]);
	for (i = 0; i < n-1; i++)
		scanf("%d", &t[1][i]);

	for (i = 0; i < n-1; i++) {
		s[0][0] = a[0][0] + e[0];
		s[1][0] = a[1][0] + e[1];

		if (s[0][i] <= s[1][i] + t[1][i]) {
			s[0][i + 1] = s[0][i] + a[0][i + 1];
			l[0][i + 1] = 1;
		}
		else {
			s[0][i + 1] = s[1][i] + t[1][i] + a[0][i + 1];
			l[0][i + 1] = 2;
		}
		if (s[1][i] <= s[0][i] + t[0][i]) {
			s[1][i + 1] = s[1][i] + a[1][i + 1];
			l[1][i + 1] = 2;
		}
		else {
			s[1][i + 1] = s[0][i] + a[1][1 + i] + t[0][i];
			l[1][i + 1] = 1;
		}
	}
	if (s[0][i] + x[0] <= s[1][i] + x[1]) {
		min = s[0][i] + x[0];
		minIdx = 1;
	}
	else {
		min = s[1][i] + x[1];
		minIdx = 2;
	}
	
	printf("%d\n", min);
	printf("\n");

	int fastR[n];
	fastR[n - 1] = minIdx;
	for (i = n-1; i >= 0; i--) {
		fastR[i-1] = l[fastR[i] - 1][i];
	}

	for (i = 0; i < n; i++) {
		printf("%d %d\n", fastR[i], i+1);
	}
	return 0;
}