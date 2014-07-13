#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

struct point
{
    int x;int y;
};

vector<point> vh;
vector<point> vc;

int minh,minc;
int min_dis;

int main()
{
    int n,m;
    //freopen("input.txt","r",stdin);

    while(scanf("%d%d",&n,&m)==2 && n!=0 && m!=0)
    {
        vc.clear();
        vh.clear();
        min_dis = 9999999;

        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<m ; j++)
            {
                point p;
                p.x = i;
                p.y = j;
                char c;
                scanf("%c",&c);
                while(c=='\n'||c==' ') scanf("%c",&c);
                if(c=='C') vc.push_back(p);
                else if(c=='H') vh.push_back(p);
            }

        for(int i=0 ; i<vc.size() ; i++)
            for(int j=0 ; j<vh.size() ; j++)
        {
            int dis = abs(vc[i].x - vh[j].x) + abs(vc[i].y-vh[j].y);
            if(dis<min_dis)
            {
                minh = j;
                minc = i;
                min_dis = dis;
            }
            else if(dis==min_dis)
            {
                if(vh[j].x<vh[minh].x || (vh[j].x==vh[minh].x && vh[j].y<vh[minh].y) )
                {
                    minh = j;
                    minc = i;
                    min_dis = dis;
                }
                else if((vh[j].x==vh[minh].x && vh[j].y==vh[minh].y))
                {
                    if(vc[i].x<vc[minc].x || (vc[i].x==vc[minc].x && vc[i].y<vc[minc].y) )
                    {
                        minh = j;
                        minc = i;
                        min_dis = dis;
                    }
                }
            }
        }
        printf("%d %d %d %d\n",vh[minh].x,vh[minh].y,vc[minc].x,vc[minc].y);

    }
    return 0;
}
