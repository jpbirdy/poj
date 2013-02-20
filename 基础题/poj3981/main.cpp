#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <string>
using namespace std;

const int N = 1010;

char str[N];

int main()
{
	char aim[]="you",tmp[]="we";
	char *p,*q=str;
	while(gets(str))
	{
		p=strstr(q,aim);
		while(p)
		{
			*p='\0';
			printf("%s",q);
			printf("%s",tmp);
			q=p+3;
			p=strstr(q,aim);
		}
		printf("%s\n",q);
		q=str;
	}
	return 0;
}
