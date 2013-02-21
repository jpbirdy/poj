/**
筛法求素数
题目给定两个数l,u，求在l和u之中相邻的素数中差最小和差最大的数
*/


#include<cstdio>
#include<cmath>
#include<cstring>
#define FR 50001
int prims[FR];
int len;
char canVisit[2000000];
void filtingNumbers()
{
	int i;
	int tmp;
	len=0;
	memset(canVisit,1,sizeof(canVisit));
	prims[len++]=2;
	for(i=3;i<FR;i+=2)
	{
		if(canVisit[i])
		{
			prims[len++] = i;
			for(tmp=i;tmp<FR;tmp+=i)
				canVisit[tmp]=false;
		}
	}
}
inline int max(int a,int b)
{
	return a>b?a:b;
}
void filtingRegion(int frm,int to)
{
	int i,tmp;
	memset(canVisit,1,sizeof(canVisit));
	for(i=0;i<len&&i<to;i++)
	{
		tmp = frm/prims[i]*prims[i];
		if(tmp<frm)tmp+=prims[i];
		if(tmp<0)continue;
		if(tmp<prims[i]<<1)
			tmp = prims[i]<<1;
		for(;tmp<=to&&tmp>0;tmp+=prims[i])
			canVisit[tmp-frm]=false;
	}
}
void solve(int frm,int to)
{
	int i;
	int dismin=0x1f1f1f1f,dismax=-0x1f1f1f1f,tmp;
	int p[2],pmin[2],pmax[2];
	int loc=0;
	bool start=false;
	int cnt=0;
	for(i=frm;i<=to&&i>0;i++)
	{
		if(canVisit[i-frm]&&i!=1)
		{
			cnt++;
			p[loc]=i;
			loc=(loc+1)%2;
			if(start)
			{
				tmp = i-p[loc];
				if(dismin>tmp)
				{
					dismin = tmp;
					pmin[0] = p[loc];
					pmin[1] = i;
				}
				if(dismax<tmp)
				{
					dismax = tmp;
					pmax[0] = p[loc];
					pmax[1] = i;
				}
			}
			start = true;
		}
	}
	if(cnt>1)
	{
		printf("%d,%d are closest, %d,%d are most distant.\n",pmin[0],pmin[1],pmax[0],pmax[1]);
	}
	else
	{
		printf("There are no adjacent primes.\n");
	}
}
int main()
{
	filtingNumbers();
	//printf("%d\n",len);
	int frm,to;
	while(~scanf("%d%d",&frm,&to))
	{
		filtingRegion(frm,to);
		solve(frm,to);
	}
	return 0;
}
/*
1 2
2146483648 2147483647
2147483047 2147483647
*/
/*
There are no adjacent primes.
2146483811,2146483813 are closest, 2146841093,2146841273 are most distant.
2147483053,2147483059 are closest, 2147483179,2147483237 are most distant.
*/
