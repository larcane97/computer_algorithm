// 2018068622_¿”πÆ∞Ê_b
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int i, int len) {
	int child;
	int key = arr[i];
	for (;  i*2<= len; i = child) {
		child = i * 2;
		if (i*2 != len && arr[child] < arr[child + 1])
			child++;
		if (key < arr[child]) {
			arr[i] = arr[child];
		}
		else
			break;
	}
	arr[i] = key;
}

void build_heap(int arr[], int len) {
	int i;
	for (i = len / 2; i > 0; i--)
		heapify(arr, i, len);
}

int extract(int arr[], int* len) {
	int num = arr[1];
	arr[1] = arr[*len];
	*len -= 1;
	heapify(arr, 1, (*len));
	return num;
}


int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int* arr = (int*)malloc(sizeof(int) * (n + 1));
	int len = n;
	int i;
	for (i = 1; i <= len; i++) {
		scanf("%d", &arr[i]);
	}
	build_heap(arr, len);
	for (i = 0; i < k; i++) {
		printf("%d ", extract(arr, &len));
	}
	printf("\n");
	for (i = 1; i <= len; i++) {
		printf("%d ", arr[i]);
	}
}