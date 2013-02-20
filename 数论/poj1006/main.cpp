/*
中国剩余定理

给定P,E,I3个数，求一个数x
x % 23 = p
x % 28 = e
x % 33 = i

首先找到23、28、33(m1,m2,m3)两两的最小公约数
924 759 644
再将这些数*ki 得到一个 M1,M2,M3,使得Mi % mi = 1;这个称之为Mi相对于mi的数论倒数
M1，M2，M3分别是5544，14421，1288，
所求结果为  (5544*p + 14421*e + 1288*i) % lcm(23,28,33)
推理也很简单
5544被23除余1，其他整除，*p之后即余p，其他整除
14421、1288除23一定整除，故结果一定被23除一定与p
另外两种类似。
而结果减去23,28,33的最小公倍数结果一定不变

*/
#include <cstdio>
using namespace std;

int main()
{
    int p, e, i, d, ans;
    int icase = 1;
    while(1)
    {
        scanf("%d%d%d%d",&p,&e,&i,&d);
        if(p == -1 && e == -1 && e == -1 && d == -1)
            break;
      	ans = (5544 * p + 14421 * e + 1288 * i ) % (23 * 28 * 33) - d;
      	//ans = (5544 * p + 14421 * e + 1288 * i ) % 21252 - d;
        while (ans <= 0)
            ans += 21252;
        printf("Case %d: the next triple peak occurs in %d days.\n",icase,ans);
        icase ++;
    }
    return 0;
}
