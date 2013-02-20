/**
无限背包问题（完全背包）
给定5中硬币，第一种价值为1，其他价值不等，但都<100，让这5种硬币组合为[1,100]的所有钱，求每种最少所需的硬币数
输出所有所需的硬币的平均数和最大值

无限背包问题，背包容积相当于组合后的钱数，物品相当于硬币，硬币可以使用无限多个

规定钱数可以加可以减，先正向加一次，再反向减一次
所以背包的递推范围不能只到100
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int(i)=(n)-1;(i)>=0;(i)--)
#define SZ(c) ((int)(c).size())
#define ITER(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FIND(x,c) ((c).find((x))!=(c).end())

#define INF (0x7fffffff-1)

#define N 6
#define V 2000

int coin[N+1];
int F[V+1];

inline int min(const int a, const int b)
{
	return a < b ? a : b;
}

//01背包
//注意钱数可加可减，DP的范围不能只到100
//这里DP到2000
void zero_one_pack(int n, int v)
{
	int i;
	int j;
	for (i = 1; i <= v; i++)
		F[i] = INF;
	F[0] = 0;


	for (i = 1; i <= n; i++)
	{
		for (j = coin[i]; j <= v; j++)
			F[j] = min(F[j], F[j-coin[i]]+1);
	}
	for (i = 1; i <= n; i++)
	{
		for (j = v - coin[i]; j >= 1; j--)
			F[j] = min(F[j], F[j+coin[i]]+1);
	}
}

int main(void)
{
	int i;
	int t;
	scanf("%d", &t);
	while (t--)
	{
		for (i = 1; i <= N; i++)
			scanf("%d", &coin[i]);

		zero_one_pack(N, V);

		int maxcoin = 0;
		double sum = 0;
		for (i = 1; i <= 100; i++)
		{
			sum += F[i];
			if (maxcoin < F[i])
				maxcoin = F[i];
		}
		printf("%.2lf %d\n", sum/100.0, maxcoin);
	}

	return 0;
}
