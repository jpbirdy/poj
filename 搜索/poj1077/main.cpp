 #include <stdio.h>
 #include <string.h>
 #include <queue>
 #include <ctime>
 #define N 362881
 #define ABS(x) ((x)>0?(x):(-(x)))
 using namespace std;
 const int dx[4]={0,0,1,-1};
 const int dy[4]={1,-1,0,0};
 char DIR[4]={'r','l','d','u'};
 const int pow10[10]={1,10,100,1000,10000,
                       100000,1000000,10000000,
                       100000000,1000000000};

 typedef pair<int,int> node;
 priority_queue<node,vector<node>,greater<node> > pq;
 int s,t=123456780,tp=123456870;

 int tx[9]={2,0,0,0,1,1,1,2,2},ty[9]={2,0,1,2,0,1,2,0,1};
 int fact[9];
 int f[N],g[N],z[N],dir[N],p[N];
 char vis[N];

int fail = 0;
 int h(int k)
 {
    int i,x,y,ai,ret=0;
    for(x=0;x<3;x++)
    {
        for(y=0;y<3;y++)
        {
            i=8-3*x-y;
            ai=k/pow10[i]%10;
            ret+=ABS(tx[ai]-x)+ABS(ty[ai]-y);
        }
    }
    return ret;
 }

 int hash(int k)
 {
    int i,j,ai,aj,cnt,ret=0,zero=8;
    for(i=8;i>0;i--)
    {
        ai=k/pow10[i]%10;
        if(ai==0) zero=8-i;
        cnt=0;
        for(j=i-1;j>=0;j--)
        {
            aj=k/pow10[j]%10;
            if(aj<ai) cnt++;
        }
        ret+=cnt*fact[i];
    }
    z[ret]=zero;
    return ret;
}

bool read_case()
{
    int i,cnt=0;
    char c;
    s=0;
    while(cnt<9)
    {
        if(scanf("%c",&c)==EOF)  return false;
        if(c>='1' && c<='8' || c=='x')
        {
            cnt++;
            c=(c=='x'?'0':c);
            s=s*10+c-'0';
        }
    }
    return true;
 }

 int move(int k,int pos,int d)
 {
    int i,j,ni,nj,npos,a;
    i=pos/3;
    j=pos%3;
    ni=i+dx[d];
    nj=j+dy[d];
    if(ni<0 || nj<0 || ni>=3 || nj>=3) return -1;
    npos=ni*3+nj;
    a=k/pow10[8-npos]%10;
    return k+a*(pow10[8-pos]-pow10[8-npos]);
 }

 void print(int k)
 {
    if(p[k]==-1)  return;
    //printf("%d",k);
    //print(p[k]);
    //printf("%c",DIR[dir[k]]);
 }

 void process()
 {
    int u,v,uu,vv,d;
    node tmp;
    memset(vis,0,sizeof(vis));
    while(!pq.empty())  pq.pop();
    u=s;
    uu=hash(u);
    p[uu]=-1;
    vis[uu]=1;
    f[uu]=0;
    g[uu]=f[uu]+h(u);
    pq.push(make_pair(g[uu],u));
    while(!pq.empty())
    {
        tmp=pq.top(),pq.pop();
        u=tmp.second;
        uu=hash(u);
        vis[uu]++;
        if(u==t || u==tp)  break;
        for(d=0;d<4;d++)
        {
            v=move(u,z[uu],d);
            if(v==-1) continue;
            vv=hash(v);
            if(vis[vv]==2)  continue;
            if(vis[vv]==1 && f[uu]+1<f[vv])
            {
                g[vv]+=f[uu]+1-f[vv];
                f[vv]=f[uu]+1;
                p[vv]=uu;
                dir[vv]=d;
            }
            else
            {
                f[vv]=f[uu]+1;
                g[vv]=f[vv]+h(v);
                pq.push(make_pair(g[vv],v));
                vis[vv]++;
                p[vv]=uu;
                dir[vv]=d;
            }
        }
    }
    if(vis[hash(t)]!=2)
        fail++;
        //puts("unsolvable");
    //else print(hash(t)),printf("\n");
}

int main()
{
    int i;
    int t=0;
    fact[0]=1;
    for(i=1;i<9;i++)  fact[i]=fact[i-1]*i;
    freopen("in1000.txt","r",stdin);
    freopen("out.txt","w",stdout);
    double sum = 0;
    int max = 0;
    while(read_case())
    {
        int c=clock();
        process();
        int t=clock()-c;
        sum = sum+t;
        if(t>max) max = t;
        printf("%d\n",t);
    }
    printf("avg:%.3f\n",sum/1000);
    printf("max:%d\n",max);
    printf("fail:%d\n",fail);
    return 0;
 }
