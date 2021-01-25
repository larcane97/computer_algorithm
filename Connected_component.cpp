// 2018068622_¿”πÆ∞Ê_12838
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct nextNode {
	int index;
	nextNode* next;
};
typedef struct node {
	int d;
	int f;
	bool chk;
	node* prev;
	nextNode* next;
};


int time=0;
int count=0;
void DFS_visit(node** G, int index) {
	time++;
	node* u = G[index];
	u->chk = true;
	u->d = time;
	nextNode* tmp = u->next;
	while (tmp!= NULL) {
		int v = tmp->index;
		if (!G[v]->chk) {
			G[v]->prev = u;
			DFS_visit(G, v);
		}
		tmp = tmp->next;
	}
	time++;
	u->f = time;
}

void DFS(node** G,int len) {
	for (int i = 1; i <= len; i++)
		G[i]->chk = false;
	for (int i = 1; i <= len; i++) {
		if (!G[i]->chk) {
			count++;
			DFS_visit(G, i);
		}
	}
}




int main() {
	int i,j,n, m,x,y;
	scanf("%d %d", &n, &m);
	node** Node = (node**)malloc(sizeof(node*) * (n+1));
	for (i = 1; i <= n; i++) {
		Node[i] = (node*)malloc(sizeof(node));
		Node[i]->prev = NULL;
		Node[i]->next = NULL;
	}
	for (i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		nextNode* xNext; 
		nextNode* yNext;
		xNext = (nextNode*)malloc(sizeof(nextNode));
		yNext = (nextNode*)malloc(sizeof(nextNode));
		xNext->index = y, yNext->index = x;
		xNext->next = yNext->next = NULL;
		if (Node[x]->next == NULL)
			Node[x]->next = xNext;
		else {
			xNext->next = Node[x]->next;
			Node[x]->next = xNext;
		}
		if(Node[y]->next == NULL)
			Node[y]->next = yNext;
		else {
			yNext->next = Node[y]->next;
			Node[y]->next = yNext;
		}
	}
	DFS(Node, n);
	printf("%d\n", count);

}