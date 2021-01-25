// 2018068622_¿”πÆ∞Ê_12838
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct edge {
	int u;
	int v;
	int w;
}edge;

void init(int* arr,int n) {
	for (int i = 1; i <= n; i++)
		arr[i] = 0;
	return;

}

int find(int* set, int i) {
	if(set[i] > 0)
		set[i] = find(set, set[i]);
	else
		return i;
}

void Union(int* set, int i, int j) {
	int iRoot = find(set, i);
	int jRoot = find(set, j);
	if (iRoot == jRoot)
		return;
	if (set[iRoot] > set[jRoot])
		set[iRoot] = jRoot;
	else if (set[jRoot] > set[iRoot])
		set[jRoot] = iRoot;
	else {
		set[jRoot] = iRoot;
		set[iRoot]--;
	}
	return;
	
}


void heapify(edge** arr, int i, int len) {
	int child;
	edge* key = arr[i];
	for (; i * 2 <= len; i = child) {
		child = i * 2;
		if (i * 2 != len && 
			( arr[child]->w > arr[child + 1]->w 
				|| ( arr[child]->w == arr[child+1]->w && arr[child]->u > arr[child+1]->u)
				|| (arr[child]->w == arr[child + 1]->w && arr[child]->u == arr[child + 1]->u && arr[child]->v > arr[child+1]->v)
				))
			child++;
		if ( (key->w > arr[child]->w) 
			|| (key->w == arr[child]->w && key->u > arr[child]->u)
			|| (key->w == arr[child]->w && key->u == arr[child]->u && key->v > arr[child]->v)
			) {
			arr[i] = arr[child];
		}
		else
			break;
	}
	arr[i] = key;
}

void build_heap(edge** arr, int len) {
	int i;
	for (i = len / 2; i > 0; i--)
		heapify(arr, i, len);
}

edge* extract(edge** arr, int* len) {
	edge* e = arr[1];
	arr[1] = arr[*len];
	*len -= 1;
	heapify(arr, 1, (*len));
	return e;
}


int main() {
	int n, m, w, i, j,len,selNum=0;
	scanf("%d %d", &n, &m);
	len = m;
	int* set = (int*)malloc(sizeof(int) * (n + 1));
	edge** E = (edge**)malloc(sizeof(edge*) * (1+m));
	init(set, n);
	for (i = 1; i <= m; i++) {
		E[i] = (edge*)malloc(sizeof(edge));
		scanf("%d %d %d", &(E[i]->u), &(E[i]->v), &(E[i]->w));
	}

	build_heap(E,m);
	while (len > 0) {
		edge* e = extract(E, &len);
		if (find(set, e->u) != find(set, e->v)) {
			E[m-selNum] = e;
			selNum++;
			Union(set, e->u, e->v);
			if (selNum >= n - 1)
				break;
		}
	}
	printf("%d\n", selNum);
	for (i = m ; i >=m-selNum+1; i--)
		printf("%d %d %d\n", E[i]->u, E[i]->v, E[i]->w);
	
	
}