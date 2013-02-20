/**
��չŷ���������
һ��ѭ��
for(i = A ; i!=B ; i+=C)
    ...
����A,B,C,k��ÿ2^kһѭ����
��ѭ�������ٴκ����

�⣺
�����ѭ��û�дﵽ2^k�ͽ�������ô����ѭ����x��
��
Cx + A = B
�������һ����i�ֻ���y�Σ�����
Cx - 2^k * y + A = B
��y'= -y
�����

Cx + 2^k*y' = B-A

����չŷ����� �ж��� C �� 2^k������������Ȼ����
Cx1 + 2^k y1 = gcd(C,2^k)

����ͬ���� (B-A)/gcd(C,2^k) �õ�����Ľ⡣
���(B-A)/gcd(C,2^k)������������һ���޽�

x1*(B-A)/gcd(C,2^k)һ����һ���⣬��δ������С�Ľ⣬��������Ϊx'
��x'ʱ��i�Ѿ� = B������پ���t�ο��Ե���B����һ����t*C = m 2^k
t��С =2^k / gcd(C,2^k)
ÿtһѭ��
x = (x'%t + t)%t
�õ���Сx

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
��չŷ������㷨
����������a,b������ʹ��շת�����ŷ������㷨���õ����Լ�� gcd(a,b)
��չŷ����ã���������������ab һ������һ��x,y ʹ�� ax + by = gcd(a,b);
�㷨Ϊ��
��
    b = 0��gcd = a,x=1,y=0
����
    ext_gcd(a,b,x,y) = ext_gcd(b,a%b,x1,y1);
    ����
     a%b = a-a/b*b;
     ������
     bx1 + (a-a/b*b)y1 = gcd(a,b);
     ay1 + b(x1-a/b*y1) = gcd(a,b);
��
     ax + by = gcd(a,b);
������ x = y1,y = x1-a/b*y1�����ƿɵ�x,y

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
