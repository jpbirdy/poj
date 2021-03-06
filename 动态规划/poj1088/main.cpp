/**

Michael喜欢滑雪百这并不奇怪， 因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。
Michael想知道载一个区域中最长底滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子 
 1  2  3  4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为24-17-16-1。当然25-24-23-...-3-2-1更长。事实上，这是最长的一条。

经典DP
排序+DP
为什么用sort就Runtime ERROR呢？？
qsort就不出错
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

struct Snode
{
    int x,y;
    int data;
};




int cmp(void const *a, void const *b)
{
    Snode *aa = (Snode *)a;
    Snode *bb = (Snode *)b;
    return (bb->data - aa->data);

}



int main()
{
    Snode a[10010];
    int g[100][100];
    int ski[100][100];
    int r,c;
    int i,j;
    int k=0;
    int x,y;

    scanf("%d%d",&r,&c);
    for(i=0 ; i<r ; i++)
        for(j=0 ; j<c ; j++)
        {
            scanf("%d",&g[i][j]);
            a[k].x = i;
            a[k].y = j;
            a[k].data = g[i][j];
            k++;
        }
    qsort(a,k,sizeof(Snode),cmp);
    memset(ski,0,sizeof(ski));
    for(i=0 ; i<k ; i++)
    {
        x = a[i].x ;
        y = a[i].y ;
        if(x>0 && g[x-1][y] > g[x][y] && (ski[x-1][y]+1)>ski[x][y])
            ski[x][y] = ski[x-1][y]+1;
        if(x<(r-1) && g[x+1][y] > g[x][y] && (ski[x+1][y]+1)>ski[x][y])
            ski[x][y] = ski[x+1][y]+1;
        if(y>0 && g[x][y-1] > g[x][y] && (ski[x][y-1]+1)>ski[x][y])
            ski[x][y] = ski[x][y-1]+1;
        if(y<(c-1) && g[x][y+1] > g[x][y] && (ski[x][y+1]+1)>ski[x][y])
            ski[x][y] = ski[x][y+1]+1;
        if(ski[x][y] == 0) ski[x][y] = 1;

    }

    int max_res = 0;
    for(i=0 ; i<r ; i++)
        for(j=0 ; j<c ; j++)
            if(ski[i][j]>max_res) max_res = ski[i][j];
    printf("%d\n",max_res);

    return 0;
}
