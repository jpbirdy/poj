//题目大意：
//先给出16个颜色
//再给出一个颜色，要求求出与上面16个颜色距离最接近的一个。
//d=sqrt(dR^2+dG^2+dB^2);

#include <cstdio>
using namespace std;



struct Color
{
    int R,G,B;
};

int main()
{
    int i;
    Color c[16];
    for(i = 0 ; i<16 ; i++)
        scanf("%d%d%d",&c[i].R,&c[i].G,&c[i].B);
    Color t;

    while(scanf("%d%d%d",&t.R,&t.G,&t.B) && (t.R>=0 && t.G>=0 && t.B>=0))
    {
        int min=999999,min_i=0;
        for(i=0 ; i<16 ; i++)
        {
            int d = (t.R - c[i].R)*(t.R - c[i].R) + (t.G - c[i].G)*(t.G - c[i].G) + (t.B - c[i].B)*(t.B - c[i].B);
            if(d<min)
            {
                min = d;
                min_i = i;
            }
        }
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n",t.R,t.G,t.B,c[min_i].R,c[min_i].G,c[min_i].B);
    }

    return 0;
}
