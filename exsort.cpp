#include <bits/stdc++.h>
using namespace std;
const int E = 6;//排序10^e个整数
const int maxn = 1e5 + 5;//内部排序最多能排的元素个数
const int maxlen = 1e5;//每个文件所含有的最多的数字个数
int a[maxn];//把小文件里的内容读到a数组，排序
int val[maxn];//用与K路归并，存储K个不同文件里的数字
FILE *fp[maxn];//文件指针
char file[maxn][20];//保存文件名的字符串

/*quicksort用于内部排序*/
int partition(int a[],int low,int high);
void Qsort(int a[],int low,int high);

void createfile(char s[],int k);//生成文件名字，文件名字是数字1～k,数字转化成字符串

struct Heap//K路归并，堆排序
{
	int t[maxn],sz;
	Heap(){sz = 0;}
	void init(int cnt);
	bool empty();
	bool cmp(int x,int y);
	void adjust_min_heap(int rt);//调整堆
	void build_heap();//建堆
	int top();//取堆顶元素
	int pop();//弹出堆顶元素
	void push(int x);//插入元素
}h;

int main()
{
	clock_t start = clock();//开始时间
    //bigdata文件存放原始的大量数据，如1000W个无序数字
    FILE *rbd = fopen("bigdata","r");
    //把bigdata文件分割成大小不超过maxlen个数的小文件
    int x = 0,k = 1;
    for(int i = 0;~fscanf(rbd,"%d",&x); i = (i+1)%maxlen){
    	if(i == 0){
    		createfile(file[k],k);
    		fp[k] = fopen(file[k],"w");
    	}
    	fprintf(fp[k],"%d\n",x);
    	if(i == maxlen-1){
    		fclose(fp[k]);
    		k++;
    	}
    }
    if(fp[k]!=NULL){
    	fclose(fp[k]);
    	k++;
    }
    k--;
    fclose(rbd);

    //对K个文件分别sort
    for(int i = 1; i <= k; ++i){
    	fp[i] = fopen(file[i],"r");
    	int j = 0;
    	for(j = 0;~fscanf(fp[i],"%d",a+j);++j);
    	//cout << j << endl;
    	Qsort(a,0,j);
    	fclose(fp[i]);
    	fp[i] = fopen(file[i],"w");
    	for(int z = 0; z < j; ++z)
    		fprintf(fp[i], "%d\n", a[z]);
    	fclose(fp[i]);
    }

    //k-way merge
    for(int i = 1; i <= k; ++i){
    	fp[i] = fopen(file[i],"r");
    	fscanf(fp[i],"%d",&val[i]);//把小文件里的数读到val里面来;
    }
    h.init(k);//注意heap的t数组里面存放的是数字的id号，即他是哪个文件里的数字
    h.build_heap();
    FILE *wrbd = fopen("bigdata","w");
    while(!h.empty())
    {
    	int rt = h.top();
    	int next_number;
    	fprintf(wrbd, "%d\n", val[rt]);//把最小堆顶部的元素弹出，输出到bigdata文件中
    	h.pop();
    	if(fscanf(fp[rt],"%d",&next_number)!=EOF){
    		val[rt] = next_number;
    		h.push(rt);
    	}
    }
    clock_t end = clock();
    printf("10^%d个元素：\n",E);
    printf("外部排序时间：%f\n",  (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}

/*-----------------分割线---------------*/
int partition(int a[],int low,int high)
{
    int pivotkey=a[low];
    high--;
    while(low<high)
    {
        while(low<high&&a[high]>=pivotkey) high--;
        a[low] = a[high];
        while(low<high&&a[low]<=pivotkey) low++;
        a[high] = a[low];
    }
    a[low] = pivotkey;
    return low;
}
void Qsort(int a[],int low,int high)
{
    int pivot;
    if(high - low > 1)
    {
        pivot=partition(a,low,high);
        Qsort(a,low,pivot);
        Qsort(a,pivot+1,high);
    }
}
void createfile(char s[],int k)
{
	int i = 0;
	
	do{
		s[i++] = '0'+(k%10);
		k/=10;
	}while(k>0);
	reverse(s,s+i);
	s[i] = '\0';
}
void Heap::init(int cnt)
{
	sz = cnt;
	for(int i = 1; i <= sz; ++i) t[i] = i;
}
bool Heap::empty(){return sz == 0;}
bool Heap::cmp(int x,int y){return val[x] < val[y];}
int Heap::top(){return t[1];}
void Heap::adjust_min_heap(int rt)
{
    //从rt往下调整
    int x = t[rt],pos=rt;
    while(rt < sz)
    {
        int a = rt<<1,b = a|1;
        pos = rt;
        if(a <= sz&&cmp(t[a] , x)) pos = a;
        if(b <= sz&&cmp(t[b] , t[pos])) pos = b;
        if(pos == rt) break;
        t[rt] = t[pos];
        rt = pos;
    }
    t[pos] = x;
}
void Heap::build_heap()//建堆
{
	for(int i = sz/2; i >= 1; --i){
		adjust_min_heap(i);
	}
}
int Heap::pop()//弹出堆顶元素
{
	if(sz >= 1){
		
		t[1] = t[sz--];
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
        	break;//如果没有大小颠倒则退出
        }
        t[i] = t[p];
        i = p;
    }
    t[i] = x;
}