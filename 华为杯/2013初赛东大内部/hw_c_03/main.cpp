///http://blog.pureisle.net/archives/887.html

/**
�������˷�Ӧ�ã�
matrixMultiplicationΪ����˷���logN���Ӷ��㷨
��֪쳲��������� f(n) = f(n-1) + f(n-2)
���� f(n) = a*f(n-1) + b*f(n-2)
�о���˷���
   a  b   *  f(n-1) =  f(n)
   1  0      f(n-2)   f(n-1)
����չ�� ��
   a  b  ^ n-1  * f(1)  =   f(n)
   1  0           f(0)     f(n-1)

   Ҳ���Ǽ������ {{a,b},{1,0}}^n-1���ݵ�ֵ�����ܵõ�f(n)
*/
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define N 2
const long long MOD = 1000000007;

struct Matrix
{
    long long m[2][2];
};
void matrixMultiplication(Matrix &res,long long n)
{
    Matrix tm,tm1;
    int i,j,k;
    tm=res;
    for (i=0;i<N;i++)
        for (j=0;j<N;j++)
        {
            res.m[i][j]=(i==j);
        }
    if(n==0){ return; }
    while(n)
    {

        if(n&1)
        {
            memset(tm1.m,0,sizeof(tm1.m));
            for (i=0;i<N;i++)
            {
                for (j=0;j<N;j++)
                {
                    for(k=0;k<N;k++)
                    {
                        tm1.m[i][j] += (res.m[i][k]*tm.m[k][j])%MOD;
                        tm1.m[i][j] %= MOD;
                    }
                }
            }
            res=tm1;
        }
        memset(tm1.m,0,sizeof(tm1.m));
        for (i=0;i<N;i++)
        {
            for (j=0;j<N;j++)
            {
                for(k=0;k<N;k++)
                {
                    tm1.m[i][j] += (tm.m[i][k]*tm.m[k][j])%MOD;
                    tm1.m[i][j] %= MOD;
                }
            }
        }
        tm=tm1;
        n>>=1;
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    Matrix mat;
    long long n;
    long long f0,f1;
    while(cin>>f0>>f1>>mat.m[0][0]>>mat.m[0][1]>>n)
    {
        mat.m[1][0]=1;
        mat.m[1][1]=0;
        matrixMultiplication(mat,n-1);
        cout<<(mat.m[0][0]*f1 % MOD + mat.m[0][1]*f0 % MOD)%MOD<<endl;
    }
}
