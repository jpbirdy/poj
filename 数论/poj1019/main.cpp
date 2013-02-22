/**
���⣺����һ������
1 12 123 1234...�������һ���ַ���
1121231234�������е�i���ϵ����Ƕ��١�

�����⣬������飬������i��ȵ�i-1���һ����i����iռ����λ����i��ͱ�i-1������λ

��һ������S���浽��ǰ��һ���ж��ٸ�������λ����
���������ҵ��������ĳһλ��ȡ����λ��������

*/
#include <stdio.h>
#include <math.h>

unsigned int a[31270], s[31270];

/* ��� */
void reset()
{
    int i;
    a[1] = 1;
    s[1] = 1;
    for(i = 2; i < 31270; i++)
    {
        /* ÿһ�����ֶ�����һ�鳤 (int)log10((double)i) + 1 */
        a[i] = a[i-1] + (int)log10((double)i) + 1;
        s[i] = s[i-1] + a[i];
    }
}

/* ���� */
int work(int n)
{
    int i = 1;
    int length = 0;

    /* �ҵ� n ���ڵ��� */
    while (s[i] < n) i++;

    /* n �ڸ�����±� */
    int pos = n - s[i-1];

    /* length: nָ������ֵ����һλ���±� */
    for (i = 1; length < pos; i++)
    {
        length += (int)log10((double)i) + 1;
    }

    /* ȥ������λ���������Ȼ��ȡ�� */
    /* i: nָ������� + 1 */
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
