/**
判断一个字符串是否是回文，是否对称，是否对称又回文
http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=342

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

const char miror_character[26] = {'A',' ',' ',' ','3',
                                  ' ',' ','H','I','L',' ','J','M',' ',
                                  'O',' ',' ',' ','2','T','U','V','W','X','Y','5'
                                };
const char miror_digit[10] = {' ','1','S','E',' ','Z',' ',' ','8',' '};


bool check_palindrome(string str)
{
    int len = SZ(str);
    int i;
    for(i=0 ; i<len/2 ; i++)
    {
        if(str[i]!=str[len-1-i]) break;
    }
    if(i<len/2) return false;
    else return true;
}

bool check_miror(string str)
{
    int len = SZ(str);
    int i;
    for(i=0 ; i<len/2 ; i++)
    {
        if((str[i]=='0' || str[i]=='O') && (str[len-1-i]=='0' || str[len-1-i]=='O'))
            continue;
        else if(isdigit(str[i]))
        {
            if(str[len-1-i] == miror_digit[str[i]-'0'])
                continue;
            else
                break;
        }
        else if(isalpha(str[i]))
        {
            if(str[len-1-i] == miror_character[str[i]-'A'])
                continue;
            else
                break;
        }
    }

    if(len % 2 ==0)
    {
        if(i<len/2) return false;
        else return true;
    }
    else
    {
        if(i<len/2) return false;
        if(isdigit(str[i]) && str[i]==miror_digit[str[i]-'0']) return true;
        if(isalpha(str[i]) && str[i]==miror_character[str[i]-'A']) return true;

        return false;
    }


}

int main()
{
    string str;
    while(cin>>str)
    {
        bool flag1 = check_palindrome(str);
        bool flag2 = check_miror(str);
        if(flag1 && flag2)
            cout << str << " -- is a mirrored palindrome." << endl << endl;
        else if(flag1)
            cout << str << " -- is a regular palindrome." << endl << endl;
        else if(flag2)
            cout << str << " -- is a mirrored string." << endl << endl;
        else cout << str << " -- is not a palindrome." << endl << endl;
    }
    return 0;
}
