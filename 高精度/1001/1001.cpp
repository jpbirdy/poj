#include <stdio.h>
#include <string.h>

//高精度计算
//高精度*低精度，c为输入，t为输出，m为低精度乘数
void mult(char c[],char t[],int m)
{
    int i,l,k,flag,add=0;
    char s[1000];
    l=strlen(c);
    for (i=0;i<l;i++)
        s[l-i-1]=c[i]-'0'; 
    for (i=0;i<l;i++)
    {
		k=s[i]*m+add;
		if (k>=10) {s[i]=k%10;add=k/10;flag=1;} else {s[i]=k;flag=0;add=0;}
	}
    if (flag) 
	{
		l = i;
		while(add)
		{
			s[l++]=add%10;
			add/=10;
		}
	}
	else l=i;

    for (i=0;i<l;i++)
        t[l-1-i]=s[i]+'0';
    t[l]='\0';
}

int main()
{
	char out[1000];
	int m = 0;
	char in[10];
	int i,num;
	
	while(gets(in)>0)
	{
		strcpy(out,"1");
		num = 0;
		int dot_num = -1;
		for(i=0;i<6;i++)
			if(in[i] != '.')
			{
				num = num*10 + in[i] - '0';
			}
			else
			{
				dot_num = i;
			}
		sscanf(in+6,"%d",&m);
		if(dot_num>=0)
		{
			dot_num = 5 - dot_num;
			int k = dot_num;
			for(i = 0 ; i<k ; i++)
				if(num%10 == 0)
				{
					num/=10;
					dot_num--;
				}
				else break;

			dot_num = dot_num * m;
		}

		for(i = 0 ; i<m ; i++)
			mult(out,out,num);

		int len = strlen(out);
		if(len < dot_num)
		{
			putchar('.');
			for(i=0;i<(dot_num-len);i++)
				putchar('0');
		}
		for(i = 0 ; i<len;i++)
		{
			if(i!=(len - dot_num)) putchar(out[i]);
			else 
			{
				putchar('.');
				putchar(out[i]);
			}
		}
		putchar('\n');
		
	}

	

	return 0;
}
