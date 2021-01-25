//2018068622_¿”πÆ∞Ê_B
#include <stdio.h>

int main() {
	int n, i, j;
	scanf("%d", &n);
	int arr[n];
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 1; i < n; i++) {
		int key = arr[i];
		j = i - 1;
		while (j >= 0 && key > arr[j]) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}

	for (i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}