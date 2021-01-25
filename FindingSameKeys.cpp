// 2018068622_¿”πÆ∞Ê_B
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i,n, m;
	scanf("%d %d", &n, &m);
	int* A = (int*)malloc(sizeof(int) * n);
	int* B = (int*)malloc(sizeof(int) * m);
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);
	for (i = 0; i < m; i++)
		scanf("%d", &B[i]);

	int count = 0;
	for (i = 0; i < n; i++) {
		int key = A[i];
		int j;
		for (j = 0; j < m; j++) {
			if (key == B[j])
				count++;
		}
	}
	printf("%d\n", count);
}