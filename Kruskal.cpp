struct edge
{
	int from,to,len;
	bool operator < (const edge &rhs) 
	{
		return len < rhs.len;
	}
}edges[maxm];

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

int Kruskal()
{
	int ans = 0;
	for(int i = 0; i <= n; ++i) p[i] = i;
	sort(r,r+m);
	for(int i = 0; i < m; ++i){
		int u = edges[i].from,v =edges[i].to;
		int x = find(u),y = find(v);
		if(x!=y) {
			ans+=w[e];p[x] = y;//
		}
	}
	return ans;
}




int cmp(const int i,const int j) return w[i] < w[j];
int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

int Kruskal()
{
	int ans = 0;
	for(int i = 0; i <= n; ++i) p[i] = i;
	for(int i = 0; i <= n; ++i) r[i] = i;
	sort(r,r+m,cmp);
	for(int i = 0; i < m; ++i){
		int e = r[i];int x = find(u[e]),y = find(v[e]);
		if(x!=y) {
			ans+=w[e];p[x] = y;//
		}
	}
	return ans;
}