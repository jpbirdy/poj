/**
扩展欧几里得问题
一个循环
for(i = A ; i!=B ; i+=C)
    ...
给定A,B,C,k，每2^k一循环。
求循环做多少次后结束

解：
如果该循环没有达到2^k就结束，那么假设循环了x次
有
Cx + A = B
如果假设一共让i轮回了y次，就有
Cx - 2^k * y + A = B
令y'= -y
整理得

Cx + 2^k*y' = B-A

由扩展欧几里得 有对于 C 和 2^k这两个数，必然存在
Cx1 + 2^k y1 = gcd(C,2^k)

两边同乘以 (B-A)/gcd(C,2^k) 得到上面的解。
如果(B-A)/gcd(C,2^k)不能整除，则一定无解

x1*(B-A)/gcd(C,2^k)一定是一个解，但未必是最小的解，设这个解记为x'
到x'时，i已经 = B，如果再经过t次可以到达B，则一定有t*C = m 2^k
t最小 =2^k / gcd(C,2^k)
每t一循环
x = (x'%t + t)%t
得到最小x

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
using namespace std;


/**
扩展欧几里得算法
给定两个数a,b，可以使用辗转相除（欧几里得算法）得到最大公约数 gcd(a,b)
扩展欧几里得：对于任意正整数ab 一定存在一组x,y 使得 ax + by = gcd(a,b);
算法为：
当
    b = 0，gcd = a,x=1,y=0
否则
    ext_gcd(a,b,x,y) = ext_gcd(b,a%b,x1,y1);
    且有
     a%b = a-a/b*b;
     所以有
     bx1 + (a-a/b*b)y1 = gcd(a,b);
     ay1 + b(x1-a/b*y1) = gcd(a,b);
而
     ax + by = gcd(a,b);
所以有 x = y1,y = x1-a/b*y1，递推可得x,y

*/
long long extended_gcd(long long a, long long b, long long &x, long long &y)
{
    if (b ==0)
    {
        x =1;
        y =0;
        return a;
    }
    long long d = extended_gcd(b, a % b, x, y);
    long long t = x;
    x = y;
    y = t - a / b * y;
    return d;
}


int main()
{
    long long a,b,c,k;
    while (scanf("%lld%lld%lld%lld", &a, &b, &c, &k), (a | b | c | k) !=0)
    {
        long long x, y;
        long long t = b - a;
        long long h =1;
        h <<= k;
        long long g = extended_gcd(c, h, x, y);
        if (t % g !=0)
        {
            printf("FOREVER\n");
            continue;
        }
        x *= t / g;
        x = (x % (h / g) + (h / g)) % (h / g);
        printf("%lld\n", x);
    }
    return 0;
}
