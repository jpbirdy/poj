/*
    给定任意一个正整数，求比这个数大且最小的“不重复数”，“不重复数的含义是相邻两位不相同，例如1101是不重复数”

*/
#include <stdio.h>
#include <stdlib.h>
int getNumNonrepetition(const int NumGived)
{
    int flag = 0;//为0表示该数不是“不重复数”
    int numRepeat = NumGived;
    int numTemp = 0;//
    int currentBit = 0, lastBit = 0;//前后数位索引
    while(1)
    {
        numRepeat++;
        //初始化后索引
        numTemp = numRepeat;
        lastBit = numTemp % 10;
        numTemp /= 10;
        flag = 1;
        //判断该数是不是“非重复数”
        while(numTemp != 0)
        {
            currentBit = numTemp % 10;
            numTemp /= 10;
            if(lastBit == currentBit)
            {
                flag = 0;
                break;
            }
            lastBit = currentBit;
        }
        if(flag == 1)//该数为不重复数，返回
        {
            return numRepeat;
        }
    }
}
int main(void)
{
    int NumGived = 19922884;

    while(scanf("%d",&NumGived)==1)
    {
        int result = getNumNonrepetition(NumGived);
        printf("%d\n", result);
    }

    return 0;
}
