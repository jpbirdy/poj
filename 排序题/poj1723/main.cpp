#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n,i;
	int a[10000],b[10000];
	int sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d",&a[i],&b[i]);
	sort(a,a+n);
	sort(b,b+n);
	for(i=0;i<n;i++)
		a[i]=a[i]-i;
	sort(a,a+n);
	for(i=0;i<n/2;i++)
		sum+=b[n-1-i]-b[i]+a[n-1-i]-a[i];
	printf("%d\n",sum);
	return 0;
}
