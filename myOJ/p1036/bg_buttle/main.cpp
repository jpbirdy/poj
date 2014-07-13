#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
class fr
{
public:
	int x,y,v;
    bool operator <(const fr &t) const
    {
        return v<t.v;
    }
    bool operator >(const fr &t) const
    {
        return v>t.v;
    }
};

priority_queue<fr,vector<fr> ,greater<fr> > q;

int a[100000],b[100000];
int n,m;
int k;
int key;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	while(scanf("%d%d%d",&n,&m,&k)!=-1)
	{
		while(q.size())
			q.pop();
		int i;
		for(i=1;i<=n;i++)
			scanf("%d",a+i);

		sort(a+1,a+1+n);

		for(i=1;i<=m;i++)
			scanf("%d",b+i);

        sort(b+1,b+m+1);
		fr tep,tt;
		if(k == 1)
		{
			cout<<a[1]+b[1]<<endl;
			continue;
		}
		int gap=k-1;
		tep.x=2;
		tep.y=1;
		tep.v=a[2]+b[1];
		q.push(tep);
		swap(tep.x,tep.y);
		tep.v=a[1]+b[2];
		q.push(tep);
		while(gap--)
		{
			tep=q.top();
            key=tep.v;
			q.pop();
			tt=tep;
			tt.y++;
			if(tt.y<=m)
			{
				tt.v=a[tt.x]+b[tt.y];
				q.push(tt);
			}
			if(tep.y==1)
			{
				tt.y=1;
			    tt.x=tep.x+1;
				if(tt.x<=n)
				{
                    	tt.v=a[tt.x]+b[tt.y];
				     q.push(tt);
				}
			}

		}
		cout<<key<<endl;
	}
	return 0;
}

