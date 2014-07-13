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
#include <queue>

using namespace std;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)
#define RREP(i,n) for(int(i)=(n)-1;(i)>=0;(i)--)
#define SZ(c) ((int)(c).size())
#define ITER(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FIND(x,c) ((c).find((x))!=(c).end())


class TheNumberGameDiv2
{
public:
	int minimumMoves(int, int);
};

int reverse_num(int n)
{
    int t=1;
    while(t*10<n) t*=10;
    int ret = 0;
    while(t>0)
    {
        ret =  ret*10 + n%10;
        t = t/10;
        n = n/10;
    }
    return ret;
}


int TheNumberGameDiv2::minimumMoves(int A, int B)
{
    queue<int> q;
    queue<int> step;
    map<int,bool> m;

    q.push(A);
    step.push(0);
    m.insert(pair<int,bool>(A,true));

    map<int ,bool >::iterator l_it;;

    int ret = -1;
    while(!q.empty())
    {
        int num = q.front();
        int s = step.front();
        q.pop();
        step.pop();
        int r = reverse_num(num);
        l_it=m.find(r);
        if(l_it==m.end())
        {
            if(r==B){ret = s+1;break;}
            q.push(r);
            step.push(s+1);
            m.insert(pair<int,bool>(r,true));
        }
        r = num/10;
        l_it=m.find(r);
        if(l_it==m.end())
        {
            if(r==B){ret = s+1;break;}
            q.push(r);
            step.push(s+1);
            m.insert(pair<int,bool>(r,true));
        }
    }

    return ret;
}
double test0() {
	int p0 = 25;
	int p1 = 5;
	TheNumberGameDiv2 * obj = new TheNumberGameDiv2();
	clock_t start = clock();
	int my_answer = obj->minimumMoves(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 5162;
	int p1 = 16;
	TheNumberGameDiv2 * obj = new TheNumberGameDiv2();
	clock_t start = clock();
	int my_answer = obj->minimumMoves(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 334;
	int p1 = 12;
	TheNumberGameDiv2 * obj = new TheNumberGameDiv2();
	clock_t start = clock();
	int my_answer = obj->minimumMoves(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 218181918;
	int p1 = 9181;
	TheNumberGameDiv2 * obj = new TheNumberGameDiv2();
	clock_t start = clock();
	int my_answer = obj->minimumMoves(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 9798147;
	int p1 = 79817;
	TheNumberGameDiv2 * obj = new TheNumberGameDiv2();
	clock_t start = clock();
	int my_answer = obj->minimumMoves(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
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

	time = test0();
	if (time < 0)
		errors = true;

	time = test1();
	if (time < 0)
		errors = true;

	time = test2();
	if (time < 0)
		errors = true;

	time = test3();
	if (time < 0)
		errors = true;

	time = test4();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
