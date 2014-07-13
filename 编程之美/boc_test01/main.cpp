/*
大数 无*大数
*/

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

const int maxn = 8010;
const int base = 10000;
const int len = 4;
const int power10[len] = {1, 10, 100, 1000};

struct largenum
{
	int l;
	int num[maxn];

	bool iszero()
	{
		return (l == 1 && num[1] == 0);
	}

	int compare(const largenum & a)
	{
		if (l > a.l) return 1;
		if (l < a.l) return -1;
		for (int i = l; i >= 1; i--)
			if (num[i] != a.num[i])
			{
				if (num[i] > a.num[i]) return 1;
				else return -1;
			}
			return 0;
	}

	void add(const largenum & a)
	{
		if (a.l > l) l = a.l;
		for (int i = 1; i <= l; i++)
		{
			num[i] += a.num[i];
			if (num[i] >= base)
			{
				num[i] -= base; num[i + 1]++;
			}
		}
		if (num[l + 1] > 0) l++;
	}

	void dec(const largenum & a)
	{
		for (int i = 1; i <= l; i++)
		{
			num[i] -= a.num[i];
			if (num[i] < 0)
			{
				num[i] += base; num[i + 1]--;
			}
		}
		while (l > 1 && num[l] == 0) l--;
	}

	void mul(const int x)
	{
		int temp, p = 0;
		for (int i = 1; i <= l; i++)
		{
			temp = num[i] * x + p;
			p = temp / base;
			num[i] = (int) (temp - base * p);
		}
		while (p > 0)
		{
			l ++; num[l] = (int) (p % base); p /= base;
		}
	}

	void dev(const int x)
	{
		int temp, left = 0;
		for (int i = l; i >= 1; i--)
		{
			temp = left * base + num[i];
			num[i] = temp / x;
			left = temp - x * num[i];
		}
		while (l > 1 && num[l] == 0) l--;
	}

	void print()
	{
		cout << num[l];
		for (int i = l - 1; i >= 1; i--)
		{
			for (int j = 1; j < len; j++)
				if (num[i] < power10[j])
					cout << '0';
				cout << num[i];
		}
	}
};

struct bignum
{
	bool f;
	largenum key;

	void init(int x)
	{
		if (x < 0)
		{
			f = false; x = -x;
		}
		else
			f = true;
		memset(key.num, 0, sizeof(key.num));
		if (x >= base)
		{
			key.l = 2; key.num[2] = x / base;
		}
		else
			key.l = 1;
		key.num[1] = x % base;
	}

	bool iszero()
	{
		return (key.iszero());
	}

	bool biggerthan(const bignum &a)
	{
		if (f != a.f) return f;
		if (f) return (key.compare(a.key) == 1);
		else return (key.compare(a.key) == -1);
	}

	void add(const bignum & a)
	{
		if (a.f == f) key.add(a.key);
		else
		{   //正+负   负+正
			int c = key.compare(a.key);
			if (c == 0)	init(0);
			else if (c == 1) key.dec(a.key);
			else
			{
				largenum temp;
				temp = a.key; temp.dec(key);
				f = !f; key = temp;
			}
		}
	}

	void add(const int x)
	{
		bignum temp; temp.init(x); add(temp);
	}

	void dec(bignum & a)
	{
		a.f = !a.f;
		add(a);
		a.f = !a.f;
	}

	void dec(const int x)
	{
		bignum temp; temp.init(-x); add(temp);
	}

	void mul(int x)
	{
		if (iszero()) return;
		if (x == 0)
		{
			init(0); return;
		}
		if (x < 0)
		{
			f = !f; x = -x;
		}
		key.mul(x);
	}

	void dev(int x)
	{
		if (iszero()) return;
		if (x < 0)
		{
			f = !f; x = -x;
		}
		key.dev(x);
	}

	void print()
	{
		if (!f && !iszero()) cout << '-';
		key.print();
	}
};


int main()
{
	bignum x1,x2;
	string str1,str2;
    cin >> str1 >> str2;
    x1.init(0);
    x2.init(0);
    for(int i=0 ; i<str1.size() ; i++)
    {
        x1.mul(10);
        x1.add(str1[i]-'0');
    }
    for(int i=0 ; i<str2.size() ; i++)
    {
        x2.mul(10);
        x2.add(str2[i]-'0');
    }

    x1.add(x2);
    x1.print();
    printf("\n");

	return 0;
}
