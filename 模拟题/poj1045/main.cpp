/**
模拟题
公式推导：
V2=I.R=C.R.d/dt(Vs*cos(Wt)-Vr*cos(Wt+B))=Vrcos(wt+B)

C.R.W.(Vr.sin(wt+b)-Vs.sin(wt))=Vr*cos(wt+b)

令t=0化简得：   tan(b)=1/(C.R.W)------------- (1)
令wt+b=0化简得：Vr=C.R.W.Vs*sin(b)------------(2)
                sinb=sqrt(tanb^2/(1+tanb^2))---(3)

              设a=C.R.W
由(1),(2),(3)得：   Vr=a.Vs/sqrt(1+a^2)).
*/


#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    double Vs, R, C, w, Vr;
    int n;

    scanf("%lf%lf%lf%d",&Vs,&R,&C,&n);

    while (n--)
    {
        scanf("%lf",&w);
        Vr = Vs * R * C * w / sqrt(1 + C * w * w);
        printf("%.3f\n",Vr);
    }
    return 0;
}
