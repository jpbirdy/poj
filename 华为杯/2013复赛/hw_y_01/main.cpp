#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAX = 1005;
struct MAP
{
 int x;
 int y;
 int pow;
};
struct Node
{
 int x;
 int y;
};
MAP m[MAX*MAX];
Node r[MAX];
int root[MAX];
int rank[MAX];
int n,k;
bool cmp(MAP m1,MAP m2)
{
 if(m1.pow<m2.pow)
  return true;
 return false;
}
bool com(Node n1,Node n2)
{
 if(n1.x<n2.x)
  return true;
 return false;
}
int Find(int x)
{
 if(x!=root[x])
 {
       root[x] = Find(root[x]);
 }
 return root[x];
}
int MAXI = 0;
bool Union(int x,int y,int pow)
{
      if(x==y)
    return 0;
   if(rank[x]>rank[y])
   {
          root[y] = x;
   }
   else
   {
    if(rank[x] == rank[y])
    {
     rank[y]++;
    }
    root[x] = y;
   }
      if(MAXI < pow)
   {
    MAXI = pow;
   }
   return 1;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //cin>>n>>k;
    while(scanf("%d%d",&n,&k)==2)
    {

    for(int i=0;i<n;i++)
    {
        root[i] = i;
        rank[i] = 0;
    }
    for(int i = 0;i < k;i++)
    {
         cin>>m[i].x>>m[i].y>>m[i].pow;
         m[i].x;
         m[i].y;
    }
       sort(m,m+k,cmp);

        MAXI = 0;
        int count = 0;
        int sum = 0;
        for(int i = 0;i < k;i++)
        {
            bool flag = Union(Find(m[i].x),Find(m[i].y),m[i].pow);

            if(flag)
            {
             r[count].x = m[i].x;
             r[count].y = m[i].y;
             count++;
             sum+=m[i].pow;
            }
        }
    //sort(r,r+count,com);
    //cout<<count<<endl;
    //cout<<MAXI<<endl;

        printf("%d %d\n",sum,MAXI);
    }

    return 0;
}
