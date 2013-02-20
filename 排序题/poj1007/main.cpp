/*
题目中定义了一种排序方法，
就是每个字符串中，按字典序，右边的字母应该比左边的字母大，
那么我们就可以从左到右依次扫描每个字母，
然后再从这个字母开始向右扫描有没有比它小的字母，
如果有给当前字符串的“未排序程度”（暂时这么叫）加上1。
最后，按照这个未排序程度从小到大输出原字符串即可。
*/

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;



struct node
{
       int num;
       char a[55];
}dna[110];

int n,m;


int cal(char *s,int n)
{
    int i,tot=0;
    int a[4]={0};
    for (i=n-1;i>=0;i--)
    {
        switch(s[i])
        {
        case 'A':
             a[1]++;
             a[2]++;
             a[3]++;
             break;
        case 'C':
             a[2]++;
             a[3]++;
             tot+=a[1];
             break;
        case 'G':
             a[3]++;
             tot+=a[2];
             break;
        case 'T':
             tot+=a[3];
        }
    }
    return tot;
}
int cmp(const node &a,const node &b)
{
    if( a.num > b.num )
       return 0;
    else
       return 1;
}

int main()
{
    int i;
    scanf("%d%d",&n,&m);
    for (i=0;i<m;i++)
    {
        scanf("%s",dna[i].a);
        dna[i].num=cal(dna[i].a,n);
    }
    sort(dna,dna+m,cmp);
    for (i=0;i<m;i++)
        puts(dna[i].a);
    return 0;
}
