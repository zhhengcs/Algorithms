#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 10;
int MemorySize;
int PageSeq[maxn];
int CntPage;
int id[maxn];
vector<int> LRUpage;

bool cmp(int x,int y)
{
	return id[x] < id[y];
}

struct Heap
{
	int t[maxn],sz,h[maxn];

	Heap(){sz = 0;}
	bool empty();
	int size();
	int getpos(int x);
	int top();
	void adjust_min_heap(int rt);
	void build_heap();
	int pop();
	void push(int x);
}que;

struct Queue
{
	int a[maxn],inq[maxn],top,cntlack;
	bool full;
	Queue();
	void push(int x);
}Q;

void LRU(int CntPage,int PageSeq[]);
void FIFO(int CntPage,int PageSeq[]);


int main()
{
	// 输入内存块数：
	cin >> MemorySize;
	//请输入请求页面序列的长度：
	cin >> CntPage;
	// "请输入页面请求序列："
	for(int i = 1;i <= CntPage; ++i){
		cin >> PageSeq[i];
	}

	LRU(CntPage,PageSeq);
	FIFO(CntPage,PageSeq);
	
	return 0;
}


void LRU(int CntPage,int PageSeq[])
{
	cout << "-------LRU algorithm--------"<<endl;
	for(int i = 1; i <= CntPage; ++i){
		printf("请求页面： %d——", PageSeq[i]);
		if(id[PageSeq[i]]){
			printf("命中\n");
			int p = que.getpos(PageSeq[i]);
			id[PageSeq[i]] = i;
			que.adjust_min_heap(p);
			id[PageSeq[i]] = i;
		}
		else{
			printf("缺页,");
			//printf("\tLack %dth memeory\n", PageSeq[i]);
			LRUpage.push_back(PageSeq[i]);
			id[PageSeq[i]] = i;
			if(que.size() < MemorySize){
				printf("直接存入，新增页%d\n",PageSeq[i]);
				que.push(PageSeq[i]);
			}
			else
			{
				int x = que.top();
				id[x] = 0;
				//LRUpage.push_back(x);
				que.pop();
				que.push(PageSeq[i]);
				printf("淘汰页%d,新增页%d\n", x,PageSeq[i]);
			}
		}
		//que.put();
	}
	cout <<"缺页次数： "<<LRUpage.size()<<endl;
	printf("缺页率： %f\n",LRUpage.size()*1.0/CntPage);
}

void FIFO(int CntPage,int PageSeq[])
{
	cout << "-------FIFO algorithm--------"<<endl;
	for(int i = 1; i <= CntPage; ++i)
	{
		Q.push(PageSeq[i]);
	}
	printf("缺页次数：%d\n",Q.cntlack);
	printf("缺页率 ：%f\n",Q.cntlack*1.0/CntPage);
}

bool Heap::empty()
{
	return sz == 0;
}

int Heap::size()
{
	return sz;
}

int Heap::getpos(int x)
{
	return h[x];
}

int Heap::top()
{
	return t[1];
}

void Heap::adjust_min_heap(int rt)
{
    //从根往下调整
    int x = t[rt],pos=rt;
    while(rt < sz)
    {
        int a = rt<<1,b = a|1;
        pos = rt;
        if(a <= sz&&cmp(t[a] , x)) pos = a;
        if(b <= sz&&cmp(t[b] , t[pos])) pos = b;

        if(pos == rt) break;
        t[rt] = t[pos];
        h[t[rt]] = rt;
        rt = pos;
    }
    t[pos] = x;
    h[t[pos]] = pos;
}

void Heap::build_heap()
{
	for(int i = sz/2; i >= 1; --i){
		adjust_min_heap(i);
	}
}

int Heap::pop()
{
	if(sz >= 1){	
		t[1] = t[sz--];
		h[t[1]] = 0;
		adjust_min_heap(1);
	}
	else sz--;
}

void Heap::push(int x)
{
    int i = ++sz;//自己节点的编号
    while(i > 1)
    {
        int p = i/2;//父节点
        if(cmp(t[p] , x)) {
        	break;
        }
        t[i] = t[p];
        h[t[i]] = i;
        i = p;
    }
    t[i] = x;
    h[t[i]] = i;
}

Queue::Queue()
{
	full = false;
	top = cntlack = 0;
	memset(inq,0,sizeof(inq));
	memset(a,0,sizeof(a));
}

void Queue::push(int x)
{
	printf("请求页面：%d——", x);
	if(inq[x]) printf("命中\n");
	else {
		cntlack++;
		if(top >= MemorySize){
			top = 0;
			full = true;
		}
		if(!full) printf("缺页，直接存入，新增页%d\n", x);
		else{
			printf("缺页，淘汰页 %d\n", a[top]);
			inq[a[top]] = 0;
			}
		a[top++] = x;
		inq[x] = 1;
	}
}