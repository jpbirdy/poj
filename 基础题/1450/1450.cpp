//��Ŀ�����ǣ�����һ��M*N��ķ���Ҫ��һ��·���������е㡣
//����˼·�ܼ򵥣�����Ҫ���ӵ��㷨
//����ĵ�ͱߺ̶ܹ������Ե�M��NͬʱΪ����ʱ��ÿ�ζ��߱ߵ����������㲻���ڱߡ����Գ����ǣ�M*N-1)+1.414
//����ֻ�߱�һ����������Ҳ��ظ�
//ÿ���� һ������Ҫ��һ���ߣ��������е�����ҪM*N���������������ǰ��M*N-1����ͨ�����ߣ����һ����Ҫ�߶Խ���

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t;
    int tt = 1;
    scanf("%d",&t);
    while(t--)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        printf("Scenario #%d:\n",tt++);
        if(m%2 && n%2) printf("%d.41\n\n",m*n);
        else printf("%d.00\n\n",m*n);
    }
    return 0;
}

