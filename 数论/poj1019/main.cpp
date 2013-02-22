/**
题意：这样一组序列
1 12 123 1234...最终组成一个字符串
1121231234，求其中第i个上的数是多少。

基本题，将其分组，这样第i组比第i-1组多一个数i，则i占多少位，第i组就比i-1组多多少位

用一个数组S保存到当前组一共有多少个数，定位到组
再在组内找到这个数的某一位，取出该位就是所求

*/
#include <stdio.h>
#include <math.h>

unsigned int a[31270], s[31270];

/* 打表 */
void reset()
{
    int i;
    a[1] = 1;
    s[1] = 1;
    for(i = 2; i < 31270; i++)
    {
        /* 每一组数字都比上一组长 (int)log10((double)i) + 1 */
        a[i] = a[i-1] + (int)log10((double)i) + 1;
        s[i] = s[i-1] + a[i];
    }
}

/* 计算 */
int work(int n)
{
    int i = 1;
    int length = 0;

    /* 找到 n 所在的组 */
    while (s[i] < n) i++;

    /* n 在该组的下标 */
    int pos = n - s[i-1];

    /* length: n指向的数字的最后一位的下标 */
    for (i = 1; length < pos; i++)
    {
        length += (int)log10((double)i) + 1;
    }

    /* 去掉所求位后面的数字然后取余 */
    /* i: n指向的数字 + 1 */
    return ((i-1) / (int)pow((double)10, length - pos)) % 10;
}

int main()
{
    int t;
    unsigned int n;
    reset();
	scanf("%d",&t);
    while(t--)
    {
		scanf("%d",&n);
		printf("%d\n",work(n));
    }
    return 0;
}
