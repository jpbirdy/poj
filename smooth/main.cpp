#include <iostream>
#include <cstdio>
using namespace std;

//指数平滑,Paling,2005,6,23
bool ExSmooth(double* x,int N,int smooth,double alpha,
              double* sx1,double* sx2,double* sx3,double *para)
/*
输入：
x,时间序列数组
N,时间序列数组大小
smooth(1,一次平滑，2，二次平滑，3，三次平滑)
alpha,平滑常数
输出：
sx1,一次指数平滑结果
sx2,二次指数平滑结果
sx3,三次指数平滑结果
para,二次指数平滑，三次指数平滑的模型参数
*/
{
    int i;
    double beta,a,b,c;
    if (alpha>1 || alpha<0)
    {
        printf("平滑常数的范围为[0,1]");
        return false;
    }
    sx3[0]=sx2[0]=sx1[0]=x[0];

    for(i=1; i<N; i++)
    {
        sx1[i]=alpha*x[i-1]+(1-alpha)*sx1[i-1];
    }
    if (smooth==1)return true;
    for(i=1; i<N; i++)
    {
        sx2[i]=alpha*sx1[i-1]+(1-alpha)*sx2[i-1];
    }
    a=2*sx1[N-1]-sx2[N-1];
    b=alpha/(1-alpha)*(sx1[N-1]-sx2[N-1]);
    para[0]=a;
    para[1]=b;
    if (smooth==2)return true;
    for(i=1; i<N; i++)
    {
        sx3[i]=alpha*sx2[i-1]+(1-alpha)*sx3[i-1];
    }
    beta=alpha/(2*(1-alpha)*(1-alpha));
    a=3*sx1[N-1]-3*sx2[N-1]+sx3[N-1];
    b=beta*((6-5*alpha)*sx1[N-1]-2*(5-4*alpha)*sx2[N-1]+(4-3*alpha)*sx3[N-1]);
    c=beta*alpha*(sx1[N-1]-2*sx2[N-1]+sx3[N-1]);
    para[0]=a;
    para[1]=b;
    para[2]=c;

    return true;
}
int main()
{
    double x[20] = {1,5,3,4,5,600,7,8,9,0,1,2,3,4,5,6,7,8,9,0};
    double para[3];
    double s1[20],s2[20],s3[20];

    int n = 10;

    ExSmooth(x,n,3,0.5,s1,s2,s3,para);



    for(int i=0 ; i<n ; i++)
        printf("%.2f ",x[i]);
    printf("\n");

    for(int i=0 ; i<n ; i++)
        printf("%.2f ",s1[i]);
    printf("\n");

    for(int i=0 ; i<n ; i++)
        printf("%.2f ",s2[i]);
    printf("\n");

    for(int i=0 ; i<n ; i++)
        printf("%.2f ",s3[i]);
    printf("\n");

    cout << "Hello world!" << endl;
    return 0;
}
