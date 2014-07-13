#include <iostream>
#include <fstream>

using namespace std;

const int MAX = 100000;
const int M = 1000000007;
long long S[MAX+1] = {0};

long long P(int n)
{
    if (n < 0)
        return 0;
    if (S[n] != 0)
        return S[n];
    long long res = 0;
    for (int k=1; k<=n; ++k)
    {
        if (k%2 == 0)
        {
            res -= P(n-k*(3*k-1)/2);
            res %= M;
            res -= P(n-k*(3*k+1)/2);
            res %= M;
        }
        else
        {
            res += P(n-k*(3*k-1)/2);
            res %= M;
            res += P(n-k*(3*k+1)/2);
            res %= M;
        }
        if(res<0) res+=M;
        if ((n-k*(3*k-1)/2) < 0)
        {
            break;
        }
    }
    S[n] = res;
    return res;
}

int main()
{
    //cout << M << endl;
    S[0] = 1;
    S[1] = 1;
    S[2] = 2;
    S[3] = 3;
    S[4] = 5;
    S[5] = 7;
    //freopen("1.txt", "r", stdin);
    for(int i=0 ; i<100000 ; i++)
        P(i+1);
    int T;

    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << S[n] << endl;
    }


    return 0;
}
