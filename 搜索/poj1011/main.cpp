/**
*木棒，题面就是中文，简单说就是有若干个长度为k的木棒被随机切下来，
得到了很多小木棒，现在已知每个小木棒的长度，求原来木棒的长度的最小值

算法：暴力法
很容易得到，原来木棒只有一根，全木木棒的长度和就是结果。
但是这个结果一定不是最小的。
木棒的长度都是整数的，最终也一定是由整数个木棒组成，所以木棒长度的可能值只能是SUM(li)的约数
枚举这些约数，暴力搜索是否能由这个长度组成
同时，木棒的最小长度必须>=给定木棒的最大长度
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int n;
int stick[100];
int total;
int ns;
int ok;
int len;
int used[100];

int cmp(const int &a,const int &b)
{
    if(a>b)return 1;
    else return 0;
}


void search(int,int,int);

void print(int x)
{
	if (x>ns)
	{
		ok=1;
		printf("%d\n",len);
		return;
	}
	int i;
	for (i=1;i<=n;i++)
		if (!used[i]) break;

	used[i]=1;
	search(x,stick[i],i);
	used[i]=0;
}

void search(int num,int now,int next)
{
	if (ok) return;
	if (now==len)
	{
		print(num+1);
		return;
	}

	if (next+1>n) return;
	int i;
	for (i=next+1;i<=n;i++)
		if (!used[i])
			if(stick[i]+now<=len)
			{
				used[i]=1;
				search(num,now+stick[i],i);
				used[i]=0;
				if (ok) return;
				if (stick[i]==len-now) return;
			}
}

int main ()
{
	while (scanf("%d",&n)==1)
	{
		if(n==0) break;
		ok = 0;
		int i;
		total = 0;
		for (i=1;i<=n;i++)
		{
		    scanf("%d",stick+i);
            total+=stick[i];
		}
		sort(stick+1,stick+n+1,cmp);
		for (i=stick[1];i<=total;i++)
			if (total%i==0&& !ok)
			{
				ns=total/i;
				memset(used,0,sizeof(used));
				len=i;
				print(1);
			}
	}
	return 0;
}
