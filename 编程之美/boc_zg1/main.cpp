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

map<string ,int> word_map;
vector<string> words;
int word_next[200];
int word_num;

char line[110];


int find_word(string word)
{
    map<string ,int>::iterator map_it;
    map_it = word_map.find(word);
    if(map_it!=word_map.end())
        return word_map[word];
    else
    {
        word_map.insert(pair<string,int>( word, word_num++));
        words.push_back(word);
        word_next[word_num-1] = word_num-1;
        return word_num-1;
    }
}


int find_word_only(string word)
{
    map<string ,int>::iterator map_it;
    map_it = word_map.find(word);
    if(map_it!=word_map.end())
        return word_map[word];
    else
        return -1;
}

string round_word(string word,int n)
{
    int num = find_word_only(word);
    if(num==-1)
        return word;
    else
    {
        REP(i,n)
        {
            if(word_next[num] == num) return words[num];
            else num = word_next[num];
        }

    }
    return words[num];
}

int main()
{
    int cases = 1;
    string str1,str2;
    int num1,num2;
    int t,m,n;



    scanf("%d",&t);
    while(t--)
    {
        memset(word_next,0,sizeof(word_next));
        word_map.clear();
        words.clear();
        word_num = 0;
        scanf("%d%d",&n,&m);
        REP(i,m)
        {
            cin>>str1>>str2;
            num1 = find_word(str1);
            num2 = find_word(str2);
            word_next[num1] = num2;
        }
        gets(line);
        gets(line);
        int len = strlen(line);
        string temp="";
        cout<<"Case #" << cases++ << ": ";
        REP(i,len)
        {
            char ch = line[i];
            if(ch!=' ')
                temp+=ch;
            else
            {
                cout<< round_word(temp,n-1) << ' ';
                temp = "";
            }
        }
        cout<< round_word(temp,n-1) << endl;
    }
    return 0;
}
