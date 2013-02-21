/**
题目给定两个数 a,b，表示一种a*b的矩形
求至少需要多少种这样的矩形可以组合成一个正方形

要组成正方形，边长为lcm(a,b)，所需的个数为lcm(a,b)^2 / a / b; = lcm(a,b)/gcd(a,b)
*/
#include <iostream>
#include <cstdio>
using namespace std;


long long gcd(long long a,long long b)
{
	if (a%b==0) return b;
	return gcd(b,a%b);
}
long long lcm(long long a,long long b)
{
	return a/gcd(a,b)*b;
}

void swap(long long &x,long long &y)
{
	if (x < y)
	{
		long long temp = x;
		x = y;
		y = temp;
	}
}


int main()
{
	long long n,m;
	while (1)
	{
		scanf("%lld%lld",&n,&m);
		if (n == 0 && m == 0)
            break;
		swap(n,m);
		if (n % m == 0)
			printf("%lld\n",n/m);
		else
			printf("%lld\n",lcm(n,m)/gcd(n,m));
	}
	return 0;
}
