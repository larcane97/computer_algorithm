// 2018068622_¿”πÆ∞Ê_12838
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct data {
	char character[5];
	int freq;
	data* left_child;
	data* right_child;
}data;

void heapify(data* arr[], int i, int len) {
	int child;
	data* key = arr[i];
	for (; i * 2 <= len; i = child) {
		child = i * 2;
		if (i * 2 != len && arr[child]->freq > arr[child + 1]->freq)
			child++;
		if (key->freq > arr[child]->freq) {
			arr[i] = arr[child];
		}
		else
			break;
	}
	arr[i] = key;
}

void build_heap(data* arr[], int len) {
	int i;
	for (i = len / 2; i > 0; i--)
		heapify(arr, i, len);
}

data* extract(data* arr[], int* len) {
	data* num = arr[1];
	arr[1] = arr[*len];
	*len -= 1;
	heapify(arr, 1, (*len));
	return num;
}

void insert(data* arr[], int* len, data* d) {
	(*len)++;
	int i;
	arr[(*len)] = d;
	for (i = *len; i > 1; i = i / 2) {
		int parent = i / 2;
		if (arr[parent]->freq > d->freq) {
			arr[i] = arr[parent];
		}
		else break;
	}
	arr[i] = d;
}


int calcBits(data* d,int n) {
	static int count = 0;
	if ( d->left_child == NULL && d->right_child == NULL) {
		count += n * d->freq;
		return count;
	}
	else {
		calcBits(d->left_child,n+1);
		calcBits(d->right_child,n+1);
	}

}

int main() {
	int n;
	int total_n;
	scanf("%d", &n);
	data** arr = (data**)malloc(sizeof(data*) * (n + 1));
	int len = n;
	int i;
	for (i = 1; i <= len; i++) {
		data* d = (data*)malloc(sizeof(data));
		scanf("%s %d", d->character,&d->freq);
		d->left_child = d->right_child = NULL;
		arr[i] = d;
		
	}
	scanf("%d", &total_n);

	build_heap(arr, len);

	
	while (len > 1) {
		data* d1 = (data*)malloc(sizeof(data));
		data* d2 = (data*)malloc(sizeof(data));
		d1 = extract(arr, &len);
		d2 = extract(arr, &len);
		data* newD = (data*)malloc(sizeof(data));
	
		newD->freq = d1->freq + d2->freq;
		newD->right_child = d2;
		newD->left_child = d1;
		
		insert(arr, &len, newD);
	}
	data* lastD = extract(arr, &len);

	int k = 1;
	for (i = 2; i < n; i *= 2)
		k++;
	int haffman_result = calcBits(lastD,0);
	int normal_result = k * total_n;

	printf("%d\n", normal_result);
	printf("%d\n",haffman_result);


	return 0;
}

