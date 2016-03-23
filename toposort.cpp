#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10,mod = 10007;

int t,n;
vector<string> s;
int indegree[maxn];//入度
int g[maxn][maxn];//矩阵
int pur[maxn];//拓扑序列

struct  cmp
{
   bool operator ()(const int &a,const int &b)
   {
      return s[a] > s[b];
   }
};

void topsort()  
{  
    priority_queue<int,vector<int>,cmp> que;//当要拓扑排序的元素有优先级要求时，比如按照字典序排列
    int i, j, k=1;  
    for(int i = 0; i < n; ++i)
    	if(!indegree[i]) que.push(i);//把入度为0的点加入队列
    while(!que.empty()) 
    {  
		int x = que.top();que.pop();
		pur[k++] = x;
		for(int z = 0; z < n; ++z){
			if(g[x][z]){
				g[x][z] = 0;//删除边
				indegree[z]--;//入度减一
				if(!indegree[z]){
					que.push(z);//把入度为0的点加入优先队列
					
				}
			}
		}
    } 
    if(k <= n)  
    {  
        cout<<"ERROR"<<endl;//非DAG  
        return ;  
    }  
    for(int x = 1; x < k; ++x)
    	cout << s[pur[x]] <<endl;
}  
 
