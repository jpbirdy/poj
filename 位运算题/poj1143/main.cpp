/*
有2、3、4...20这些数，甲乙轮流从中取出某个数，取出的数满足如下特点
1、取过的数和其倍数不能再取
2、取过的数和其倍数的和不能再取
现给定一个残局（这里注意残局，但是不存在的数表示已经被取走了），由甲开始，问是否存在必胜数，输出必胜数
否则输出
There's no winning move.

此题关键在于用一个数的某些位表示某一个数是否被取走。
用一个位运算将满足1、2两个条件的数都去除
((num | 1)<< j) | (mask[j]-1);

注意PE，相邻两个测试数据间要加回车。首位不加。
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;


const int MAXN = 0xFFFFF;
int map[MAXN];

int mask[22];

int judge(int num)
{
    int i,j;
    if(map[num]==-1)
    {
        if(num==0)
        {
            map[0]=0;
            return 0;
        }

        map[num] = 0;

        for(i=2; i<=20; i++)
            if(num&mask[i])
            {
                int temp = num;
                j = i;
                while(j<=20)
                {
                    //num | 1数字1 不存在，置为1避免干扰
                    // (num | 1) <<j，所有数+j之后的情况
                    //如果某位上为0，则<<j位后，相当于这个数+j对应的数为0
                    //最后将前面的置为1，只修改第j位之后的数
                    temp&= ((num | 1)<< j) | (mask[j]-1);
                    j+=i;
                }

                if(judge(temp) == 0)
                    map[num] |=mask[i];

            }
    }
    return map[num];
}


int main()
{
    int i,t,n;
    int cases = 1;
    int num;
    memset(map,255,sizeof(map));
    mask[1] = 0;
    for(i=1 ; i<22 ; i++)
        mask[i+1]=1<<i;

    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;


        if(cases==1)
            printf("Test Case #%d\n",cases++);
        else
            printf("\nTest Case #%d\n",cases++);

        num = 0;
        for(i=0 ; i<n ; i++)
        {
            scanf("%d",&t);
            num|=mask[t];
        }
        int ans = judge(num);
        if(ans == 0)
        {
            printf("There's no winning move.\n");
        }
        else
        {
            printf("The winning moves are:");
            for(i=2 ; i<=20 ; i++)
            {
                if(ans & mask[i])
                    printf(" %d",i);
                ans&=~mask[i];
                if(ans == 0) break;
            }
            printf("\n");
        }
    }

    return 0;
}
