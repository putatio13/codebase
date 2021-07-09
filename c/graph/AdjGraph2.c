#define maxn 20010
typedef struct edge{
	    int v, next;
} e[maxn * 2];
int p[maxn], eid;

void init(){
	    eid = 0;
	        memset(p, -1, sizeof(p));
}
void insert(int x, int y)
{
	    e[eid].v = y;
	        e[eid].next = p[x];
		    p[x] = eid++;
}

void insert2(int x, int y)
{
	    insert(x, y);
	        insert(y, x);
}
