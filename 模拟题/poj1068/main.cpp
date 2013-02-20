//给定一个P序列，求W序列
//题目给出一个合法的()序列
//P=P1P2...PN，Pi表示第i个)前面(的个数。
//W=W1W2...WN，Wi表示第i个)前与之匹配的(所经过的(的个数
//

/*
Sample Input
2
6
4 5 6 6 6 6
9
4 6 6 6 6 8 9 9 9
Sample Output

1 1 1 4 5 6
1 1 2 4 5 1 1 3 9

Hint
S		(((()()())))

P-sequence	    4 5 6 6 6 6
W-sequence	    1 1 1 4 5 6


*/
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    int t,n;
    string str;

    int pair[100];

    int p[25];
    scanf("%d",&t);
    while(t--)
    {
        str = "";
        scanf("%d",&n);
        int i,j;
        for(i=0 ; i<n; i++)
            scanf("%d",p+i);
        j = 0;
        for(i=0 ; i<n; i++)
        {
            for(; j<p[i]; j++)
                str+="(";
            str+=")";
        }
        //cout << str << endl;
        j = 0;
        int len = str.size();
        for(i=0 ; i<len; i++)
        {
            if(str[i]=='(') pair[j++]=i;
            else
            {
                printf("%d",(i-pair[j-1]+1)/2);
                j--;
                if(i<(len-1)) printf(" ");
            }
        }
        printf("\n");

    }
    return 0;
}
