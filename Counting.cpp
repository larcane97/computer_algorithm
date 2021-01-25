// 2018068622_¿”πÆ∞Ê_B
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	int i;
	int* r1 = (int*)malloc(sizeof(int) * (k+1));
	int* r2 = (int*)malloc(sizeof(int) * (1+k));
	int* A = (int*)malloc(sizeof(int) * n);
	int* C = (int*)malloc(sizeof(int) * (m + 1));
	int* B = (int*)malloc(sizeof(int) * n);
	for (i = 0; i <= m; i++)
		C[i] = 0;
	for (i = 1; i <= k; i++) {
		scanf("%d %d", &r1[i], &r2[i]);
	}

	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
		C[A[i]]++;
	}

	for (i = 1; i <= k; i++) {
		int sum = 0;
		int j = r1[i];
		for (; j <= r2[i]; j++)
			sum += C[j];
		printf("%d\n", sum);
	}
	
	
}