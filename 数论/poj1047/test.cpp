#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	char number[62];
	while ( scanf("%s", number) != EOF )
	{
		int length = strlen(number);
		bool ifOk = true;
		for ( int i = 2 ; i <= length ; i ++ )
		{
			char outCh[62];
			int addNum = 0;
			for ( int j = length - 1 ; j >= 0 ; j -- )
			{
				int temp = i * (number[j]-'0') + addNum;
				addNum = temp/10;
				outCh[j] = char(temp % 10+'0');
			}
			if ( addNum/10 > 0 )
			{
				ifOk = false;
				break;
			}
			bool ifCircle = false;
			for ( int j = 0 ; j < length ; j ++ )
			{
				if ( outCh[j] == number[0] )
				{
					ifCircle = true;
					for ( int t = j ; t < j + length ; t ++ )
					{
						int index = t % length;
						if ( outCh[index] != number[t-j] )
						{
							ifCircle = false;
							break;
						}
					}
				}
				if ( ifCircle )
					break;
			}
			if ( !ifCircle )
			{
				ifOk = false;
				break;
			}
		}
		if ( ifOk )
			printf("%s is cyclic\n", number);
		else
			printf("%s is not cyclic\n", number);
	}
}
