/*
    ��������һ������������������������С�ġ����ظ������������ظ����ĺ�����������λ����ͬ������1101�ǲ��ظ�����

*/
#include <stdio.h>
#include <stdlib.h>
int getNumNonrepetition(const int NumGived)
{
    int flag = 0;//Ϊ0��ʾ�������ǡ����ظ�����
    int numRepeat = NumGived;
    int numTemp = 0;//
    int currentBit = 0, lastBit = 0;//ǰ����λ����
    while(1)
    {
        numRepeat++;
        //��ʼ��������
        numTemp = numRepeat;
        lastBit = numTemp % 10;
        numTemp /= 10;
        flag = 1;
        //�жϸ����ǲ��ǡ����ظ�����
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
        if(flag == 1)//����Ϊ���ظ���������
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
