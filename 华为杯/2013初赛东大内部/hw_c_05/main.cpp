#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

map<int ,int> mapint;
map<int ,int>::iterator map_it;

int main()
{
    //freopen("input.txt","r",stdin);
    int n,m;
    int x;
    while(scanf("%d%d",&n,&m)==2)
    {
        mapint.clear();
        for(int i=0 ; i<n ; i++)
        {
            scanf("%d",&x);
            map_it = mapint.find(x);
            if(map_it==mapint.end())
                mapint.insert(pair<int,int>(x,i+1));
        }
        for(int i=0 ; i<m ; i++)
        {
            scanf("%d",&x);
            printf("%d\n",mapint[x]);
        }
    }
    return 0;
}
