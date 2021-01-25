// 2018068622_¿”πÆ∞Ê_12838
#define inf 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	scanf("%d", &n);
	int* p = (int*)malloc(sizeof(int) * (1+n));
	int* r = (int*)malloc(sizeof(int) * (1 + n));
	int* s = (int*)malloc(sizeof(int) * (1 + n));
	int i,j, q,max=-inf,maxIdx;
	r[0] = 0;
	s[0] = 0;
	for (i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	for(i = 1; i <= n; i++) {
		q = -inf;
		for (j = 1; j <= i; j++) {
			if (q < p[j] + r[i - j]) {
				q = p[j] + r[i- j];
				s[i] = j;
			}
		}
		r[i] = q;
	}
	for (i = 0; i <= n; i++) {
		if (max < r[i]) {
			max = r[i];
			maxIdx = i;
		}
	}
	printf("%d\n", max);
	while (maxIdx > 0) {
		printf("%d ", s[maxIdx]);
		maxIdx = maxIdx - s[maxIdx];
	}
	free(p); free(r); free(s);
	return 0;
}
