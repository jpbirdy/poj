/**
���߶�����
��n��������m�����ߣ�ÿ�����߻���һ������ֵx�����ҿ��Կ�����������x�Ķ�������Ҫ֧��x�����

����n��������������m�����ߵ�����������н⣬���֧�����ٵĽ����
��������޽�

̰���㷨��
����ĳ���������ӵ�ǰδ��Ӷ���������ҳ�һ�����Կ���������ֵ��С��һ��
̰���㷨��ȷ��
���㷨���Ա�֤���н������£�����������ֵ��С

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
#include <algorithm>
using namespace std;

const int MAX_N = 20010;
int dragon[MAX_N],loowater[MAX_N];
bool b[MAX_N];


int main()
{
    int n,m;
    int i,j;
    int min_res = 0;
    while(scanf("%d%d",&n,&m)==2 && n && m)
    {
        for(i=0 ; i<n ; i++)
            scanf("%d",&dragon[i]);
        for(i=0 ; i<m ; i++)
            scanf("%d",&loowater[i]);
        if(n>m)
        {
            printf("Loowater is doomed!\n");
            continue;
        }
        memset(b,0,sizeof(b));
        min_res = 0;
        //sort(dragon,dragon+n);        //�������������Բ�����
        sort(loowater,loowater+m);
        for(i=0 ; i<n ; i++)
        {
            for(j=0 ; j<m ; j++)
                if(!b[j] && loowater[j]>=dragon[i])
                {
                    b[j] = true;
                    min_res+=loowater[j];
                    break;
                }
            if(j==m) break;
        }
        if(i==n)
            printf("%d\n",min_res);
        else
            printf("Loowater is doomed!\n");
    }
    return 0;
}
