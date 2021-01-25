// 2018068622_¿”πÆ∞Ê_B
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define inf 0

void merge(int arr[], int p, int r) {
	int i, j, k;
	int q = (p + r) / 2;
	int n1 = q - p + 1;
	int n2 = r - q;
	int* L = (int*)malloc((n1 + 1) * sizeof(int));
	int* R = (int*)malloc((n2 + 1) * sizeof(int));
	for (i = 0; i < n1; i++) {
		L[i] = arr[p + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = arr[q + j + 1];
	}
	L[n1] = inf;
	R[n2] = inf;
	i = j = 0;
	for (k = p; k < r + 1; k++) {
		if (L[i] >= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
	}

}

void merge_sort(int arr[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(arr, p, q);
		merge_sort(arr, q + 1, r);
		merge(arr, p, r);
	}
}

int main() {
	int i, n;
	scanf("%d", &n);
	int* arr = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	merge_sort(arr, 0, n-1);

	for (i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}