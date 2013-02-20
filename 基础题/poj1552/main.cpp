#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    bool a[100];//记录输入中出现的数，逐个判断，O(N)
    int n,i;
    int temp;
    int max,min;
    while(scanf("%d",&n)==1)
    {
          if(n==-1)break;
          max=-1;
          min=100100;
          memset(a,0,sizeof(a));
          a[n]=true;
          if(min>n)min=n;
          if(max<n)max=n;
          while(1)
          {
              scanf("%d",&n);
              if(n==0)break;
              a[n]=true;
              if(min>n)min=n;
              if(max<n)max=n;
          }
          temp=0;
          for(i=min;i<=49;i++)
          {
              if(a[i]&&a[i*2])temp++;
          }
          printf("%d\n",temp);
    }
}
