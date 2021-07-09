#define MAXV 100

typedef struct ANode
{
    int adjvex;
    struct ANode *nextarc;
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

void initiGraph(AdjGraph *g, int n)
{
    for (int i = 0; i < n; i++)
        g->adjlist[i].firstarc = NULL;
    g->n = n;
}

void insertArc(AdjGraph *g, int b, int e)
{
    ArcNode *t, *pre = (*g).adjlist[b].firstarc;
    t = (ArcNode *)malloc(sizeof(ArcNode));
    t->adjvex = e;
    if (pre != NULL)
        t->nextarc = pre;
    else
        t->nextarc = NULL;
    (*g).adjlist[b].firstarc = t;
}