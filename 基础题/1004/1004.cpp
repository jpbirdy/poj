#include <stdio.h>

int main()
{
	int i;
	double a;
	double sum = 0;
	for(i=0;i<12;i++)
	{
		scanf("%lf",&a);
		sum+=a;
	}

	sum = (int)(sum*100/12 + 0.5)/100.0;//��������
	printf("$%.2f\n",sum);	//�����lf����WA�����İɡ�����
	return 0;
}
