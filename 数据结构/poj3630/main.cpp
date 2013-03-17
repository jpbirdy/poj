
/**
字典树TRIE TREE
输入必须要排序，否则就要特殊处理（可能代价上特殊处理小。但是复杂点）

给定很多字符串，计算是否有某两个字符串，一个是另一个的前缀

*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int(i)=(n)-1;(i)>=0;(i)--)
#define SZ(c) ((int)(c).size())
#define ITER(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FIND(x,c) ((c).find((x))!=(c).end())


//字典树 10个数字
const int MAX_NUM = 10;

struct trie_node
{
    bool complete;
    char ch;
    trie_node* chlid[MAX_NUM];
};

trie_node * root;

trie_node node_array[100010];
int node_index = 0;



trie_node * create_new_node(char ch)
{
    //trie_node * node = new trie_node;
    trie_node * node = &node_array[node_index];
    node_index++;

    node->ch = ch;
    node->complete = false;
    for(int i=0 ; i<MAX_NUM ; i++)
        node->chlid[i] = NULL;
    return node;
}

//若修改为0-9或小写字母 ，修改这里即可
int char2index(char ch)
{
    return ch - '0';
}


bool insert(const char * str, int len)
{
    trie_node * pt = root;
    int i;
    for(i=0 ; i<len ; i++)
    {
        if(pt->chlid[char2index(str[i])]==NULL)
            pt->chlid[char2index(str[i])] = create_new_node(str[i]);
        pt = pt->chlid[char2index(str[i])];

        if(pt->complete) return false;

    }
    pt->complete = true;
    return true;
}

bool cmp(char *x,char *y)
{
	return strcmp(x,y)<0;
}

int main()
{
    int t;
    int n;
    char **d=new char*[10000];
	for(int i=0; i<10000; ++i)
		d[i]=new char[10];


    scanf("%d",&t);
    while(t--)
    {
        bool flag = true;
        node_index = 0;
        root = create_new_node(' ');
        scanf("%d",&n);
        for(int i=0 ; i<n ; i++)
        {
            scanf("%s",d[i]);
        }
        sort(d,d+n,cmp);

        for(int i=0 ; i<n ; i++)
        {
            if(!insert(d[i],strlen(d[i])))
            {
                flag = false;
                break;
            }
        }



        if(flag)
            puts("YES");
        else puts("NO");
    }


    delete [] d;
    return 0;
}
