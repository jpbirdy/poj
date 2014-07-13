#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

const int N=10000;
long long A[N];
int size = 0;

void swap(long long &a,long long &b)
{
    long long t;
    t=a;a=b;b=t;
}



//��iΪ��������һ������ѣ����µ���
void max_heapify(long long a[],int i)
{
    //����0��ʼ��ţ����ӽڵ�2i+1�����ӽ��2i+2
    int left = i*2+1;
    int right = i*2+2;
    int largest = i;
    if(left<size && a[left]>a[largest])
        largest = left;
    if(right<size && a[right]>a[largest])
        largest = right;
    if(largest!=i)
    {
        swap(a[i],a[largest]);
        max_heapify(a,largest);
    }
}

//��iΪ��������һ��С���ѣ����µ���
void min_heapify(long long a[],int i)
{
    //����0��ʼ��ţ����ӽڵ�2i+1�����ӽ��2i+2
    int left = i*2+1;
    int right = i*2+2;
    int largest = i;
    if(left<size && a[left]<a[largest])
        largest = left;
    if(right<size && a[right]<a[largest])
        largest = right;
    if(largest!=i)
    {
        swap(a[i],a[largest]);
        min_heapify(a,largest);
    }
}


//��size/2��ʼ����Ϊsize/2�Ժ����нڵ㶼�����ж��ӽڵ�
//��ǰ����������ÿ��Ԫ�ض�������Ϊһ������ѵĸ�����������Ȼ����
void build_max_heap(long long a[])
{
    int i;
    for(i=size/2 ; i>=0 ; i--)
        max_heapify(a,i);
}

void build_min_heap(long long a[])
{
    int i;
    for(i=size/2 ; i>=0 ; i--)
        min_heapify(a,i);
}


void max_heap_sort(long long a[])
{
    int i;
    build_max_heap(a);
    for(i=size-1 ; i>0 ; i--)
    {
        printf("%d ",a[0]);
        swap(a[0],a[i]);
        max_heapify(a,0);
    }
    printf("%d\n",a[0]);
}


void min_heap_sort(long long a[])
{
    int i;
    build_min_heap(a);
    for(i=size-1 ; i>0 ; i--)
    {
        printf("%d ",a[0]);
        swap(a[0],a[i]);
        min_heapify(a,0);
    }
    printf("%d\n",a[0]);
}

int main()
{
    int i;
    freopen("out.txt","r",stdin);

    for(int i=0 ; i<N ; i++)
        scanf("%lld",A+i);
    size = N;
    build_min_heap(A);

    long long x;
    while(scanf("%lld",&x)!=EOF)
    {
        if(x>A[0])
        {
            A[0] = x;
            min_heapify(A,0);
        }
    }

    /*
    for(i=size-1 ; i>0 ; i--)
    {
        printf("%d ",A[0]);
        swap(A[0],A[i]);
        size--;
        min_heapify(A,0);
    }
    printf("%d\n",A[0]);
    */

    return 0;
}
