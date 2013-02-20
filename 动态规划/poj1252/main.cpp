/**
���ޱ������⣨��ȫ������
����5��Ӳ�ң���һ�ּ�ֵΪ1��������ֵ���ȣ�����<100������5��Ӳ�����Ϊ[1,100]������Ǯ����ÿ�����������Ӳ����
������������Ӳ�ҵ�ƽ���������ֵ

���ޱ������⣬�����ݻ��൱����Ϻ��Ǯ������Ʒ�൱��Ӳ�ң�Ӳ�ҿ���ʹ�����޶��

�涨Ǯ�����Լӿ��Լ����������һ�Σ��ٷ����һ��
���Ա����ĵ��Ʒ�Χ����ֻ��100
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

//01����
//ע��Ǯ���ɼӿɼ���DP�ķ�Χ����ֻ��100
//����DP��2000
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
