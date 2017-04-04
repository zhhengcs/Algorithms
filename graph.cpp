int m = 2000,n = 1000;//边，节点

int g[maxn][maxm];//临界矩阵
g[u][v] = len

//vector实现临界表
struct node
{
	int to,len;
};
vector<node> G[maxn];
g[i].push_back((node){to,len});

//链式前向星
strcut edgenode
{
	int to;
	int len;
	int next;
}Edges[maxm];

int head[maxn],k = 0;//节点头，边的编号

void addedge(int i,int j,int len)//add edd
{
	Edges[k].to = j;
	Edges[k].len = len;
	Edges[k].next = head[i];
	head[i] = k++;
}
for(int i = head[u],i!=-1;i = Edges[i].next)//iterator
{
	edgenode e = Edges[i];
	//code....
}
