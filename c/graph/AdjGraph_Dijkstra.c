nclude<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXV 110
const int INF = 0x3f3f3f3f;
#define min(a, b) (a > b) ? b : a
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
int N, M;
int d[MAXV], vis[MAXV];
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

void fun(int s)
{
	memset(d, 0x3f, sizeof(d));
	        memset(vis, 0, sizeof(vis));
		    d[s] = 0;
		        for (int i = 1; i <= N; i++)
				    {
					            int mind = INF;
						            int u = 0;
							            for (int j = 1; j <= N; j++)
									            {
											                if (!vis[j] && d[j] < mind)
														            {
																                    mind = d[j];
																		                    u = j;
																				                }
													        }
								            if(mind==INF)
										            {
												                break;
														        }
									            vis[u] = 1;
										            for (ArcNode *j = g->adjlist[u].firstarc; j != NULL; j = j->nextarc)
												            {
														                int v = j->adjvex;
																            d[v] = min(d[v], d[u] + j->weight);
																	            }
											        }
			    printf("%d\n", d[N]);
}
