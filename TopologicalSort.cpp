// 2018068622_¿”πÆ∞Ê_12838
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int n;
	int d;
	int f;
	bool chk;
	node* prev;
};

int time = 0;
int count = 0;
bool DAGchk = true;
void DFS_visit(node** G, int index, int* arr,int** mat,int n) {
	static int k = 0;
	time++;
	node* u = G[index];
	u->chk = true;
	u->d = time;
	node* v;
	for (int i = 1;i<=n; i++) {
		if (mat[index][i] == 1) {
			v = G[i];
			if (v != NULL && !v->chk) {
				v->prev = u;
				DFS_visit(G, v->n, arr, mat, n);
			}
			if (v->chk && v->f ==NULL)
				DAGchk = false;

		}
	}
	time++;
	u->f = time;
	arr[k++] = index;
}

void DFS(node** G, int n, int* arr,int** mat) {
	for (int i = 1; i <= n; i++)
		G[i]->chk = false;
	for (int i = 1; i <= n; i++) {
		if (!G[i]->chk) {
			count++;
			DFS_visit(G, i, arr,mat,n);
		}
	}
	time = 0;
}




int main() {
	int i, j, n, m, x, y;
	scanf("%d %d", &n, &m);
	node** Node = (node**)malloc(sizeof(node*) * (n + 1));

	int** mat = (int**)malloc(sizeof(int*) * (1 + n));
	for (i = 1; i <= n; i++) {
		mat[i] = (int*)malloc(sizeof(int) * (n + 1));
		for (j = 1; j <= n; j++)
			mat[i][j] = 0;
	}

	for (i = 1; i <= n; i++) {
		Node[i] = (node*)malloc(sizeof(node));
		Node[i]->n = i;
		Node[i]->d = NULL;
		Node[i]->f = NULL;
		Node[i]->prev = NULL;
	}


	for (i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		mat[x][y] = 1;
	}
	int* arr = (int*)malloc(sizeof(int) * n);

	DFS(Node, n, arr,mat);
	if (DAGchk) {
		printf("%d\n", 1);
		//for (i = 1; i <= n; i++) {
			//printf("%d %d\n", Node[i]->d, Node[i]->f);
		//}
		for (i = n - 1; i >= 0; i--)
			printf("%d ", arr[i]);
	}
	else printf("%d\n", 0);

	return 0;

}