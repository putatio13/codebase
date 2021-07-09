nclude<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXV 110
const int INF = 0x3f3f3f3f;
#define min(a, b) (a > b) ? b : a

//图的定义
typedef struct ANode
{
    int adjvex;
        struct ANode *nextarc;
            int weight;
            } ArcNode;
typedef struct VNode
{
	ArcNode *firstarc;
} VNode;
typedef struct
{
	VNode adjlist[MAXV];
	int n;
} AdjGraph;

//有关图的函数
AdjGraph *g;
void initiGraph(int n)
{
	g = (AdjGraph *)malloc(sizeof(AdjGraph));
	for (int i = 1; i <= n; i++)
		g->adjlist[i].firstarc = NULL;
	g->n = n;                                            
}
void insertArc(AdjGraph *g, int b, int e,int w)
{
	ArcNode *t, *pre = (*g).adjlist[b].firstarc;
	t = (ArcNode *)malloc(sizeof(ArcNode));
	t->adjvex = e;
	t->weight = w;
	if (pre != NULL)
		t->nextarc = pre;
	else
		t->nextarc = NULL;
	(*g).adjlist[b].firstarc = t;
}
void insertArc2(AdjGraph *g, int b, int e,int weight)
{

	insertArc(g, b, e, weight);
	insertArc(g, e, b, weight);
}

//有关队列的函数
#define MAXSIZE 10000
int queue[MAXSIZE];
int front = -1, rear = -1;
void enQueue(int n)
{
	rear = (rear + 1) % MAXSIZE;
	queue[rear] = n;
}
int deQueue()
{
	front = (front + 1) % MAXSIZE;
	return queue[front];
}

int vis[MAXV], d[MAXV], cnt[MAXV];
int N, M;
int fun(int s)
{
	memset(d, 0x3f, sizeof(d));
	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	front = -1;
	rear = -1;
	enQueue(s);
	d[s] = 0;
	while (rear != front)
	{
		int u = deQueue();
		cnt[u]++;
		if (cnt[u] > N)
			return 1;
		vis[u] = 0;
		for (ArcNode *j = g->adjlist[u].firstarc; j != NULL; j = j->nextarc)
		{
			int v = j->adjvex;
			if (d[v] > d[u] + j->weight)
			{
				d[v] = d[u] + j->weight;
				if(!vis[v])
				{
					enQueue(v);
					vis[v] = 1;
				}
			}
		}                                                                                                                                                                                                                                                                                                                                                                                  }                                                                                                                                                                                                                                                                                                                                                                                        return 0;
}
