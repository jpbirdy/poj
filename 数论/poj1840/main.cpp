/**
a1x1^3+a2x2^3+a3x3^3+a4x4^3+a5x5^3 = 0
有上面一个多项式，-50<= ai，xi <= 50，给定ai，求出可以满足条件的xi的方案个数

解法：
将5个项分为两组，一组为a1x1^3+a2x2^3+a3x3^3，枚举x1，x2，x3，
因为后两项和绝对值最大值12500000（50^4 + 50^4），所以如果前面的和不在对应范围舍弃。
若存在，保存每个可能的值出现的次数

然后枚举后两项，得到和为p 若在次数数组中存在-p，那么结果的个数
ans+=sum_first_3_element[-p+12500000],+12500000将负的转为正，保证数组下标为正数


*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[5];
const int Min = -50, Max = 50;
short sum_first_3_element[25000010];



int main()
{
    memset(sum_first_3_element, 0, sizeof(sum_first_3_element));
    for(int i = 0; i < 5; i++)
        scanf("%d",&a[i]);
    for(int i = Min; i <= Max; i++)
    {
        if(i == 0) continue;
        for(int j = Min; j <= Max; j++)
        {
            if(j == 0) continue;
            for(int k = Min; k <= Max; k++)
            {
                if(k == 0) continue;
                int tmp = i * i * i * a[0] + j * j * j * a[1] + k * k * k * a[2];
                if(tmp > 12500000 || tmp < -12500000)
                     continue;
                sum_first_3_element[tmp + 12500000]++;
            }
        }
    }

    int ans = 0;
    for(int i = Min; i <= Max; i++)
    {
        if(i == 0) continue;
        for(int j = Min; j <= Max; j++)
        {
            if(j == 0) continue;
            int tmp = -(i * i * i * a[3] + j * j * j * a[4]);
            ans += sum_first_3_element[tmp+12500000];
        }
    }
    printf("%d\n",ans);
    return 0;
}
