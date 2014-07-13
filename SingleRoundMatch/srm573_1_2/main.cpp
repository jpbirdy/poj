#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

class TeamContestEasy {
public:
	int worstRank(vector <int>);
};

int min(int a,int b,int c)
{
    if(a<=b && a<=c) return a;
    else if(b<=c) return b;
    else return c;
}

int cmp( const int &a, const int &b )
{
    if( a > b )
       return 1;
    else
       return 0;
}

int TeamContestEasy::worstRank(vector<int> strength)
{
    int my_ability = strength[0] + strength[1] + strength[2] - min(strength[0], strength[1] , strength[2] );
    int num = 1;
    int groups = strength.size() / 3;

    sort(strength.begin()+3,strength.end(),cmp);
    int len = strength.size();
    bool b[50];
    memset(b,0,sizeof(b));
    bool flag = true;

    while(flag && num<groups)
    {
        int i , j , k;
        //当前最大
        for(i=3 ; i<len ; i++)
            if(!b[i]) break;

        //当前最小
        for(j=len-1 ; j>=3 ; j--)
            if(!b[j]) break;

        for(k=j-1 ; k>=3 ; k--)
            if(!b[k] && (strength[i] + strength[k])>my_ability) break;

        if(k>=3 && k!=i)
        {
            num++;
            b[i] = b[j] = b[k] = true;
        }
        else
            flag = false;

    }

/*
    for(int i=0 ; i<strength.size() ; i++)
        printf("%d ",strength[i]);
*/
    return num;
}

double test6()
{
	int t0[] = {3,3,1,5,4,3,2,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	TeamContestEasy * obj = new TeamContestEasy();
	clock_t start = clock();
	int my_answer = obj->worstRank(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}


int main() {
	int time;
	bool errors = false;

	time = test6();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
