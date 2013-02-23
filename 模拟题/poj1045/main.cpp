/**
ģ����
��ʽ�Ƶ���
V2=I.R=C.R.d/dt(Vs*cos(Wt)-Vr*cos(Wt+B))=Vrcos(wt+B)

C.R.W.(Vr.sin(wt+b)-Vs.sin(wt))=Vr*cos(wt+b)

��t=0����ã�   tan(b)=1/(C.R.W)------------- (1)
��wt+b=0����ã�Vr=C.R.W.Vs*sin(b)------------(2)
                sinb=sqrt(tanb^2/(1+tanb^2))---(3)

              ��a=C.R.W
��(1),(2),(3)�ã�   Vr=a.Vs/sqrt(1+a^2)).
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
