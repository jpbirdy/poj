#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


int Min(int a,int b)
{
    return ((a<b)?a:b);
}

int Min(int a,int b,int c)
{
    if(a<b && a<c) return a;
    else if(b<c) return b;
    return c;
}

int a[100010];
int s[100010];

int n;
int m;
int k1,k2;
int k;

int mod[3];

int main()
{
    freopen("input.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        memset(a,0,sizeof(a));
        for(int i=0 ; i<n ; i++)
            scanf("%d",a+i);
        for(int i=0 ; i<n ; i++)
            scanf("%d",s+i);

        mod[0] = mod[1] = mod[2] = 0;
        mod[2] = 1;

        k1 = 2;
        k2 = n-1-2;

        mod[k2%3] = 1;

        a[k1] = s[k1-1]-s[k1-2];
        a[k2] = s[k2+1]-s[k2+2];
        k1+=3;
        k2-=3;
        while(k1<n)
        {
            a[k1] = s[k1-1] - s[k1-2] + a[k1-3];
            a[k2] = s[k2+1] - s[k2+2] + a[k2+3];
            if(k1==k2) break;
            k1+=3;
            k2-=3;
        }

        if((mod[0]+mod[1]+mod[2])==1)
        {
            for(int i=0 ; i<n ; i++)
                if(mod[(i%3)]==0 && a[i]!=-1)
                {
                    k1 = i+3;
                    while(k1<n)
                    {
                        a[k1] = s[k1-1] - s[k1-2] + a[k1-3];
                        k1+=3;
                    }
                    k2 = i-3;
                    while(k2>=0)
                    {
                        a[k2] = s[k2+1] - s[k2+2] + a[k2+3];
                        k2-=3;
                    }
                    break;
                }

        }

        scanf("%d",&m);
        while(m--)
        {
            scanf("%d",&k);
            if(a[k]!=-1)
            {
                printf("%d\n",a[k]);
            }
            else
            {
                int l=k-1;
                int r=k+1;
                int flag1 ,flag2;
                if(l<0 || a[l]!=-1) flag1 = 1;
                else flag1 = 0;
                if(r==n || a[r]!=-1) flag2 = 1;
                else flag2 = 0;
                if(flag1 && flag2)
                {
                    if(k==0) printf("%d\n",s[k]-a[r]);
                    else if(k==(n-1)) printf("%d\n",s[k]-a[l]);
                    else printf("%d\n",s[k]-a[l]-a[r]);
                    //printf("%d\n",s[k]-a[l]-a[r]);
                }
                else if(flag1)
                {
                    if(k==0) printf("%d\n",s[k]);
                    else
                    {
                        r = k+2;
                        if(r<n)
                            printf("%d\n",Min(s[k]-a[l],s[k-1]-a[l],s[k+1]-a[r]));
                        else
                            printf("%d\n",Min(s[k]-a[l],s[k-1]-a[l]));
                    }
                }
                else
                {
                    if(k==(n-1)) printf("%d\n",s[k]);
                    else
                    {
                        l = k-2;
                        if(l>=0)
                            printf("%d\n",Min(s[k]-a[r],s[k+1]-a[r],s[k-1]-a[l]));
                        else
                            printf("%d\n",Min(s[k]-a[r],s[k+1]-a[r]));
                    }
                }
            }
        }

    }

    return 0;
}
