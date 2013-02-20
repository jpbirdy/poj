#include <cstdio>
#include <algorithm>
using namespace std;

char s[31];
int num[25] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9};

//此处是精髓，每次的电话号码其实是生成了一个7位数字，排序即可。
int Hash()
{
    int sum=0;
    for(int i=0,k=0;k<7;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            sum*=10;k++;
            sum+=(s[i]-'0');
        }
        else if(s[i]>='A'&&s[i]<'Z')
        {
            sum*=10;k++;
            sum+=num[s[i]-'A'];
        }
    }
    return sum;
}

int main()
{

    int n;
    int data[100010];
	scanf("%d",&n);
	getchar();
    for(int tmp=0;tmp<n;tmp++)
    {
        gets(s);
        data[tmp]=Hash();
    }
    sort(data,data+n);
    bool p=false;n--;
    for(int i=0,num=1;i<n;i+=num=1)
    {
        while(data[i]==data[i+1])
        {
            num++;
            i++;
        }
        if(num>1)
        {
            printf("%03d-%04d %d\n",data[i]/10000,data[i]%10000,num);
            p=true;
        }
    }
    if(!p)printf("No duplicates.\n");
    return 0;
}
