// 2018068622_¿”πÆ∞Ê_B
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int i, int len) {
	int child;
	int key = arr[i];
	for (; i * 2 <= len; i = child) {
		child = i * 2;
		if (i * 2 < len && arr[child] <= arr[child + 1])
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
	(*len) -= 1;
	heapify(arr, 1, (*len));
	return num;
}


void insert(int arr[], int key, int* len) {
	(*len)++;
	int i, parent;
	for (i = (*len); i > 1; i = parent) {
		parent = i / 2;
		if (arr[parent] < key)
			arr[i] = arr[parent];
		else break;
	}
	arr[i] = key;
}

void substitude(int arr[], int key, int index, int len) {
	if (arr[index] > key) {
		arr[index] = key;
		heapify(arr, index, len);
	}
	if (arr[index] < key) {
		int i, parent;
		for (i = index; i > 1; i = parent) {
			parent = i / 2;
			if (arr[parent] < key)
				arr[i] = arr[parent];
			else break;
		}
		arr[i] = key;
	}

}

int main() {


	int* arr = (int*)malloc(sizeof(int) * 100001);
	int* extracted = (int*)malloc(sizeof(int) * 100001);
	int len = 0;
	int len2 = 0;
	int n;
	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			int i;
			for (i = 1; i <= len2; i++)
				printf("%d ", extracted[i]);
			printf("\n");
			for (i = 1; i <= len; i++)
				printf("%d ", arr[i]);
			printf("\n");
			break;
		}
		else if (n == 1) {
			int a;
			scanf("%d", &a);
			insert(arr, a, &len);

		}
		else if (n == 2) {
			extracted[++len2] = extract(arr, &len);
		}
		else if (n == 3) {
			int a, b;
			scanf("%d %d", &a, &b);
			substitude(arr, b, a, len);
		}
	}

}