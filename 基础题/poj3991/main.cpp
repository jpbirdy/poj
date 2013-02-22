/**
输入一串{}串，求至少需要添加，或修改{}可以使所有的{}被匹配
用一个栈，先配对所有的{}，剩下的{}就是未配对的，如果未配对的{}个数为偶数，将一半修改为正确的即可
如果为奇数，则多添加一个
*/

#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
const int MAX_LEN = 2000;
char str[MAX_LEN+5];
int main()
{
	int cases = 0;
	while (1)
	{
		scanf("%s",str);
		if (str[0] == '-')
            break;
		stack<char> s;
		int p = 0;
		int len = strlen(str);
		for (int i=0;i<len;i++)
		{
			if (str[i] == '{')
			{
				s.push(str[i]);
			}
			else
			{
				if (!s.empty())
				{
					s.pop();
				}
				else p++;
			}
		}
		int q = s.size();
		if (p % 2 == 0)
			printf("%d. %d\n",++cases,(p+q)/2);
		else
			printf("%d. %d\n",++cases,(p+q)/2 + 1);
	}
	return 0;
}
