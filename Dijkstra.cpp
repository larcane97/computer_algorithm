// 2018068622_¿”πÆ∞Ê_12838
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define inf 100000

typedef struct edge {
	int u;
	int v;
	int w;
	edge* next;
}edge;

typedef struct node {
	int n;
	int d;
	edge* adj;
}node;

void heapify(node** arr, int i, int len) {
	int child;
	node* key = arr[i];
	for (; i * 2 <= len; i = child) {
		child = i * 2;
		if (i * 2 != len && (arr[child]->d > arr[child + 1]->d))
			child++;
		if(key->d > arr[child]->d)
			arr[i] = arr[child];
		else
			break;
	}
	arr[i] = key;
}

void build_heap(node** arr, int len) {
	int i;
	for (i = len / 2; i > 0; i--)
		heapify(arr, i, len);
}

node* extract(node** arr, int* len) {
	node* e = arr[1];
	arr[1] = arr[*len];
	*len -= 1;
	heapify(arr, 1, (*len));
	return e;
}


void increase(node** arr,int i) {
	node* key = arr[i];
	int parent;
	while (i > 1) {
		parent = i / 2;
		if (arr[parent]->d > key->d)
			arr[i] = arr[parent];
		else break;
		i = parent;
	}
	arr[i] = key;
	return;
}


int main() {
	int i, j, n, m,len;
	scanf("%d %d", &n, &m);
	node** Node = (node**)malloc(sizeof(node*) * (n + 1));
	node* V = (node*)malloc(sizeof(node) * (n + 1));
	len = n;
	for (i = 1; i <= n; i++) {
		Node[i] = (node*)malloc(sizeof(node));
		Node[i]->n = i, Node[i]->d = inf;
		//Node[i]->p = NULL;
		Node[i]->adj = NULL;
		V[i] = *Node[i];
	}
	for (i = 0; i < m; i++){
		edge* e = (edge*)malloc(sizeof(edge));
		scanf("%d %d %d", &(e->u), &(e->v), &(e->w));
		e->next= Node[e->u]->adj;
		Node[e->u]->adj = e;
	}
		
	
	Node[1]->d = 0;
	V[1].d = 0;
	build_heap(Node, len);
	int max = 0;
	node* u=NULL;
	while (len >0) {
		u = extract(Node, &len);
		edge* e = u->adj;
		while (e != NULL) {
			V[e->v].d = V[e->v].d <= (u->d + e->w) ? V[e->v].d : u->d + e->w;
			for (j = 1; j <= len; j++) {
				if (Node[j]->n == e->v) {
					Node[j]->d = V[e->v].d;
					increase(Node, j);
					break;
				}
			}
			//Node[e->v]->p = e->u;
			e = e->next;
		}
		if (V[u->n].d > max)
			max = V[u->n].d;
		//Node[len + 1] = u;
	}
	printf("%d\n", max);
}